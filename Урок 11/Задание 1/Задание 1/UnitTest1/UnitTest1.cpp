#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Netology GIT tasks\Урок 11\Задание 1\Задание 1\Задание 1\ExtendedArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest {
	TEST_CLASS(ExtendedArrayTest) {
public:
    TEST_METHOD(EmptyArrayMean) {
        ExtArray<int> empty(0);
        Assert::AreEqual(0.0, empty.mean());
    }

    TEST_METHOD(EmptyArrayMedian) {
        ExtArray<double> empty = {};
        Assert::AreEqual(0.0, empty.median());
    }

    TEST_METHOD(EmptyArrayMode) {
        ExtArray<int> empty(0);
        auto result = empty.mode();
        Assert::AreEqual(0, result.first);
        Assert::AreEqual(0, result.second);
    }
	};
}