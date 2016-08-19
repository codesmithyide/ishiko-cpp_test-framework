/*
	Copyright (c) 2000-2015 Xavier Leclercq

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

#include "FunctionBasedTest.h"

namespace Ishiko
{
namespace TestFramework
{

FunctionBasedTest::FunctionBasedTest(const TestNumber& number, 
	                                 const std::string& name,
								     TestResult::EOutcome (*runFct)())
	: Test(number, name), m_runFctVoid(runFct), m_runFctTest(0)
{
}

FunctionBasedTest::FunctionBasedTest(const TestNumber& number,
									 const std::string& name,
									 TestResult::EOutcome (*runFct)(),
									 const TestEnvironment& environment)
	: Test(number, name, environment), m_runFctVoid(runFct), m_runFctTest(0)
{
}

FunctionBasedTest::FunctionBasedTest(const TestNumber& number,
		                             const std::string& name,
									 TestResult::EOutcome(*runFct)(Test& test))
	: Test(number, name), m_runFctVoid(0), m_runFctTest(runFct)
{
}

FunctionBasedTest::FunctionBasedTest(const TestNumber& number,
									 const std::string& name,
									 TestResult::EOutcome (*runFct)(Test& test),
									 const TestEnvironment& environment)
	: Test(number, name, environment), m_runFctVoid(0), m_runFctTest(runFct)
{
}

FunctionBasedTest::FunctionBasedTest(const std::string& name,
                                     TestResult::EOutcome(*runFct)(Test& test),
                                     TestSequence& parentSequence)
    : Test(TestNumber(), name, parentSequence.environment()), m_runFctTest(runFct)
{
    std::shared_ptr<Test> self(this);
    parentSequence.append(self);
}

FunctionBasedTest::~FunctionBasedTest() throw()
{
}

TestResult::EOutcome FunctionBasedTest::doRun(TestObserver::ptr& observer)
{
	if (m_runFctTest)
	{
		return m_runFctTest(*this);
	}
	else if (m_runFctVoid)
	{
		return m_runFctVoid();
	}
	else
	{
		return TestResult::eFailed;
	}
}

}
}
