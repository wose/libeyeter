#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "program.h"

#define PROGRAM_01 "data/program_01.eye"
#define PROGRAM_02 "data/program_02.eye"

TEST(program, loadFromFile)
{
    Program program01, program02;
    program01.loadFromFile(PROGRAM_01);

    ASSERT_EQ(program01.getProcedureCount(), 1);

    program02.loadFromFile(PROGRAM_02);
    ASSERT_EQ(program02.getProcedureCount(), 2);
}

TEST(program, procedureNames)
{
    Program program;
    program.loadFromFile(PROGRAM_02);

    std::vector<std::string> procedures = program.getProcedures();
    ASSERT_EQ(procedures[0], "main");
    ASSERT_EQ(procedures[1], "foo");
}

TEST(program, programVersion)
{
    Program program;
    program.loadFromFile(PROGRAM_02);

    ASSERT_EQ(program.getVersion(), "0.1");
}
