#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>
#include <signal.h>

#include <cerver/version.h>
#include <cerver/cerver.h>

#include <cerver/http/http.h>
#include <cerver/http/route.h>

#include <cerver/utils/log.h>
#include <cerver/utils/utils.h>

#include "brawl.h"
#include "version.h"

#include "routes/service.h"

static Cerver *brawl_api = NULL;

void end (int dummy) {
	
	if (brawl_api) {
		cerver_stats_print (brawl_api, false, false);
		cerver_log_msg ("\nHTTP Cerver stats:\n");
		http_cerver_all_stats_print ((HttpCerver *) brawl_api->cerver_data);
		cerver_log_line_break ();
		cerver_teardown (brawl_api);
	}

	(void) brawl_end ();

	cerver_end ();

	exit (0);

}

static void brawl_set_brawl_routes (HttpCerver *http_cerver) {

	/* register top level route */
	// GET /api/status
	HttpRoute *brawl_route = http_route_create (REQUEST_METHOD_GET, "api/status", brawl_handler);
	http_cerver_route_register (http_cerver, brawl_route);

	/* register brawl children routes */
	// GET api/status/version
	HttpRoute *brawl_version_route = http_route_create (REQUEST_METHOD_GET, "version", brawl_version_handler);
	http_route_child_add (brawl_route, brawl_version_route);

}

static void start (void) {

	brawl_api = cerver_create (
		CERVER_TYPE_WEB,
		"brawl-api",
		PORT,
		PROTOCOL_TCP,
		false,
		CERVER_CONNECTION_QUEUE
	);

	if (brawl_api) {
		/*** cerver configuration ***/
		cerver_set_receive_buffer_size (brawl_api, CERVER_RECEIVE_BUFFER_SIZE);
		cerver_set_thpool_n_threads (brawl_api, CERVER_TH_THREADS);
		cerver_set_handler_type (brawl_api, CERVER_HANDLER_TYPE_THREADS);

		/*** web cerver configuration ***/
		HttpCerver *http_cerver = (HttpCerver *) brawl_api->cerver_data;

		brawl_set_brawl_routes (http_cerver);

		// add a catch all route
		http_cerver_set_catch_all_route (http_cerver, brawl_catch_all_handler);

		if (cerver_start (brawl_api)) {
			cerver_log_error (
				"Failed to start %s!",
				brawl_api->info->name->str
			);

			cerver_delete (brawl_api);
		}
	}

	else {
		cerver_log_error ("Failed to create cerver!");

		cerver_delete (brawl_api);
	}

}

int main (int argc, char const **argv) {

	srand (time (NULL));

	// register to the quit signal
	(void) signal (SIGINT, end);
	(void) signal (SIGTERM, end);

	// to prevent SIGPIPE when writting to socket
	(void) signal (SIGPIPE, SIG_IGN);

	cerver_init ();

	cerver_version_print_full ();

	brawl_version_print_full ();

	if (!brawl_init ()) {
		start ();
	}

	else {
		cerver_log_error ("Failed to init brawl!");
	}

	(void) brawl_end ();

	cerver_end ();

	return 0;

}