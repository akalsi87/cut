/**
 * \file tVersion.c
 * \date Oct 17, 2015
 */

/* LANG includes */
#include <string.h>

/* TEST includes */
#include "unittest.h"

/* MOD includes */
#include <cut/common/version.h>

TEST_FUNC( version )
{
    TEST_TRUE( cutCommonMajorVersion() == 0 );
    TEST_TRUE( cutCommonMinorVersion() == 0 );
    TEST_TRUE( cutCommonPatchVersion() == 1 );
    TEST_TRUE( strcmp(cutCommonVersionString(), "0.0.1") == 0 );
}

void SetupTests(void)
{
    REG_TEST( version );
}
