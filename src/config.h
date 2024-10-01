#pragma once

#include <stdint.h>
#include <stdio.h>

#include <jpeglib.h>
#include <fftw.h>
#include <rfftw.h>
#include "util.h"


#define u_char unsigned char

#define int8_t int8_t
#define int16_t int16_t
#define int32_t int32_t



#define u_int8_t uint8_t
#define u_int16_t uint16_t
#define u_int32_t uint32_t
#define u_int64_t uint64_t
#define u_int uint32_t

#ifdef _MSC_VER 
//not #if defined(_WIN32) || defined(_WIN64) because we have strncasecmp in mingw
#define strncasecmp _strnicmp
#define strcasecmp _stricmp
#endif