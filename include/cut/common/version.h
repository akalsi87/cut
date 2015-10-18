/**
 * \file version.h
 * \date Oct 17, 2015
 */

#ifndef CUT_COMMON_VERSION_H
#define CUT_COMMON_VERSION_H

/* MOD includes */
#include <cut/common/exportsym.h>

CUT_COMMON_API
/*!
 * \return Major library version.
 */
int cutCommonMajorVersion();

CUT_COMMON_API
/*!
 * \return Minor library version.
 */
int cutCommonMinorVersion();

CUT_COMMON_API
/*!
 * \return Patch library version.
 */
int cutCommonPatchVersion();

CUT_COMMON_API
/*!
 * \return Full version string.
 */
const char* cutCommonVersionString();

#endif/*CUT_COMMON_VERSION_H*/
