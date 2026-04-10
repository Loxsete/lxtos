#pragma once
#include <stdint.h>

#define SYS_PUTCHAR   0
#define SYS_PUTS      1
#define SYS_GETCHAR   2
#define SYS_EXIT      3
#define SYS_GETS      4
#define SYS_CLEAR     5
#define SYS_READDIR   6
#define SYS_MKDIR     7
#define SYS_MKFILE    8
#define SYS_RM        9
#define SYS_READ      10
#define SYS_WRITE     11

uint64_t syscall_dispatch(uint64_t num, uint64_t a1, uint64_t a2, uint64_t a3);
