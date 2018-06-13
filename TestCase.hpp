#ifndef TESTCASE_HPP
#define TESTCASE_HPP

#include<iostream>
#include <sstream>

using namespace std;

class TestCase{
    string testName;
    ostream &out;
    int totalTests;
    int passedTests;
    int failedTests;


public:
    TestCase(const string testName, ostream &out);
    TestCase&  print();

    template <typename T>
    TestCase& check_equal(const T &a,const T &b)
    {
        totalTests++;
        if(a!=b)
        {
            out<<testName<<": Failure in test #"<<to_string(totalTests)<<": "<<a<<" should equal "<<b<<"!\n";
            failedTests++;
        }
        else
        {
            passedTests++;
        }
        return *this;

    }

    template<typename T>
    TestCase& check_different(const T &a,const T &b)
    {
         totalTests++;
         if(a==b)
         {
            failedTests++;
            out<<testName<<": Failure in test #"<<to_string(totalTests)<<": "<<a<<" shouldn't equal "<<b<<"!\n";
      
         }
         else
         {
             passedTests++;

         }
         return *this;

    }

    template<typename T>
    TestCase& check_output(const T &a,const string str)
    {
        totalTests++;
        stringstream io_str;
        io_str<<a;
        if(io_str.str()==str)
        {
            passedTests++;
        }
        else
        {
            failedTests++;
            out<<testName<<": Failure in test #"<<to_string(totalTests)<<": string value should be "<<io_str.str()<<" but is "<<str<<"\n";

        }
        return *this;

    }

    template<typename T1,typename T2,typename T3>
    TestCase& check_function(const T1 function,const T2 &t2,const T3 &t3)
    {
        totalTests++;
        if(function(t2)==t3)
        {
            passedTests++;
        }
        else
        {
            failedTests++;
            out<<testName<<": Failure in test #"<<to_string(totalTests)<<": Function should return "<<t3<<" but returned "<<function(t2)<<"\n";
            
        }
        return *this;
    }








};




#endif // TESTCASE_HPP
