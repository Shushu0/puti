#include "Socket.hh"

namespace puti
{
    void Socket::init()
    {
        socketfd_ = ::socket(AF_INET, SOCK_STREAM, 0);
        if (socketfd_ < 0)
        {
            Log::log(Log::LT_FATAL, strerror(errno));
            ::exit(1);
        }
    }
    bool Socket::bind(const InetAddr& addr)
    {
        struct sockaddr_in sa = addr.addr();
        int32_t ret = ::bind(socketfd_, (struct sockaddr*)&sa, sizeof(sa));
        if (ret != 0)
        {
            Log::log(Log::LT_ERROR, strerror(errno));
            return false;
        }
        else
        {
            std::stringstream ss;
            ss<<"socket file descriptor "<<socketfd_<<" bound to inet_addr"<<addr.tostring();
            Log::log(Log::LT_DEBUG, ss.str());
            return true;
        }

    }
    Socket Socket::accept(InetAddr *addr)
    {
        struct sockaddr_in sa;
        socklen_t len;
        int32_t ret = ::accept(socketfd_, (struct sockaddr*)&sa, &len);
        if (ret < 0)
        {
            Log::log(Log::LT_ERROR, strerror(errno));
            return Socket(-1);
        }
        else
        {
           addr->set_addr(sa);
           std::stringstream ss;
           ss<<"accept from inet_addr"<<addr->tostring()<<", socket file descriptors "<<ret<<"-->"<<socketfd_;
           Log::log(Log::LT_DEBUG, ss.str());
           return Socket(ret);
        }
    }

    bool Socket::connect(const InetAddr& addr)
    {
        struct sockaddr_in sa = addr.addr();
        int32_t ret = ::connect(socketfd_, (struct sockaddr*)&sa, sizeof(sa));
        if (ret < 0)
        {
            Log::log(Log::LT_ERROR, strerror(errno));
            return false;
        }
        else
        {
            std::stringstream ss;
            ss<<"socket file descriptor "<<socketfd_<<" connect to inet_addr"<<addr.tostring();
            Log::log(Log::LT_DEBUG, ss.str());
            return true;
        }
    }
    
} /* namespace puti */
