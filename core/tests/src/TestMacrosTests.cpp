// SPDX-FileCopyrightText: 2000-2024 Xavier Leclercq
// SPDX-License-Identifier: BSL-1.0

#include "TestMacrosTests.h"
#include "Ishiko/TestFramework/Core/TestMacros.hpp"
#include <Ishiko/TestFramework/Core/TestProgressObserver.hpp>
#include <Ishiko/BasePlatform.hpp>
#include <Ishiko/Text.hpp>
#include <sstream>

using namespace Ishiko;

TestMacrosTests::TestMacrosTests(const TestNumber& number, const TestContext& context)
    : TestSequence(number, "Test macros tests", context)
{
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_PASS test 1", PassMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL test 1", FailMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF test 1", FailIfMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF test 2", FailIfMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_NOT test 1", FailIfNotMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_NOT test 2", FailIfNotMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_EQ test 1", FailIfEqMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_EQ test 2", FailIfEqMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_NEQ test 1", FailIfNeqMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_NEQ test 2", FailIfNeqMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_STR_EQ test 1", FailIfStrEqMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_STR_EQ test 2", FailIfStrEqMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_STR_NEQ test 1", FailIfStrNeqMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_STR_NEQ test 2", FailIfStrNeqMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_NOT_CONTAIN test 1", FailIfNotContainMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_NOT_CONTAIN test 2", FailIfNotContainMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_HEAP_ALLOCATION_COUNT_NEQ test 1",
        FailIfHeapAllocationCountNeqTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_HEAP_ALLOCATION_COUNT_NEQ test 2",
        FailIfHeapAllocationCountNeqTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_HEAP_ALLOCATION_COUNT_NEQ test 3",
        FailIfHeapAllocationCountNeqTest3);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ test 1",
        FailIfOutputAndReferenceFilesNeqMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ test 2",
        FailIfOutputAndReferenceFilesNeqMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ test 3",
        FailIfOutputAndReferenceFilesNeqMacroTest3);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ test 4",
        FailIfOutputAndReferenceFilesNeqMacroTest4);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ test 5",
        FailIfOutputAndReferenceFilesNeqMacroTest5);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ test 6",
        FailIfOutputAndReferenceFilesNeqMacroTest6);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT test 1", AbortMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF test 1", AbortIfMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF test 2", AbortIfMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_NOT test 1", AbortIfNotMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_NOT test 2", AbortIfNotMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_EQ test 1", AbortIfEqMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_EQ test 2", AbortIfEqMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_NEQ test 1", AbortIfNeqMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_NEQ test 2", AbortIfNeqMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_STR_EQ test 1", AbortIfStrEqMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_STR_EQ test 2", AbortIfStrEqMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_STR_NEQ test 1", AbortIfStrNeqMacroTest1);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_ABORT_IF_STR_NEQ test 2", AbortIfStrNeqMacroTest2);
    append<HeapAllocationErrorsTest>("ISHIKO_TEST_SKIP test 1", SkipMacroTest1);
}

void TestMacrosTests::PassMacroTest1(Test& test)
{
    Test myTest(TestNumber(), "PassMacroTest1",
        [](Test& test)
        {
            ISHIKO_TEST_PASS();
        });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailMacroTest1",
        [&canary](Test& test)
        {
            ISHIKO_TEST_FAIL();

            canary = true;

            ISHIKO_TEST_PASS();
        });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfMacroTest1",
        [&canary](Test& test)
        {
            ISHIKO_TEST_FAIL_IF(false);

            canary = true;

            ISHIKO_TEST_PASS();
        });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfMacroTest2",
        [&canary](Test& test)
        {
            ISHIKO_TEST_FAIL_IF(true);

            canary = true;

            ISHIKO_TEST_PASS();
        });

    std::stringstream progressOutput;
    std::shared_ptr<TestProgressObserver> observer = std::make_shared<TestProgressObserver>(progressOutput);
    myTest.observers().add(observer);

    myTest.run();

    std::vector<std::string> progressOutputLines = ASCII::GetLines(progressOutput.str());

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_ABORT_IF_NEQ(progressOutputLines.size(), 3);
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[1],
        "ISHIKO_TEST_FAIL_IF(true) failed with actual value (true)");
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfNotMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfNotMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_NOT(true);

        canary = true;

        ISHIKO_TEST_PASS();
    });

    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfNotMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfNotMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_NOT(false);

        canary = true;

        ISHIKO_TEST_PASS();
    });

    std::stringstream progressOutput;
    std::shared_ptr<TestProgressObserver> observer = std::make_shared<TestProgressObserver>(progressOutput);
    myTest.observers().add(observer);

    myTest.run();

    std::vector<std::string> progressOutputLines = ASCII::GetLines(progressOutput.str());

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_ABORT_IF_NEQ(progressOutputLines.size(), 3);
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[1],
        "ISHIKO_TEST_FAIL_IF_NOT(false) failed with actual value (false)");
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfEqMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfEqMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_EQ(0, 1);

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfEqMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfEqMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_EQ(0, 0);

        canary = true;

        ISHIKO_TEST_PASS();
    });
    
    std::stringstream progressOutput;
    std::shared_ptr<TestProgressObserver> observer = std::make_shared<TestProgressObserver>(progressOutput);
    myTest.observers().add(observer);

    myTest.run();

    std::vector<std::string> progressOutputLines = ASCII::GetLines(progressOutput.str());

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_ABORT_IF_NEQ(progressOutputLines.size(), 3);
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[1],
        "ISHIKO_TEST_FAIL_IF_EQ(0, 0) failed with actual values (0, 0)");
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfNeqMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfNeqMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(0, 0);

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfNeqMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfNeqMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_NEQ(0, 1);

        canary = true;

        ISHIKO_TEST_PASS();
    });

    std::stringstream progressOutput;
    std::shared_ptr<TestProgressObserver> observer = std::make_shared<TestProgressObserver>(progressOutput);
    myTest.observers().add(observer);

    myTest.run();

    std::vector<std::string> progressOutputLines = ASCII::GetLines(progressOutput.str());

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_ABORT_IF_NEQ(progressOutputLines.size(), 3);
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[1],
        "ISHIKO_TEST_FAIL_IF_NEQ(0, 1) failed with actual values (0, 1)");
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfStrEqMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfStrEqMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_STR_EQ("a", "b");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfStrEqMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfStrEqMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_STR_EQ("a", "a");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfStrNeqMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfStrNeqMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_STR_NEQ("a", "a");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfStrNeqMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfStrNeqMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_STR_NEQ("a", "b");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfNotContainMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfNotContainMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_NOT_CONTAIN("abc", "b");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfNotContainMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfNotContainMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_NOT_CONTAIN("abc", "d");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfHeapAllocationCountNeqTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfHeapAllocationCountNeqTest1",
        [&canary](Test& test)
        {
            ISHIKO_TEST_FAIL_IF_HEAP_ALLOCATION_COUNT_NEQ(0);

            canary = true;

            ISHIKO_TEST_PASS();
        });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfHeapAllocationCountNeqTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "FailIfHeapAllocationCountNeqTest2",
        [&canary](Test& test)
        {
            int* allocation = new int(0);

            ISHIKO_TEST_FAIL_IF_HEAP_ALLOCATION_COUNT_NEQ(1);

            delete allocation;

            canary = true;

            ISHIKO_TEST_PASS();
        });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfHeapAllocationCountNeqTest3(Test& test)
{
#if !((ISHIKO_RUNTIME == ISHIKO_RUNTIME_MICROSOFT_CRT) && defined(_DEBUG))
    ISHIKO_TEST_SKIP();
#endif

    bool canary = false;
    Test myTest(TestNumber(), "FailIfHeapAllocationCountNeqTest3",
        [&canary](Test& test)
        {
            int* allocation = new int(0);

            ISHIKO_TEST_FAIL_IF_HEAP_ALLOCATION_COUNT_NEQ(0);

            delete allocation;

            canary = true;

            ISHIKO_TEST_PASS();
        });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfOutputAndReferenceFilesNeqMacroTest1(Test& test)
{
    bool canary = false;
    TestContext myTestContext;
    myTestContext.setOutputDirectory(test.context().getDataDirectory());
    myTestContext.setReferenceDirectory(test.context().getDataDirectory());
    Test myTest(TestNumber(), "FailIfOutputAndReferenceFilesNeqMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("ComparisonTestFiles/Hello.txt",
            "ComparisonTestFiles/Hello2.txt");

        canary = true;

        ISHIKO_TEST_PASS();
    },
        myTestContext);
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfOutputAndReferenceFilesNeqMacroTest2(Test& test)
{
    bool canary = false;
    TestContext myTestContext;
    myTestContext.setOutputDirectory(test.context().getDataDirectory());
    myTestContext.setReferenceDirectory(test.context().getDataDirectory());
    Test myTest(TestNumber(), "FailIfOutputAndReferenceFilesNeqMacroTest2",
        [&canary](Test& test)
        {
            ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("ComparisonTestFiles/Hello.txt",
                "ComparisonTestFiles/NotHello.txt");

            canary = true;

            ISHIKO_TEST_PASS();
        },
        myTestContext);

    std::stringstream progressOutput;
    std::shared_ptr<TestProgressObserver> observer = std::make_shared<TestProgressObserver>(progressOutput);
    myTest.observers().add(observer);

    myTest.run();

    std::vector<std::string> progressOutputLines = ASCII::GetLines(progressOutput.str());

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_ABORT_IF_NEQ(progressOutputLines.size(), 4);
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[0], " FailIfOutputAndReferenceFilesNeqMacroTest2 started");
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[1], "    Check failed ");
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[2], "    Check failed: Hello ");
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfOutputAndReferenceFilesNeqMacroTest3(Test& test)
{
    bool canary = false;
    TestContext myTestContext;
    myTestContext.setOutputDirectory(test.context().getDataDirectory());
    myTestContext.setReferenceDirectory(test.context().getDataDirectory());
    Test myTest(TestNumber(), "FailIfOutputAndReferenceFilesNeqMacroTest3",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("ComparisonTestFiles/NotExist",
            "ComparisonTestFiles/NotHello.txt");

        canary = true;

        ISHIKO_TEST_PASS();
    },
        myTestContext);

    std::stringstream progressOutput;
    std::shared_ptr<TestProgressObserver> observer = std::make_shared<TestProgressObserver>(progressOutput);
    myTest.observers().add(observer);

    myTest.run();

    std::vector<std::string> progressOutputLines = ASCII::GetLines(progressOutput.str());

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_ABORT_IF_NEQ(progressOutputLines.size(), 3);
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[0], " FailIfOutputAndReferenceFilesNeqMacroTest3 started");
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[1], "    Check failed: failed to open output file: ");
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfOutputAndReferenceFilesNeqMacroTest4(Test& test)
{
    bool canary = false;
    TestContext myTestContext;
    myTestContext.setOutputDirectory(test.context().getDataDirectory());
    myTestContext.setReferenceDirectory(test.context().getDataDirectory());
    Test myTest(TestNumber(), "FailIfOutputAndReferenceFilesNeqMacroTest4",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("ComparisonTestFiles/Hello.txt",
            "ComparisonTestFiles/NotExist");

        canary = true;

        ISHIKO_TEST_PASS();
    },
        myTestContext);

    std::stringstream progressOutput;
    std::shared_ptr<TestProgressObserver> observer = std::make_shared<TestProgressObserver>(progressOutput);
    myTest.observers().add(observer);

    myTest.run();

    std::vector<std::string> progressOutputLines = ASCII::GetLines(progressOutput.str());

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_ABORT_IF_NEQ(progressOutputLines.size(), 3);
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[0], " FailIfOutputAndReferenceFilesNeqMacroTest4 started");
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[1], "    Check failed: failed to open reference file: ");
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfOutputAndReferenceFilesNeqMacroTest5(Test& test)
{
    bool canary = false;
    TestContext myTestContext;
    myTestContext.setOutputDirectory(test.context().getDataDirectory());
    myTestContext.setReferenceDirectory(test.context().getDataDirectory());
    Test myTest(TestNumber(), "FailIfOutputAndReferenceFilesNeqMacroTest5",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("ComparisonTestFiles/Hello.txt",
            "ComparisonTestFiles/Hello3.txt");

        canary = true;

        ISHIKO_TEST_PASS();
    },
        myTestContext);
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::FailIfOutputAndReferenceFilesNeqMacroTest6(Test& test)
{
    bool canary = false;
    TestContext myTestContext;
    myTestContext.setOutputDirectory(test.context().getDataDirectory());
    myTestContext.setReferenceDirectory(test.context().getDataDirectory());
    Test myTest(TestNumber(), "FailIfOutputAndReferenceFilesNeqMacroTest6",
        [&canary](Test& test)
    {
        ISHIKO_TEST_FAIL_IF_OUTPUT_AND_REFERENCE_FILES_NEQ("ComparisonTestFiles/Hello.txt",
            "ComparisonTestFiles/NotHello2.txt");

        canary = true;

        ISHIKO_TEST_PASS();
    },
        myTestContext);

    std::stringstream progressOutput;
    std::shared_ptr<TestProgressObserver> observer = std::make_shared<TestProgressObserver>(progressOutput);
    myTest.observers().add(observer);

    myTest.run();

    std::vector<std::string> progressOutputLines = ASCII::GetLines(progressOutput.str());

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_ABORT_IF_NEQ(progressOutputLines.size(), 4);
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[0], " FailIfOutputAndReferenceFilesNeqMacroTest6 started");
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[1], "    Check failed ");
    ISHIKO_TEST_FAIL_IF_NOT_CONTAIN(progressOutputLines[2], "    Check failed: Hello ");
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortMacroTest1",
        [&canary](Test& test)
        {
            ISHIKO_TEST_ABORT();

            canary = true;

            ISHIKO_TEST_PASS();
        });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfMacroTest1",
        [&canary](Test& test)
        {
            ISHIKO_TEST_ABORT_IF(false);

            canary = true;

            ISHIKO_TEST_PASS();
        });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfMacroTest2",
        [&canary](Test& test)
        {
            ISHIKO_TEST_ABORT_IF(true);

            canary = true;

            ISHIKO_TEST_PASS();
        });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfNotMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfNotMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_NOT(true);

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfNotMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfNotMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_NOT(false);

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfEqMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfEqMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_EQ(0, 1);

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfEqMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfEqMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_EQ(0, 0);

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfNeqMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfNeqMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_NEQ(0, 0);

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfNeqMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfNeqMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_NEQ(0, 1);

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfStrEqMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfStrEqMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_STR_EQ("a", "b");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfStrEqMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfStrEqMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_STR_EQ("a", "a");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfStrNeqMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfStrNeqMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_STR_NEQ("a", "a");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::passed);
    ISHIKO_TEST_FAIL_IF_NOT(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::AbortIfStrNeqMacroTest2(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "AbortIfStrNeqMacroTest2",
        [&canary](Test& test)
    {
        ISHIKO_TEST_ABORT_IF_STR_NEQ("a", "b");

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::failed);
    ISHIKO_TEST_FAIL_IF(canary);
    ISHIKO_TEST_PASS();
}

void TestMacrosTests::SkipMacroTest1(Test& test)
{
    bool canary = false;
    Test myTest(TestNumber(), "TestMacrosTests_SkipMacroTest1",
        [&canary](Test& test)
    {
        ISHIKO_TEST_SKIP();

        canary = true;

        ISHIKO_TEST_PASS();
    });
    myTest.run();

    ISHIKO_TEST_FAIL_IF_NEQ(myTest.result(), TestResult::skipped);
    ISHIKO_TEST_FAIL_IF(canary);
    ISHIKO_TEST_PASS();
}
