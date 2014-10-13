#ifndef _EYETER_PROGRAM_H_
#define _EYETER_PROGRAM_H_

#include <string>
#include <vector>

#include "Procedure.h"

namespace EyeTER {

class Program
{
 public:
    Program();
    ~Program();

 private:
    std::string version_;
    std::vector<Procedure> procedures_;

 public:
    std::string getVersion() const;
    unsigned int getProcedureCount() const;
    std::vector<Procedure> getProcedures() const;

    void loadFromFile(const std::string& file);
    void loadFromString(const std::string& program);
};

}
#endif
