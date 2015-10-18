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
 * \file allocator.c
 * \date Oct 17, 2015
 */

/* LANG includes */
#include <stdlib.h>

/* MOD includes */
#include <cut/common/allocator.h>
#include <cut/common/likely.h>

#define PRIVATE static

PRIVATE void* cutAlloc(void* state, size_t s)
{
    return malloc(s);
}

PRIVATE void* cutZalloc(void* state, size_t s)
{
    switch (s % 8) {
        case 0:  return calloc(s/8, 8);
        case 4:  return calloc(s/4, 4);
        case 2:  return calloc(s/2, 2);
        default: return calloc(s,   1);
    }
}

PRIVATE void* cutRealloc(void* state, void* p, size_t s)
{
    return realloc(p, s);
}

PRIVATE void cutDealloc(void* state, void* p)
{
    if (p) { free(p); }
}

/***************************************************/
/* public APIs                                     */
/***************************************************/

PRIVATE const cutAllocator DEFAULT_ALLOC = {
        cutAlloc,
        cutDealloc,
        cutRealloc,
        cutZalloc,
        NULL
    };

PRIVATE cutAllocator  SET_ALLOC;
PRIVATE cutAllocator* ALLOC_PTR = NULL;

const cutAllocator* cutDefaultAllocator()
{
    if (CUT_UNLIKELY(ALLOC_PTR == NULL)) {
        ALLOC_PTR = &SET_ALLOC;
        SET_ALLOC = DEFAULT_ALLOC;
    }
    return ALLOC_PTR;
}

void cutSetDefaultAllocator(const cutAllocator* alloc)
{
    if (CUT_LIKELY(alloc != NULL)) {
        SET_ALLOC = *alloc;
    }
}
