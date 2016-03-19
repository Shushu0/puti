#include "File.hh"
namespace puti
{

    std::string File::read() const
    {
       char buf[256] = { 0 };
       ssize_t nread = ::read(fd_, buf, sizeof(buf));
       if (nread <= 0)
           return std::string();
       else
           return std::string(buf);
    }


    ssize_t File::write(const std::string& content)
    {
       return ::write(fd_, content.c_str(), content.length());
    }

    off_t File::seek(off_t offset, int whence)
    {
       return ::lseek(fd_, offset, whence);
    }


    int32_t File::size()const
    {
        struct stat st;
        ::fstat(fd_, &st);
        return st.st_size;
    }

} /* namespace puti */
