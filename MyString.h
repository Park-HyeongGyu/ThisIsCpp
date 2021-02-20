#pragma once

class CMyString
{
public:
    CMyString();
    CMyString(const CMyString &rhs);
    ~CMyString();

    CMyString& operator=(const CMyString &rhs);

private:
    // pointer that indicate dynamic allocated memory for saving string.
    char* m_pszData;

    // length of saved string.
    int m_nLength;

public:
    int SetString(const char* pszParam);
    const char* GetString() const;
    void Release();
};