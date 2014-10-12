#include "program.h"
#include "pugixml.hpp"
#define PUGIXML_HEADER_ONLY
#include "pugixml.cpp"

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

std::vector<std::string> Program::getProcedures() const
{
    return procedures_;
}

void Program::loadFromFile(const std::string& file)
{
    pugi::xml_document doc;
    std::string namePanel;

    if(!doc.load_file(file.c_str()))
        throw "foo";

    pugi::xpath_node version = doc.select_single_node("/eyeter");
    version_ = version.node().attribute("version").value();

    pugi::xpath_node_set procedures = doc.select_nodes("/procedure");

    for(pugi::xpath_node_set::const_iterator it = procedures.begin(); it != procedures.end(); ++it)
    {
        pugi::xpath_node node = *it;
        procedures_.push_back(node.node().attribute("name").value());
    }
}

void Program::loadFromString(const std::string& program)
{
}
