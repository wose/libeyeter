#include <stdexcept>

#include "Procedure.h"

using namespace EyeTER;

Procedure::Procedure()
{
}

Procedure::Procedure(const pugi::xpath_node& node)
{
    load(node);
}

Procedure::~Procedure()
{
}

void Procedure::load(const pugi::xpath_node& node)
{
    name_ = node.node().attribute("name").value();
    pugi::xpath_node_set lines = node.node().select_nodes("body/child::*");

    for(auto line : lines) {
        body_ += line.node().child_value();
        body_ += "\n";
    }
}

std::string Procedure::getName() const
{
    return name_;
}

void Procedure::setName(const std::string& name)
{
    name_ = name;
}

std::string Procedure::getBody() const
{
    return body_;
}

void Procedure::setBody(const std::string& body)
{
    body_ = body;
}
