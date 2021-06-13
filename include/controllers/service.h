#ifndef _BRAWL_SERVICE_H_
#define _BRAWL_SERVICE_H_

struct _HttpResponse;

extern struct _HttpResponse *brawl_works;
extern struct _HttpResponse *current_version;

extern struct _HttpResponse *catch_all;

extern unsigned int brawl_service_init (void);

extern void brawl_service_end (void);

#endif