#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/unit_test.hpp>

//Compile: g++ -o test CiagFibonacciego.cpp -lboost_unit_test_framework
//Funkcja oblicza ciag fibonacciego z zakresu 0-30
//Dla pozostalych wartosci zwraca (-1)

int Fibonacci(int x)
{
        if((x < 0) || (x > 30))
                return -1;
        else if (x == 0)
                return 0;
        else if (x == 1)
                return 1;

        int value1 = 0;
        int value2 = 1;
        int sum = value1 + value2;

        for(int i=2;i<=x;i++)
        {
                sum = value1 + value2;
                value1 = value2;
                value2 = sum;
        };
        return sum;
};


BOOST_AUTO_TEST_SUITE( FibonacciSuite )

BOOST_AUTO_TEST_CASE( wartosci )
{
        BOOST_CHECK(Fibonacci(31) == -1);
        BOOST_CHECK(Fibonacci(200) == -1);
        BOOST_CHECK(Fibonacci(1000) == -1);

        BOOST_CHECK(Fibonacci(-1) == -1);
        BOOST_CHECK(Fibonacci(-30) == -1);
        BOOST_CHECK(Fibonacci(-100000000) == -1);
}

BOOST_AUTO_TEST_CASE( zakres )
{
        BOOST_CHECK(Fibonacci(0) == 0);
        BOOST_CHECK(Fibonacci(1) == 1);
        BOOST_CHECK(Fibonacci(2) == 1);
        BOOST_CHECK(Fibonacci(3) == 2);
        BOOST_CHECK(Fibonacci(8) == 21);
        BOOST_CHECK(Fibonacci(16) == 987);
        BOOST_CHECK(Fibonacci(19) == 4181);
}

BOOST_AUTO_TEST_SUITE_END()
