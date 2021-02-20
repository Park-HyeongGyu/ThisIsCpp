#include "MyString.h"
#include <cstring>
#include <iostream>

CMyString::CMyString() :m_pszData(nullptr), m_nLength(0)
{
    std::cout << "constructor is called" << std::endl;
}
CMyString::~CMyString() { Release(); }

// In case of object, Solve with object's way!!
CMyString::CMyString(const CMyString &rhs) : m_pszData(nullptr), m_nLength(0)
{
    std::cout << "CMyString::CMyString(const CMyString &rhs)" << std::endl; 
    this->SetString(rhs.GetString());
}

CMyString::CMyString(const char* str) : m_pszData(nullptr), m_nLength(0)
{
    // std::cout << "CMyString::CMyString(const char* str) : m_pszData(nullptr), m_nLength(0)" << std::endl;
    this->SetString(str);
}

CMyString::CMyString(CMyString &&rhs)
{
    std::cout << "Move constructor of CMyString is called" << std::endl;

    // It is okay to do shallow copy! Because original will be disappear!
    m_pszData = rhs.m_pszData;
    m_nLength = rhs.m_nLength;

    // Initialize members of original contemporary object. Never disassemble.
    rhs.m_pszData = nullptr;
    rhs.m_nLength = 0;
    // Because of destructor of original contemporary object?
}

CMyString& CMyString::operator=(const CMyString &rhs)
{
    std::cout << "CMyString& CMyString::operator=(const CMyString &rhs)" << std::endl;

    if(this != &rhs)
    {
        this->SetString(rhs.GetString());
    }
    
    return *this;
}

int CMyString::SetString(const char* pszParam)
{
    // before allocating new string, release before information.
    Release();

    // Call function with null parameter means that deallocate memory and allocate with null.
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