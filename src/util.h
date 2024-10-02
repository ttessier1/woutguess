#pragma once

#include <stddef.h>

void * checkedmalloc(size_t n);

#ifndef htonl
#define htonl(VAL) ((VAL & 0x000000FF) << 24) | \
        ((VAL & 0x0000FF00) << 8) | \
        ((VAL & 0x00FF0000) >> 8) | \
        ((VAL & 0xFF000000) >> 24) 
#endif
#if !defined(ntohl)
#define ntohl(VAL) ((VAL & 0x000000FF) << 24) | \
        ((VAL & 0x0000FF00) << 8) | \
        ((VAL & 0x00FF0000) >> 8) | \
        ((VAL & 0xFF000000) >> 24)
#endif


extern int steg_stat;

extern int steg_foil;
extern int steg_foilfail;
