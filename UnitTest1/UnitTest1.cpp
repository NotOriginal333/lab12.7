#include "pch.h"
#include "CppUnitTest.h"
#include "../lab12.7/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            StudentList list;
            list.addStudent("Smith", 4.5, 1000);
            list.addStudent("Johnson", 3.9, 0);
            list.addStudent("Williams", 4.2, 800);
            list.addStudent("Jones", 3.7, 0);

            list.removeStudentsWithoutScholarship();

			Assert::IsNull(list.findStudentsByGrade(3.9).getHead());
			Assert::IsNull(list.findStudentsByGrade(3.7).getHead());
		}
	};
}
