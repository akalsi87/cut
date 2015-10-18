/**
 * \file version.h
 * \date Oct 17, 2015
 */

#ifndef CUT_COMMON_VERSION_H
#define CUT_COMMON_VERSION_H

/* MOD includes */
#include <cut/common/exportsym.h>

CUT_API
/*!
 * \return Major library version.
 */
int cutMajorVersion();

CUT_API
/*!
 * \return Minor library version.
 */
int cutMinorVersion();

CUT_API
/*!
 * \return Patch library version.
 */
int cutPatchVersion();

CUT_API
/*!
 * \return Full version string.
 */
const char* cutVersionString();

#endif/*CUT_COMMON_VERSION_H*/
