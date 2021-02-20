#include <iostream>
#include "MyString.h"

int main()
{
    CMyString strData, strTest;
    strData.SetString("Hello");
    strTest.SetString("World");

    // copy generating.
    CMyString strNewData(strData);
    std::cout << strNewData.GetString() << std::endl;

    // calling operator=.(단순 대입연산자 호출)
    strNewData = strTest;
    std::cout << strNewData.GetString() << std::endl;

    return 0;
}