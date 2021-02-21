#include <iostream>
#include "MyStringEx.h"

int main()
{
    CMyStringEx strLeft("Hello"), strRight("World");
    std::cout << strLeft + strRight << std::endl;

    return 0;
}