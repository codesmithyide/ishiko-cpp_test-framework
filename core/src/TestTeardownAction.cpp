/*
    Copyright (c) 2015-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/tests/blob/main/LICENSE.txt
*/

#include "TestTeardownAction.hpp"

namespace Ishiko
{
namespace Tests
{

TestTeardownAction::TestTeardownAction()
{
}

TestTeardownAction::~TestTeardownAction()
{
}

void TestTeardownAction::teardown()
{
    // Default implementation does nothing
}

}
}
