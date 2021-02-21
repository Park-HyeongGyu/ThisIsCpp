#include "MyStringEx.h"
#include <cstring>

CMyStringEx::CMyStringEx()
{
}

CMyStringEx::~CMyStringEx()
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