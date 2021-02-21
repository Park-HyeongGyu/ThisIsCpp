#include "MyStringEx.h"
#include <cstring>

int CMyStringEx::Find(const char* pszParam)
{
    const char * finded = strstr(this->GetString(), pszParam);
    int index = 0;
    while(GetString()+index != finded)
    {
        index++;
    }
    return index;
}