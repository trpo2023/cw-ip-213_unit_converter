#include "ctest.h"
#include <string.h>
#include <conversion.h>

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
