#include "pch.h"
#include "CppUnitTest.h"
#include "../PR5.1B/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT23
{
	TEST_CLASS(UT23)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Money t(1, 1), f(1, 1);

			Assert::AreEqual(t.GetHrn(), f.GetHrn());
		}
	};
}