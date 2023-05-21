#include "ctest.h"
#include <string.h>
#include <conversion.h>
#include <Check_Error.h>

CTEST(convert, t1)
{
    const double expected = 1000;
    char HAVEunit[7] = "kg";
    char WANTunit[7] = "g";
    const double real = Convert(HAVEunit, 2, WANTunit, 1, 1);
    ASSERT_EQUAL(expected, real);
}

CTEST(convert, t2)
{
    const double expected = 10;
    char HAVEunit[7] = "kg";
    char WANTunit[7] = "ton";
    const double real = Convert(HAVEunit, 2, WANTunit, 3, 10000);
    ASSERT_EQUAL(expected, real);
}

CTEST(convert, t3)
{
    const double expected = 0.123;
    char HAVEunit[7] = "m";
    char WANTunit[7] = "km";
    const double real = Convert(HAVEunit, 1, WANTunit, 2, 123);
    ASSERT_EQUAL(expected, real);
}

CTEST(convert, t4)
{
    char HAVEunit[7] = "km/h";
    char WANTunit[7] = "km/m";
    const double expected = 2;
    const double real = Convert(HAVEunit, 4, WANTunit, 4, 120);
    ASSERT_EQUAL(expected, real);
}

CTEST(convert, t5)
{
    char HAVEunit[7] = "m/s";
    char WANTunit[7] = "km/s";
    const double expected = 360;
    const double real = Convert(HAVEunit, 3, WANTunit, 4, 100);
    ASSERT_EQUAL(expected, real);
}

CTEST(convert, t6)
{
    char HAVEunit[7] = "hour";
    char WANTunit[7] = "sec";
    const double expected = 3600;
    const double real = Convert(HAVEunit, 4, WANTunit, 1, 1);
    ASSERT_EQUAL(expected, real);
}

CTEST(CheckError, t7)
{
    char HAVEunit[7] = "hour";
    char WANTunit[7] = "sec";
    const int expected = 0;
    const int real = Check_Units_Name(HAVEunit, 4, WANTunit, 3, 1);
    ASSERT_EQUAL(expected, real);
}

CTEST(CheckError, t8)
{
    char HAVEunit[7] = "hur";
    char WANTunit[7] = "sec";
    const int expected = 1;
    const int real = Check_Units_Name(HAVEunit, 3, WANTunit, 3, 1);
    ASSERT_EQUAL(expected, real);
}

CTEST(CheckError, t9)
{
    char HAVEunit[7] = "hour";
    char WANTunit[7] = "s";
    const int expected = 2;
    const int real = Check_Units_Name(HAVEunit, 4, WANTunit, 1, 1);
    ASSERT_EQUAL(expected, real);
}

CTEST(CheckError, t10)
{
    char HAVEunit[7] = "hour";
    char WANTunit[7] = "kg";
    const int expected = 3;
    const int real = Check_Units_Name(HAVEunit, 4, WANTunit, 2, 1);
    ASSERT_EQUAL(expected, real);
}

CTEST(CheckError, t11)
{
    char HAVEunit[7] = "hour";
    char WANTunit[7] = "kg";
    const int expected = 3;
    const int real = Check_Units_Name(HAVEunit, 4, WANTunit, 2, 1);
    ASSERT_EQUAL(expected, real);
}

CTEST(CheckError, t12)
{
    char input[20] = "20kg";
    const int expected = 4;
    const int real = Check_space(input);
    ASSERT_EQUAL(expected, real);
}

CTEST(CheckError, t13)
{
    char input[20] = "kg 20";
    const int expected = 5;
    const int real = Check_number(input);
    ASSERT_EQUAL(expected, real);
}
