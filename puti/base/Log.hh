#ifndef PUTI_BASE_LOG_H_
#define PUTI_BASE_LOG_H_

#include <string>

#include "File.hh"

namespace puti
{

    class Log
    {
     public:
        enum LogLevel
        {
            LT_TRACE = 0,
            LT_DEBUG,
            LT_INFO,
            LT_WARN,
            LT_ERROR,
            LT_FATAL,

            LT_MAX,
        };
    
        static void setLogFile(const std::string& path)
        {
           logfile_ = File(path); 
        }

        static void log(LogLevel ll, const std::string& content);
     private:
        static File logfile_;
    };
}

#endif /* PUTI_BASE_LOG_H_ */
