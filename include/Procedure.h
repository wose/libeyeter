#ifndef _EYETER_PROCEDURE_H_
#define _EYETER_PROCEDURE_H_

#include <string>
#include <vector>

#include "pugixml.hpp"

namespace EyeTER {

class Procedure
{
 public:
    Procedure();
    Procedure(const pugi::xpath_node& node);
    ~Procedure();

 private:
    std::string name_;
    std::string body_;

    std::vector<std::string> iconic_inputs_;
    std::vector<std::string> iconic_outputs_;
    std::vector<std::string> control_inputs_;
    std::vector<std::string> control_outputs_;

 public:
    void load(const pugi::xpath_node& node);
    std::string getName() const;
    void setName(const std::string& name);
    std::string getBody() const;
    void setBody(const std::string& body);
};

}
#endif
