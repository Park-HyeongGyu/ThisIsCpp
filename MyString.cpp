#include "MyString.h"
#include <cstring>
#include <iostream>

CMyString::CMyString() :m_pszData(nullptr), m_nLength(0)
{
    // std::cout << "constructor is called" << std::endl;
}
CMyString::~CMyString() { Release(); }

// In case of object, Solve with object's way!!
CMyString::CMyString(const CMyString &rhs) : m_pszData(nullptr), m_nLength(0)
{
    // std::cout << "CMyString::CMyString(const CMyString &rhs)" << std::endl; 
    this->SetString(rhs.GetString());
}

CMyString::CMyString(const char* str) : m_pszData(nullptr), m_nLength(0)
{
    // std::cout << "CMyString::CMyString(const char* str) : m_pszData(nullptr), m_nLength(0)" << std::endl;
    this->SetString(str);
}

CMyString::CMyString(CMyString &&rhs)
{
    // std::cout << "Move constructor of CMyString is called" << std::endl;

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
    // std::cout << "CMyString& CMyString::operator=(const CMyString &rhs)" << std::endl;

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

int CMyString::GetLength() const
{
    return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
    // checking validity of parameter
    if(pszParam == nullptr)
    {
        return 0;
    }

    int nLenParam = strlen(pszParam);

    if(nLenParam == 0)
    {
        return 0;
    }

    // if threre is no string setted, do as allocating new string.
    if(m_pszData == nullptr)
    {
        SetString(pszParam);

        return m_nLength;
    }

    // Back up length of current string.
    int nLenCur = m_nLength;

    // Allocate new memory that can be saved added two string.
    char *pszResult = new char[nLenCur + nLenParam +1];

    // Append string.
    strcpy(pszResult, m_pszData);
    strcpy(pszResult+(sizeof(char)*nLenCur), pszParam);

    // Delete current string and renew member information.
    Release();
    m_pszData = pszResult;
    m_nLength = nLenCur + nLenParam;

    return m_nLength;
}

CMyString CMyString::operator+(const CMyString &rhs)
{
    CMyString cont;
    cont.Append(this->GetString());
    cont.Append(rhs.GetString());
    
    return cont;
}

CMyString& CMyString::operator+=(const CMyString &rhs)
{
    this->Append(rhs.GetString());

    return *this;
}

char CMyString::operator[](int index) const
{
    if(index < 0 || index > m_nLength-1)
    {
        std::cout << "Index out of range" << std::endl;
        return m_pszData[0];
    }
    return m_pszData[index];
}

char& CMyString::operator[](int index)
{
    if(index < 0 || index > m_nLength -1 )
    {
        std::cout << "Index out of range" << std::endl;
        return m_pszData[0];
    }
    return m_pszData[index];
}

int CMyString::operator==(const CMyString &rhs)
{
    if(m_pszData != nullptr && rhs.m_pszData != nullptr)
    {
        if(strcmp(m_pszData, rhs.m_pszData) == 0)
        {
            return 1;
        }
    }

    return 0;
}

int CMyString::operator!=(const CMyString &rhs)
{
    if(m_pszData != nullptr && rhs.m_pszData != nullptr)
    {
        if(strcmp(m_pszData, rhs.m_pszData) == 0)
        {
            return 0;
        }
    }

    return 1;
}