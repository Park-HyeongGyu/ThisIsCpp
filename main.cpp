#include <iostream>
#include "MyString.h"

void TestFunc(const CMyString &strParam)
{
    std::cout << strParam << std::endl;
}
// const char *에 대한 변환생성자와 char*로의 형변환 연산자를 만들어 넣으셈
int main()
{
    CMyString strData("Hello");

    ::TestFunc(strData);
    ::TestFunc(CMyString("World"));

    return 0;
}