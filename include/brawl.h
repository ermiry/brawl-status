#ifndef _BRAWL_H_
#define _BRAWL_H_

#include "runtime.h"

struct _HttpResponse;

extern RuntimeType RUNTIME;

extern unsigned int PORT;

extern unsigned int CERVER_RECEIVE_BUFFER_SIZE;
extern unsigned int CERVER_TH_THREADS;
extern unsigned int CERVER_CONNECTION_QUEUE;

// inits brawl main values
extern unsigned int brawl_init (void);

// ends brawl main values
extern unsigned int brawl_end (void);

#endif