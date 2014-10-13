#include <stdexcept>

#include "Program.h"
#include "Procedure.h"

#include "pugixml.hpp"

namespace EyeTER {

Program::Program()
{
}

Program::~Program()
{
}

std::string Program::getVersion() const
{
    return version_;
}

unsigned int Program::getProcedureCount() const
{
    return procedures_.size();
}

std::vector<Procedure> Program::getProcedures() const
{
    return procedures_;
}

void Program::loadFromFile(const std::string& file)
{
    pugi::xml_document doc;
    std::string namePanel;

    if(!doc.load_file(file.c_str()))
        throw std::runtime_error("Failed to open file");

    pugi::xpath_node version = doc.select_single_node("/eyeter");
    version_ = version.node().attribute("version").value();

    pugi::xpath_node_set procedures = doc.select_nodes("/procedure");

    for(auto procedure : procedures) {
        procedures_.push_back(Procedure(procedure));
    }
}

void Program::loadFromString(const std::string& program)
{
}

}
