#pragma once

#include "MyString.h"

class CMyStringEx 
: public CMyString
{
public:
    CMyStringEx();
    ~CMyStringEx();

    CMyStringEx(const char* param);
    int Find(const char * pszParam);
    int SetString(const char* pszParam);
};