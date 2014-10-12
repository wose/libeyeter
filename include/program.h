#ifndef _EYETER_PROGRAM_H_
#define _EYETER_PROGRAM_H_

#include <string>
#include <vector>

class Program
{
 public:
    Program();
    ~Program();

 private:
    std::string version_;
    std::vector<std::string> procedures_;

 public:
    std::string getVersion() const;
    unsigned int getProcedureCount() const;
    std::vector<std::string> getProcedures() const;

    void loadFromFile(const std::string& file);
    void loadFromString(const std::string& program);
};

#endif
