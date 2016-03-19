#include "../Time.h"

#include <iostream>
int main()
{
    std::cout<<puti::Time::current().c_str()<<std::endl;
    return 0;
}
