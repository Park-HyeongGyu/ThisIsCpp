#include <iostream>
#include "MyStringEx.h"

int main()
{
    CMyStringEx strTest;
    strTest.SetString("멍멍이아들");
    std::cout << strTest << std::endl;

    return 0;
}