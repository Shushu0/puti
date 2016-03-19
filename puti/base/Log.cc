#include "Log.hh"

#include <stdio.h>
#include "Time.hh"
namespace puti
{
   File Log::logfile_ = File("tmp.log");
   void Log::log(Log::LogLevel ll, const std::string& content)
   {
       static const char* log_type_strs[Log::LT_MAX] = {
                        "TRACE",
                        "DEBUG",
                        "INFO",
                        "WARNING",
                        "ERROR",
                        "FATAL"};
       std::string timestr = Time::current();
       char buf[1024] = { 0 };
       snprintf(buf, sizeof(buf), "%s\t%s : %s\n", timestr.c_str(), log_type_strs[ll], content.c_str());
       logfile_.write(buf);
       //logfile_.close();
       return;
   }
} /* namespace puti*/
