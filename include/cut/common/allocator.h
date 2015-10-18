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
#include <cut/common/inline.h>

/*! alloc function   */
typedef void* (*cutAllocFcn)(void*, size_t);

/*! dealloc function */
typedef void  (*cutDeallocFcn)(void*, void*);

/*! realloc function */
typedef void* (*cutReallocFcn)(void*, void*, size_t);

/*! zalloc function  */
typedef void* (*cutZallocFcn)(void*, size_t);

/*!
 * Definition for an allocator.
 */
typedef struct cutAllocTag
{
    cutAllocFcn    alloc;    /*!< Allocate function callback          */
    cutDeallocFcn  dealloc;  /*!< Deallocate function callback        */
    cutReallocFcn  realloc;  /*!< Reallocate function callback        */
    cutZallocFcn   zalloc;   /*!< Zeroed allocation function callback */
    void*          _state;   /*!< Internal state of the allocator     */
} cutAllocator;

CUT_COMMON_API
/*!
 * Get the deafult allocator. This is the allocator used by this library.
 */
const cutAllocator* cutDefaultAllocator();

CUT_COMMON_API
/*!
 * Set the default allocator used by this library. This must be called before
 * any other APIs as the library state may have allocated data from a different
 * allocator.
 *
 * Allocators are copied, therefore are expected to have trivial assignment
 * work as the copy mechanism. If there is some other way to clone your allocator
 * clone outside this function, and then call this with the clone.
 *
 * The way to copy is similar to:
 * \code{.c}
 *   cutAllocator myAlloc = *alloc;
 * \endcode
 */
void cutSetDefaultAllocator(const cutAllocator* alloc);

CUT_INLINE
/*!
 * Allocate uninitialized memory.
 * \param palloc - Pointer to a valid allocator. Cannot be NULL.
 * \param s - Size in bytes to allocate.
 * \return Pointer to memory if successful or NULL if failure occurs.
 */
void* cutAllocate(const cutAllocator* palloc, size_t s)
{
    return palloc->alloc(palloc->_state, s);
}

CUT_INLINE
/*!
 * Allocate zero initialized memory.
 * \param palloc - Pointer to a valid allocator. Cannot be NULL.
 * \param s - Size in bytes to allocate.
 * \return Pointer to memory if successful or NULL if failure occurs.
 */
void* cutZallocate(const cutAllocator* palloc, size_t s)
{
    return palloc->zalloc(palloc->_state, s);
}

CUT_INLINE
/*!
 * Reallocate already allocated memory.
 * \param palloc - Pointer to a valid allocator. Cannot be NULL.
 * \param p - Pointer to attempt to reallocate.
 * \param s - Size in bytes to allocate.
 * \return Pointer to memory if successful or NULL if failure occurs.
 */
void* cutReallocate(const cutAllocator* palloc, void* p, size_t s)
{
    return palloc->realloc(palloc->_state, p, s);
}

CUT_INLINE
/*!
 * Reclaim allocated memory.
 * \param palloc - Pointer to a valid allocator. Cannot be NULL.
 * \param p - Pointer to destroy.
 */
void cutDeallocate(const cutAllocator* palloc, void* p)
{
    palloc->dealloc(palloc->_state, p);
}

#endif/*CUT_COMMON_ALLOCATOR_H*/
