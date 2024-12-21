#include "pch.h"
#include "sum_array.h"
#include "sum_array_dynamic.h"
#include <vector>

// Test 1: Static Library, Small Array
TEST(StaticLibraryTest, SmallArray) {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    ASSERT_EQ(sumArray(numbers, 2), 15);
}

// Test 2: Static Library, Large Array
TEST(StaticLibraryTest, LargeArray) {
    std::vector<int> numbers(1000, 1); // Array of 1000 elements, all 1
    ASSERT_EQ(sumArray(numbers, 4), 1000);
}

// Test 3: Dynamic Library, Small Array
TEST(DynamicLibraryTest, SmallArray) {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    ASSERT_EQ(sumArrayD(numbers, 3), 15);
}

// Test 4: Dynamic Library, Large Array
TEST(DynamicLibraryTest, LargeArray) {
    std::vector<int> numbers(10000, 2); // Array of 10000 elements, all 2
    ASSERT_EQ(sumArrayD(numbers, 8), 20000);
}
