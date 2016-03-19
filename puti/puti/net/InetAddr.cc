#include "InetAddr.hh"

#include <netdb.h>


namespace puti 
{

    std::string InetAddr::inet_addr_n2p(const uint32_t naddr)
    {
        char buf[INET_ADDRSTRLEN] = { 0 };
        if (::inet_ntop(AF_INET, &naddr, buf, sizeof(buf)) != NULL)
        {
            return std::string(buf);
        }
        else
        {
            Log::log(Log::LT_FATAL, strerror(errno));
            ::exit(1);  
        }
    }

    uint32_t InetAddr::inet_addr_p2n(const std::string& paddr)
    {
        uint32_t ret;
        struct hostent *hp = gethostbyname(paddr.c_str());
        if (hp == NULL)
        {
            if (::inet_pton(AF_INET, paddr.c_str(), &ret) == 0)
            {
                 return ret;
            }
            else
            {
                 Log::log(Log::LT_ERROR, strerror(errno));
                 ::exit(1);
            }    
        
        }
        else
        {
            return *reinterpret_cast<uint32_t*>(hp->h_addr_list[0]);  
        }
        
    }


    std::string InetAddr::tostring()const
    {
        std::stringstream ss;
        ss<<"[Family: AF_INET; Port: "<<ntohs(addr_.sin_port)<<"; IP: "<<inet_addr_n2p(addr_.sin_addr.s_addr)<<"]";
        return ss.str();
    }
} /* namespace puti */
