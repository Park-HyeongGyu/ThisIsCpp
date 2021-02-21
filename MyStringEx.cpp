#include "MyStringEx.h"
#include <cstring>
#include <iostream>

CMyStringEx::CMyStringEx()
{
}

CMyStringEx::~CMyStringEx()
{
}

CMyStringEx::CMyStringEx(const char* pszParam) : CMyString(pszParam)
{
}

int CMyStringEx::Find(const char* pszParam)
{
    if(pszParam == nullptr || GetString() == nullptr)
    {
        return -1;
    }

    const char *pszResult = strstr(GetString(), pszParam);

    if(pszResult != nullptr)
    {
        return pszResult - GetString();
    }

    return -1;
}

int CMyStringEx::SetString(const char* pszParam)
{
    int nResult;

    if(strcmp(pszParam, "멍멍이아들") == 0)
    {
        nResult = CMyString::SetString("착한사람");
    }
    else
    {
        nResult = CMyString::SetString(pszParam);
    }

    return nResult;
}