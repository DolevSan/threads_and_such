#include "pch.h"
#include "assignment1.h"

int amount = 0;

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestSharedPrint, TestRun) {
	std::thread t1(function_1);

	for (int i = 0; i < 100; i++) {
		shared_print(string("From main: "), i);
		amount = i;
	}

	t1.join();


	EXPECT_EQ(amount, 99);
	EXPECT_TRUE(true);
}