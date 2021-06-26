/*
    Copyright (c) 2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/Ishiko-cpp/TestFramework/blob/master/LICENSE.txt
*/

#ifndef _ISHIKO_TEST_TESTFRAMEWORK_CORE_TESTMACROSFORMATTERTESTS_H_
#define _ISHIKO_TEST_TESTFRAMEWORK_CORE_TESTMACROSFORMATTERTESTS_H_

#include "Ishiko/TestFramework/TestFrameworkCore.h"

class TestMacrosFormatterTests : public Ishiko::Tests::TestSequence
{
public:
    TestMacrosFormatterTests(const Ishiko::Tests::TestNumber& number,
        const Ishiko::Tests::TestEnvironment& environment);

private:
    static void FormatTest1(Ishiko::Tests::Test& test);
    static void FormatTest2(Ishiko::Tests::Test& test);
    static void FormatTest3(Ishiko::Tests::Test& test);
    static void FormatTest4(Ishiko::Tests::Test& test);
    static void FormatTest5(Ishiko::Tests::Test& test);
    static void FormatTest6(Ishiko::Tests::Test& test);
};

#endif
