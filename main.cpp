#include <iostream>
#include "MyString.h"

CMyString TestFunc()
{
    CMyString strTest("TestFunc() return");
    std::cout << strTest << std::endl;

    return strTest;
}

int main()
{
    // No name contemporary object is made.
    CMyString a = TestFunc();

    return 0;
}