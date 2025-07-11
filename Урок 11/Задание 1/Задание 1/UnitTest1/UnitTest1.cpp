#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Netology GIT tasks\Урок 11\Задание 1\Задание 1\Задание 1\ExtendedArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExtendedArrayTests
{
    TEST_CLASS(ExtendedArrayTest)
    {
    public:


        TEST_METHOD(TestMeanFullArray)
        {
            ExtArray<int> arr{ 1, 2, 3, 4, 5 };
            Assert::AreEqual(3.0, arr.mean());
        }

        TEST_METHOD(TestMeanRangeValid)
        {
            ExtArray<int> arr{ 1, 2, 3, 4, 5 };
            Assert::AreEqual(3.5, arr.mean(1, 5)); 
            Assert::AreEqual(1.5, arr.mean(0, 2)); 
        }

        TEST_METHOD(TestMeanRangeInvalid)
        {
            ExtArray<int> arr{ 1, 2, 3 };

            auto func1 = [&arr]() { arr.mean(2, 2); };
            Assert::ExpectException<std::invalid_argument>(func1);

            auto func2 = [&arr]() { arr.mean(3, 1); };
            Assert::ExpectException<std::invalid_argument>(func2);

            auto func3 = [&arr]() { arr.mean(0, 4); };
            Assert::ExpectException<std::out_of_range>(func3);
        }

        TEST_METHOD(TestMeanEmptyArray)
        {
            ExtArray<int> arr(0);
            Assert::AreEqual(0.0, arr.mean());

            auto func = [&arr]() { arr.mean(0, 0); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestMedian)
        {
            ExtArray<double> arr{ 1.5, 2.5, 3.5, 4.5 };
            Assert::AreEqual(3.0, arr.median());
        }

        TEST_METHOD(TestMode)
        {
            ExtArray<int> arr{ 1, 2, 2, 3, 3, 3 };
            auto result = arr.mode();
            Assert::AreEqual(3, result.first);
            Assert::AreEqual(3, result.second);
        }

        TEST_METHOD(CheckSumBoolArray)
        {
            ExtArray<bool> arr{ true, false, true, true, false };
            Assert::AreEqual(static_cast<size_t>(3), arr.checkSum());
        }

        TEST_METHOD(CheckSumIntArrayValid)
        {
            ExtArray<int> arr{ 1, 0, 1, 1, 0, 1 };
            Assert::AreEqual(static_cast<size_t>(4), arr.checkSum());
        }

        TEST_METHOD(CheckSumIntArrayInvalid)
        {
            ExtArray<int> arr{ 1, 0, 2, 1 };

            auto func = [&arr]() { arr.checkSum(); };
            Assert::ExpectException<std::logic_error>(func);
        }

        TEST_METHOD(CheckSumWrongType)
        {
            ExtArray<double> arr{ 1.0, 0.0, 1.0 };

            auto func = [&arr]() { arr.checkSum(); };
            Assert::ExpectException<std::bad_typeid>(func);
        }

        TEST_METHOD(CheckSumEmptyArray)
        {
            ExtArray<bool> empty_bool(0);
            Assert::AreEqual(static_cast<size_t>(0), empty_bool.checkSum());

            ExtArray<int> empty_int(0);
            Assert::AreEqual(static_cast<size_t>(0), empty_int.checkSum());
        }
    };
}