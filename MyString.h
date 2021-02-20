#pragma once

class CMyString
{
public:
    CMyString();
    CMyString(const CMyString &rhs);
    ~CMyString();

    explicit CMyString(const char* str);
    operator char*() const
    {
        return m_pszData;
    }

    CMyString(CMyString &&rhs);

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