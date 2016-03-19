#include "../InetAddr.hh"

#include <iostream>

int main()
{
    std::cout<<puti::InetAddr::inet_addr_p2n("192.168.1.2")<<std::endl;
    std::cout<<puti::InetAddr::inet_addr_p2n("www.baidu.com")<<std::endl;
    std::cout<<puti::InetAddr::inet_addr_n2p(33663168)<<std::endl;
    return 0;
}
