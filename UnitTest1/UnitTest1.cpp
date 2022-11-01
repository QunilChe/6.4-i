#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4-i/6.4-i.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62
{
	TEST_CLASS(UnitTest62)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int s[1] = { 1 };
			int t;
			t = Sum(s, 1);
			Assert::AreEqual(t, 1);

		}
	};
}
