#include "TestCase.hpp"


TestCase:: TestCase(string testName,ostream &out ):totalTests(0),passedTests(0),failedTests(0),out(out),testName(testName)
{
}

TestCase& TestCase::print()
{

    string  str=testName+" "+to_string(failedTests)+" failed, "+to_string(passedTests)+" passed, "+to_string(totalTests)+" total.\n";
    std::cout<<str;
    return *this;

}
