#include "MyString.h"
#include <cstring>

CMyString::CMyString() :m_pszData(nullptr), m_nLength(0) {}
CMyString::~CMyString() { Release(); }

int CMyString::SetString(const char* pszParam)
{
    // before allocating new string, release before information.
    Release();

    // Call function with null means that deallocating memory and allocate with null.
    if(pszParam == nullptr)
    {
        return 0;
    }

    // String with 0 length will be understanded as reset.
    int nLength = strlen(pszParam);
    
    if(nLength == 0)
    {
        return 0;
    }

    // allocated memory considering null character.
    m_pszData = new char[nLength +1];

    // save string to new allocated memory.
    strcpy(m_pszData, pszParam);
    m_nLength = nLength;
    
    // return the length of string.
    return nLength;
}

const char* CMyString::GetString() const
{
    return m_pszData;
}

void CMyString::Release()
{
    // considering a situation that this function is called many times, reset major members.
    if(m_pszData != nullptr)
    {
        delete [] m_pszData;
    }

    m_pszData = nullptr;
    m_nLength = 0;
}