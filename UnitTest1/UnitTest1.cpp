#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.3(rec).cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestFindFirstNonPositiveRow)
		{
			int n = 3;
			int** matrix = new int* [n];
			for (int i = 0; i < n; ++i) {
				matrix[i] = new int[n];
			}
			matrix[0][0] = -1; matrix[0][1] = -2; matrix[0][2] = -3;
			matrix[1][0] = 4; matrix[1][1] = 5; matrix[1][2] = 6;
			matrix[2][0] = 7; matrix[2][1] = -8; matrix[2][2] = 9;
			int result = FindFirstNonPositiveRow(matrix, n, n, 0);
			int expected = 0;
			Assert::AreEqual(expected, result);
			for (int i = 0; i < n; ++i) {
				delete[] matrix[i];
			}
			delete[] matrix;
		}
	};
}
