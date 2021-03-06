#pragma once
#ifndef MYASSERT_H
#define MYASSERT_H

#include <string>
#ifdef __USE_GNU
#define __func_get __PRETTY_FUNCTION__
#else
#define __func_get __FUNCTION__
#endif

#define assert(cond, msg) \
    if (!(cond))          \
    assert_fail(__FILE__, __func_get, __LINE__, this, msg)

#define assertChar(ch) assert(iter.next() == L##ch, L"excepted '" ch "'");

class parserCore;
void assert_fail(const char *, const char *, int, parserCore *, const wchar_t *);

#endif