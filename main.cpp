#include <iostream>
#include "MyStringEx.h"

int main()
{
    CMyStringEx strTest;
    strTest.SetString("I am a boy.");
    std::cout << strTest << std::endl;

    int nIndex = strTest.Find("am");
    std::cout << "Index: " << nIndex << std::endl;

    return 0;
}