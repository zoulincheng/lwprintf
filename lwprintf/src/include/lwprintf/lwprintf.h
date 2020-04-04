/**
 * \file            lwprintf.h
 * \brief           Lightweight stdio manager
 */

/*
 * Copyright (c) 2020 Tilen MAJERLE
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of LwPRINTF - Lightweight stdio manager library.
 *
 * Author:          Tilen MAJERLE <tilen@majerle.eu>
 * Version:         $_version_$
 */
#ifndef LWPRINTF_HDR_H
#define LWPRINTF_HDR_H

#include <string.h>
#include <stdint.h>
#include <limits.h>
#include "lwprintf_config.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \defgroup        LWPRINTF Lightweight stdio manager
 * \brief           Lightweight stdio manager
 * \{
 */

#define LWPRINTF_UNUSED(x)          ((void)(x))

struct lwprintf;

typedef int (*lwprintf_output_fn)(int ch, struct lwprintf* lw);

typedef struct lwprintf {
    lwprintf_output_fn out;
} lwprintf_t;

uint8_t     lwprintf_init(lwprintf_t* lw, lwprintf_output_fn out_fn);
int         lwprintf_vprintf_ex(lwprintf_t* const lw, const char* format, va_list arg);
int         lwprintf_printf_ex(lwprintf_t* const lw, const char* format, ...);
int         lwprintf_vsnprintf_ex(lwprintf_t* const lw, char* s, size_t n, const char* format, va_list arg);
int         lwprintf_snprintf_ex(lwprintf_t* const lw, char* s, size_t n, const char* format, ...);

#define     lwprintf_sprintf(lw, s, format, ...)    lwprintf_snprintf(lw, buff, SIZE_MAX, fmt, #__VA_ARGS__)

/**
 * \}
 */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* LWPRINTF_HDR_H */