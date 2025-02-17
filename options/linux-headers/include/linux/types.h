#ifndef _LINUX_TYPES_H
#define _LINUX_TYPES_H

#include <bits/types.h>

typedef __mlibc_size __kernel_size_t;

typedef __mlibc_uint8 __u8;
typedef __mlibc_uint16 __u16;
typedef __mlibc_uint32 __u32;
typedef __mlibc_uint64 __u64;

typedef __mlibc_int8 __s8;
typedef __mlibc_int16 __s16;
typedef __mlibc_int32 __s32;
typedef __mlibc_int64 __s64;

typedef __u16 __be16;
typedef __u16 __le16;
typedef __u32 __be32;
typedef __u32 __le32;
typedef __u64 __be64;
typedef __u64 __le64;

#define __aligned_u64 __u64 __attribute__((aligned(8)))

#endif // _LINUX_TYPES_H
