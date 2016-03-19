#ifndef PUTI_NET_SOCKET_H_
#define PUTI_NET_SOCKET_H_

#include "Net.hh"

#include "InetAddr.hh"

namespace puti 
{
    class Socket
    {
    public:
        Socket()
        {
            init();
        }

         Socket(const int32_t fd)
            :socketfd_(fd)
        {}


         ~Socket()
         {
            close();   
         }
        /**
         * @brief: 
         * @date: Wed Jan  6 19:47:04 CST 2016 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        bool bind(const InetAddr& addr);

        /**
         * @brief: 
         * @date: Wed Jan  6 19:47:12 CST 2016 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        Socket accept(InetAddr *addr);

        /**
         * @brief: 
         * @date: Wed Jan  6 19:47:21 CST 2016 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        bool connect(const InetAddr& addr);

        /**
         * @brief: 
         * @date: Wed Jan  6 19:47:34 CST 2016 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        bool listen(const int32_t backlog);

        /**
         * @brief: 
         * @date: Wed Jan  6 19:47:41 CST 2016 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        bool shutdown_write();

        /**
         * @brief: 
         * @date: Wed Jan  6 19:47:49 CST 2016 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        void close()
        {
            ::close(socketfd_);
        }

        int32_t fd()const
        {
            return socketfd_;
        }

        bool is_valid()const
        {
            return socketfd_ >= 0;
        }
    private:
        void init();
    private:
        int32_t socketfd_;
    };
} /* namespace puti */

#endif /* PUTI_NET_SOCKET_H_ */
