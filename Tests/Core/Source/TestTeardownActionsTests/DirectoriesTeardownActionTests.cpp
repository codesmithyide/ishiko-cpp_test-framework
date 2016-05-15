/*
	Copyright (c) 2015 Xavier Leclercq

	Permission is hereby granted, free of charge, to any person obtaining a
	copy of this software and associated documentation files (the "Software"),
	to deal in the Software without restriction, including without limitation
	the rights to use, copy, modify, merge, publish, distribute, sublicense,
	and/or sell copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
	THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
	IN THE SOFTWARE.
*/

#include "DirectoriesTeardownActionTests.h"
#include <boost/filesystem.hpp>

void AddDirectoriesTeardownActionTests(Ishiko::TestFramework::TestSequence& testSequence)
{
	Ishiko::TestFramework::TestSequence* directoriesTeardownTestSequence = 
		new Ishiko::TestFramework::TestSequence("DirectoriesTeardownAction tests", testSequence);

	new Ishiko::TestFramework::HeapAllocationErrorsTest("Creation test 1",
		DirectoriesTeardownActionCreationTest1, *directoriesTeardownTestSequence);

	new Ishiko::TestFramework::HeapAllocationErrorsTest("run test 1",
		DirectoriesTeardownActionRunTest1, *directoriesTeardownTestSequence);
}

Ishiko::TestFramework::TestResult::EOutcome DirectoriesTeardownActionCreationTest1()
{
	Ishiko::TestFramework::DirectoriesTeardownAction action;
	return Ishiko::TestFramework::TestResult::ePassed;
}

Ishiko::TestFramework::TestResult::EOutcome DirectoriesTeardownActionRunTest1Helper(Ishiko::TestFramework::Test& test)
{
	const char* path = "../../TestOutput/TestTeardownActionsTests/DirectoriesTeardownActionRunTest1";
	std::shared_ptr<Ishiko::TestFramework::DirectoriesTeardownAction> action =
		std::make_shared<Ishiko::TestFramework::DirectoriesTeardownAction>();
	action->add(path);
	test.addTeardownAction(action);

	if (boost::filesystem::create_directories(path))
	{
		return Ishiko::TestFramework::TestResult::ePassed;
	}
	else
	{
		return Ishiko::TestFramework::TestResult::eFailed;
	}
}

Ishiko::TestFramework::TestResult::EOutcome DirectoriesTeardownActionRunTest1()
{
	const char* path = "../../TestOutput/TestTeardownActionsTests/DirectoriesTeardownActionRunTest1";

	Ishiko::TestFramework::FunctionBasedTest test(Ishiko::TestFramework::TestNumber(),
		"DirectoriesTeardownActionRunTest1", DirectoriesTeardownActionRunTest1Helper);
	test.run();

	if (!boost::filesystem::exists(path) && test.passed())
	{
		return Ishiko::TestFramework::TestResult::ePassed;
	}
	else
	{
		return Ishiko::TestFramework::TestResult::eFailed;
	}
}