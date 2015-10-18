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

int cutMajorVersion()
{
    return CUT_MAJ;
}

int cutMinorVersion()
{
    return CUT_MIN;
}

int cutPatchVersion()
{
    return CUT_PAT;
}

const char* cutVersionString()
{
    return tokencat(CUT_MAJ, CUT_MIN, CUT_PAT);
}
