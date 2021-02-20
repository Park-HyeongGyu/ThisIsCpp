#include <iostream>
#include "MyString.h"

int main()
{
    CMyString strLeft("Hello"), strRight("World"), strResult;
    strResult = strLeft + strRight;

    std::cout << strResult << std::endl;

    std::cout << strLeft << std::endl;
    strLeft += CMyString("World");
    std::cout << strLeft << std::endl;

    return 0;
}