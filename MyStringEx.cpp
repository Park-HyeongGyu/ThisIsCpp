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

void CMyStringEx::OnSetString(char *pszData, int nLength)
{
    if(strcmp(pszData, "멍멍이아들") == 0)
    {
        strcpy(pszData, "*착한아들*");
    }
}