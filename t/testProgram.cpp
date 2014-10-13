#include <string>
#include <vector>

#include "gtest/gtest.h"
#include "Program.h"

#define PROGRAM_01 "data/program_01.eye"
#define PROGRAM_02 "data/program_02.eye"

using namespace EyeTER;

TEST(program, loadFromFile)
{
    Program program01, program02;
    ASSERT_EQ(program01.getProcedureCount(), 0)
        << "There should be no procedures after creating the program object";

    program01.loadFromFile(PROGRAM_01);

    ASSERT_EQ(program01.getProcedureCount(), 1)
        << PROGRAM_01 << " should contain 1 procedure";

    ASSERT_NO_THROW(program02.loadFromFile(PROGRAM_02))
        << "loading a file which exists should't throw an exaption";

    ASSERT_EQ(program02.getProcedureCount(), 2)
        << PROGRAM_02 << " should contain 2 procedures";

    ASSERT_ANY_THROW(program01.loadFromFile("file_doesnt_exist.eye"))
        << "loading a file which doesn't exist should throw an exception";
}

TEST(program, programVersion)
{
    Program program;
    program.loadFromFile(PROGRAM_02);

    ASSERT_EQ(program.getVersion(), "0.1");
}
