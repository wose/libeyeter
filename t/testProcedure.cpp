#include "pugixml.hpp"

#include "gtest/gtest.h"
#include "Program.h"
#include "Procedure.h"

#define PROGRAM_01 "data/program_01.eye"
#define PROGRAM_02 "data/program_02.eye"

using namespace EyeTER;

TEST(procedure, constructor)
{
    Procedure proc;
    ASSERT_EQ(proc.getName(), "")
        << "name should be empty after creation";
    ASSERT_EQ(proc.getBody(), "")
        << "procedure body should be empty after creation";
}

TEST(procedure, load)
{
    Program program;
    program.loadFromFile(PROGRAM_01);
    std::vector<Procedure> procedures = program.getProcedures();

    ASSERT_EQ(procedures[0].getName(), "main")
        << "name of the first procedure should be main";

    ASSERT_EQ(procedures[0].getBody(),
              "foo:= 42.23\n"
              "bar:= 23.42\n"
              "operator1(foo)\n"
              "operator2(bar)\n"
              "\n"
              "* test comment\n");

}
