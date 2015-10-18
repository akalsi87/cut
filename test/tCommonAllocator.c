/**
 * \file tCommonAllocator.c
 * \date Oct 17, 2015
 */

/* LANG includes */
#include <string.h>

/* TEST includes */
#include "unittest.h"

/* MOD includes */
#include <cut/common/allocator.h>

TEST_FUNC( defaultAlloc )
{
    const cutAllocator* d = cutDefaultAllocator();
    const cutAllocator def = *d;
    TEST_TRUE( d->alloc );
    TEST_TRUE( d->dealloc );
    TEST_TRUE( d->realloc );
    TEST_TRUE( d->zalloc );
    TEST_TRUE( d->_state == NULL );

    cutAllocator alloc = { NULL, NULL, NULL, NULL, NULL };
    cutSetDefaultAllocator(&alloc);
    TEST_TRUE( d->alloc == NULL );
    TEST_TRUE( d->dealloc == NULL );
    TEST_TRUE( d->realloc == NULL );
    TEST_TRUE( d->zalloc == NULL );
    TEST_TRUE( d->_state == NULL );

    cutSetDefaultAllocator(&def);
    TEST_TRUE( d->alloc );
    TEST_TRUE( d->dealloc );
    TEST_TRUE( d->realloc );
    TEST_TRUE( d->zalloc );
    TEST_TRUE( d->_state == NULL );
}

TEST_FUNC( allocDealloc )
{
    const cutAllocator* a = cutDefaultAllocator();
    char* p = (char*)cutAllocate(a, 20);
    TEST_TRUE( p );
    p = cutReallocate(a, p, 400);
    cutDeallocate(a, p);
    p = cutZallocate(a, 20);
    {// test all zeros
        int i = 0;
        for (; i != 20; ++i) {
            TEST_TRUE( p[i] == '\0' );
        }
    }
    cutDeallocate(a, p);
}

void SetupTests(void)
{
    REG_TEST( defaultAlloc );
    REG_TEST( allocDealloc );
}
