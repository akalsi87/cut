/*
Copyright (c) 2015, Aaditya Kalsi
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * \file allocator.h
 * \date Oct 17, 2015
 */

#ifndef CUT_COMMON_ALLOCATOR_H
#define CUT_COMMON_ALLOCATOR_H

/* LANG includes */
#include <stddef.h>

/* MOD includes */
#include <cut/common/exportsym.h>

/*! alloc function   */
typedef void* (*cutAllocFcn)(size_t);

/*! dealloc function */
typedef void  (*cutDeallocFcn)(void*);

/*! realloc function */
typedef void* (*cutReallocFcn)(void*, size_t);

/*! zalloc function  */
typedef void* (*cutZallocFcn)(size_t);

/*!
 *
 */
typedef struct cutAllocTag
{
    cutAllocFcn    alloc;
    cutDeallocFcn  dealloc;
    cutReallocFcn  realloc;
    cutZallocFcn   zalloc;
    void*          _state;
} cutAllocator;

CUT_COMMON_API
/*!
 *
 */
cutAllocator cutDefaultAllocator();

CUT_COMMON_API
/*!
 *
 */
void cutSetDefaultAllocator(cutAllocator alloc);

#endif/*CUT_COMMON_ALLOCATOR_H*/
