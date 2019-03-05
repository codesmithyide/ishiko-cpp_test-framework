/*
    Copyright (c) 2006-2019 Xavier Leclercq

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

#ifndef _ISHIKO_TESTFRAMEWORK_CORE_TESTHARNESS_H_
#define _ISHIKO_TESTFRAMEWORK_CORE_TESTHARNESS_H_

#include "TestApplicationReturnCodes.h"
#include "TestConfiguration.h"
#include "TestSequence.h"
#include "TopTestSequence.h"
#include "TestProgressObserver.h"
#include <string>

namespace Ishiko
{
namespace Tests
{

class TestHarnessBase
{
public:
	explicit TestHarnessBase(const std::string& title);
	virtual ~TestHarnessBase();

	int run();

	TestEnvironment& environment();

	TestSequence& tests();

protected:
	int runTests();

private:
	TestEnvironment m_environment;
    TopTestSequence m_topSequence;
};

}
}

namespace Ishiko
{
namespace Tests
{

typedef TestHarnessBase TestHarness;

}
}

#endif
