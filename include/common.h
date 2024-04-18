/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Common header file for U-Boot
 *
 * This file still includes quite a few headers that should be included
 * individually as needed. Patches to remove things are welcome.
 *
 * (C) Copyright 2000-2009
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 */

#ifndef __COMMON_H_
#define __COMMON_H_	1

#ifndef __ASSEMBLY__		/* put C only stuff in this section */

/* crazyboy 20161205  */
#define CRZ_DEBUG
#if defined(CRZ_DEBUG)
#define CRZ_ANSI_RESET                  "\033[0m"
#define CRZ_ANSI_TEXT_BLACK             "\033[30m"
#define CRZ_ANSI_TEXT_RED               "\033[31m"
#define CRZ_ANSI_TEXT_GREEN             "\033[32m"
#define CRZ_ANSI_TEXT_YELLOW            "\033[33m"
#define CRZ_ANSI_TEXT_BLUE              "\033[34m"
#define CRZ_ANSI_TEXT_MGENTA            "\033[35m"
#define CRZ_ANSI_TEXT_CYAN              "\033[36m"
#define CRZ_ANSI_TEXT_WHITE             "\033[37m"
#define CRZ_ANSI_TEXT_RESET             "\033[39m"
#define CRZ_ANSI_BACKGROUND_BLACK       "\033[40m"
#define CRZ_ANSI_BACKGROUND_RED         "\033[41m"
#define CRZ_ANSI_BACKGROUND_GREEN       "\033[42m"
#define CRZ_ANSI_BACKGROUND_YELLOW      "\033[43m"
#define CRZ_ANSI_BACKGROUND_BLUE        "\033[44m"
#define CRZ_ANSI_BACKGROUND_PINK        "\033[45m"
#define CRZ_ANSI_BACKGROUND_DARKBLUE    "\033[46m"
#define CRZ_ANSI_BACKGROUND_WHITE       "\033[47m"
#define CRZ_ANSI_BACKGROUND_RESET       "\033[49m"
#define MANGO_DBG(fmt, ...) \
    printf(CRZ_ANSI_TEXT_GREEN "[CRZ]" CRZ_ANSI_TEXT_RESET " %s (%d) %s: " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define MANGO_ERROR(fmt, ...) \
    printf(CRZ_ANSI_TEXT_RED "[CRZ]" CRZ_ANSI_TEXT_RESET " %s (%d) %s: " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define MANGO_DBG_DEFAULT MANGO_DBG("\n");
#define MANGO_DBG_YELLOW(fmt, ...) \
	printf(CRZ_ANSI_TEXT_YELLOW "[CRZ]" CRZ_ANSI_TEXT_RESET " %s (%d) %s: " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define MANGO_DBG_BLUE(fmt, ...) \
	printf(CRZ_ANSI_TEXT_BLUE "[CRZ]" CRZ_ANSI_TEXT_RESET " %s (%d) %s: " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define MANGO_DBG_RED(fmt, ...) \
	printf(CRZ_ANSI_TEXT_RED "[CRZ]" CRZ_ANSI_TEXT_RESET " %s (%d) %s: " fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__)
#define MANGO_DBG_DEFAULT_RED MANGO_DBG_RED("\n");
#else
#define MANGO_DBG(fmt, ...)
#define MANGO_ERROR(fmt, ...)
#define MANGO_DBG_DEFAULT
#define MANGO_DBG_YELLOW(fmt, ...)
#define MANGO_DBG_BLUE(fmt, ...)
#define MANGO_DBG_RED(fmt, ...)
#define MANGO_DBG_DEFAULT_RED
#endif
#include <config.h>
#include <errno.h>
#include <time.h>
#include <linux/types.h>
#include <linux/printk.h>
#include <linux/string.h>
#include <stdarg.h>
#include <stdio.h>
#include <linux/kernel.h>
#include <asm/u-boot.h> /* boot information for Linux kernel */
#include <vsprintf.h>
#endif	/* __ASSEMBLY__ */

/* Pull in stuff for the build system */
#ifdef DO_DEPS_ONLY
# include <env_internal.h>
#endif

#endif	/* __COMMON_H_ */
