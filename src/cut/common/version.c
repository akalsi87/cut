/**
 * \file version.c
 * \date Oct 17, 2015
 */

/* MOD includes */
#include <cut/common/version.h>

#define stringify(x) \
  #x

#define tokencat(x,y,z) \
  stringify(x) "." stringify(y) "." stringify(z)

int cutCommonMajorVersion()
{
    return CUT_COMMON_MAJ;
}

int cutCommonMinorVersion()
{
    return CUT_COMMON_MIN;
}

int cutCommonPatchVersion()
{
    return CUT_COMMON_PAT;
}

const char* cutCommonVersionString()
{
    return tokencat(CUT_COMMON_MAJ, CUT_COMMON_MIN, CUT_COMMON_PAT);
}
