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
    cutAllocator a = cutDefaultAllocator();
    TEST_TRUE( a.alloc );
    TEST_TRUE( a.dealloc );
    TEST_TRUE( a.realloc );
    TEST_TRUE( a.zalloc );
    TEST_TRUE( a._state == NULL );
}

void SetupTests(void)
{
    REG_TEST( defaultAlloc );
}
