#include <cerver/http/http.h>
#include <cerver/http/request.h>
#include <cerver/http/response.h>

#include "controllers/service.h"

// GET /api/brawl
void brawl_handler (
	const HttpReceive *http_receive,
	const HttpRequest *request
) {

	(void) http_response_send (brawl_works, http_receive);

}

// GET /api/brawl/version
void brawl_version_handler (
	const HttpReceive *http_receive,
	const HttpRequest *request
) {

	(void) http_response_send (current_version, http_receive);

}

// GET *
void brawl_catch_all_handler (
	const HttpReceive *http_receive,
	const HttpRequest *request
) {

	http_response_send (catch_all, http_receive);

}
