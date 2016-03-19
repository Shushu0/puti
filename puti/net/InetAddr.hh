#ifndef PUTI_NET_INETADDR_H_
#define PUTI_NET_INETADDR_H_

#include "Net.hh"

namespace puti
{
    class InetAddr
    {
    public:
        InetAddr()
        {
            memset(&addr_, 0, sizeof(addr_));
        }


        InetAddr(sa_family_t family, uint16_t port, const std::string& ip)
        {
            addr_.sin_family      = family;
            addr_.sin_port        = htons(port);
            addr_.sin_addr.s_addr = inet_addr_p2n(ip);
        }

        

        /**
         * @brief: 
         * @date: Thu Dec 31 18:10:03 CST 2015 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        std::string tostring()const ;

        struct sockaddr_in addr()const
        {
            return addr_;
        }

        void set_addr(const struct sockaddr_in sa)
        {
            ::memcpy(&addr_, &sa, sizeof(sa));
        }

        void set_port(const uint16_t port)
        {
            addr_.sin_port = htons(port);
        }
    private:
        /**
         * @brief: 
         * @date: Thu Dec 31 17:42:57 CST 2015 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        static std::string inet_addr_n2p(const uint32_t naddr);

        /**
         * @brief: 
         * @date: Thu Dec 31 17:43:07 CST 2015 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        static uint32_t inet_addr_p2n(const std::string& paddr);

    private:
        struct sockaddr_in addr_;
    };
} /* namespace puti */


#endif /* PUTI_NET_INETADDR_H_ */
