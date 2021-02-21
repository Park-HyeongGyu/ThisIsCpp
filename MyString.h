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

    int GetLength() const;
    int Append(const char* pszParam);
    CMyString operator+(const CMyString &rhs);
    CMyString& operator+=(const CMyString &rhs);

    char operator[](int index) const;
    char& operator[](int index);

    int operator==(const CMyString &rhs);
    int operator!=(const CMyString &rhs);

    virtual void OnSetString(char *pszData, int nLength);
};