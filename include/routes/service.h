#ifndef _BRAWL_ROUTES_SERVICE_H_
#define _BRAWL_ROUTES_SERVICE_H_

struct _HttpReceive;
struct _HttpRequest;

// GET /api/brawl
extern void brawl_handler (
	const struct _HttpReceive *http_receive,
	const struct _HttpRequest *request
);

// GET /api/brawl/version
extern void brawl_version_handler (
	const struct _HttpReceive *http_receive,
	const struct _HttpRequest *request
);

// GET *
extern void brawl_catch_all_handler (
	const struct _HttpReceive *http_receive,
	const struct _HttpRequest *request
);

#endif