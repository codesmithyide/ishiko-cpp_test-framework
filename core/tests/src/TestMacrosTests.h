// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#ifndef GUARD_ISHIKO_TESTFRAMEWORK_TESTS_CORE_TESTMACROSTESTS_H
#define GUARD_ISHIKO_TESTFRAMEWORK_TESTS_CORE_TESTMACROSTESTS_H

#include <Ishiko/TestFramework/Core.hpp>

class TestMacrosTests : public Ishiko::TestSequence
{
public:
    TestMacrosTests(const Ishiko::TestNumber& number, const Ishiko::TestContext& context);

private:
    static void PassMacroTest1(Ishiko::Test& test);
    static void FailMacroTest1(Ishiko::Test& test);
    static void FailIfMacroTest1(Ishiko::Test& test);
    static void FailIfMacroTest2(Ishiko::Test& test);
    static void FailIfNotMacroTest1(Ishiko::Test& test);
    static void FailIfNotMacroTest2(Ishiko::Test& test);
    static void FailIfEqMacroTest1(Ishiko::Test& test);
    static void FailIfEqMacroTest2(Ishiko::Test& test);
    static void FailIfNeqMacroTest1(Ishiko::Test& test);
    static void FailIfNeqMacroTest2(Ishiko::Test& test);
    static void FailIfStrEqMacroTest1(Ishiko::Test& test);
    static void FailIfStrEqMacroTest2(Ishiko::Test& test);
    static void FailIfStrNeqMacroTest1(Ishiko::Test& test);
    static void FailIfStrNeqMacroTest2(Ishiko::Test& test);
    static void FailIfNotContainMacroTest1(Ishiko::Test& test);
    static void FailIfNotContainMacroTest2(Ishiko::Test& test);
    static void FailIfHeapAllocationCountNeqTest1(Ishiko::Test& test);
    static void FailIfHeapAllocationCountNeqTest2(Ishiko::Test& test);
    static void FailIfHeapAllocationCountNeqTest3(Ishiko::Test& test);
    static void FailIfOutputAndReferenceFilesNeqMacroTest1(Ishiko::Test& test);
    static void FailIfOutputAndReferenceFilesNeqMacroTest2(Ishiko::Test& test);
    static void FailIfOutputAndReferenceFilesNeqMacroTest3(Ishiko::Test& test);
    static void FailIfOutputAndReferenceFilesNeqMacroTest4(Ishiko::Test& test);
    static void FailIfOutputAndReferenceFilesNeqMacroTest5(Ishiko::Test& test);
    static void FailIfOutputAndReferenceFilesNeqMacroTest6(Ishiko::Test& test);
    static void AbortMacroTest1(Ishiko::Test& test);
    static void AbortIfMacroTest1(Ishiko::Test& test);
    static void AbortIfMacroTest2(Ishiko::Test& test);
    static void AbortIfNotMacroTest1(Ishiko::Test& test);
    static void AbortIfNotMacroTest2(Ishiko::Test& test);
    static void AbortIfEqMacroTest1(Ishiko::Test& test);
    static void AbortIfEqMacroTest2(Ishiko::Test& test);
    static void AbortIfNeqMacroTest1(Ishiko::Test& test);
    static void AbortIfNeqMacroTest2(Ishiko::Test& test);
    static void AbortIfStrEqMacroTest1(Ishiko::Test& test);
    static void AbortIfStrEqMacroTest2(Ishiko::Test& test);
    static void AbortIfStrNeqMacroTest1(Ishiko::Test& test);
    static void AbortIfStrNeqMacroTest2(Ishiko::Test& test);
    static void SkipMacroTest1(Ishiko::Test& test);
};

#endif
