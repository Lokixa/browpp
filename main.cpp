#include "includes/curl.h"
#include <iostream>

int main()
{
    curl curl{};
    std::cout << curl.get("https://lyubenk.com") << std::endl;
}
