#ifndef PUTI_BASE_FILE_H_
#define PUTI_BASE_FILE_H_
#include <unistd.h>
#include <stdint.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <string>
#include <iostream>
/**
 * @brief: 
 * @date: Wed Dec 30 16:15:18 CST 2015 
 * @author: zhuoliang@360.cn
 */

namespace puti
{
    class File
    {
     public:
       explicit File(const std::string& path)
        :path_(path)
       {
           init(); 
       }
        
       ~File()
       {
           close();
       }
       void init()
       {
           fd_ = ::open(path_.c_str(), O_CREAT|O_APPEND, 0666);
           assert(fd_ >= 0);
       }
    
       /**
        * @brief: 
        * @date: Wed Dec 30 16:09:15 CST 2015 
        * @author: zhuoliang@360.cn
        * @param: 
        * @return: -1 on error
        */
    
       std::string read()const;
       
       /**
        * @brief: 
        * @date: Wed Dec 30 16:10:55 CST 2015 
        * @author: zhuoliang@360.cn
        * @param: 
        * @return: 
        */
       ssize_t write(const std::string& content);
       
       /**
        * @brief: 
        * @date: Wed Dec 30 16:11:01 CST 2015 
        * @author: zhuoliang@360.cn
        * @param: 
        * @return: 
        */
        off_t seek(off_t offset, int whence);
    
        /**
         * @brief: 
         * @date: Wed Dec 30 16:12:16 CST 2015 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: 
         */
        int32_t size()const;
    
        /**
         * @brief: 
         * @date: Wed Dec 30 16:13:06 CST 2015 
         * @author: zhuoliang@360.cn
         * @param: 
         * @return: -1 on error, zero on success
         */
        int32_t close()
        {
            return ::close(fd_);
        }
     private:
       int32_t fd_;
       std::string path_;   
    };
}
#endif /* PUTI_BASE_FILE_H_ */
