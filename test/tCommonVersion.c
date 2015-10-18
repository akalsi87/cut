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
    TEST_TRUE( cutMajorVersion() == 0 );
    TEST_TRUE( cutMinorVersion() == 0 );
    TEST_TRUE( cutPatchVersion() == 1 );
    TEST_TRUE( strcmp(cutVersionString(), "0.0.1") == 0 );
}

void SetupTests(void)
{
    REG_TEST( version );
}
