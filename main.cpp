#include <iostream>
#include "MyString.h"

int main()
{
    CMyString strLeft("Test"), strRight("String");

    if(strLeft == strRight)
    {
        std::cout << "Same" << std::endl;
    }
    else
    {
        std::cout << "Different" << std::endl;
    }

    strLeft = CMyString("String");

    if(strLeft != strRight)
    {
        std::cout << "Different" << std::endl;
    }
    else
    {
        std::cout << "Same" << std::endl;
    }

    return 0;
}