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
 *
 */
int cutCommonMajorVersion();

CUT_COMMON_API
/*!
 *
 */
int cutCommonMinorVersion();

CUT_COMMON_API
/*!
 *
 */
int cutCommonPatchVersion();

CUT_COMMON_API
/*!
 *
 */
const char* cutCommonVersionString();

#endif/*CUT_COMMON_VERSION_H*/
