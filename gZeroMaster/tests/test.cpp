#include "pch.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

int gB0ComPort;
int gNonB0ComPort;

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	if (argc < 3) {
		std::cout <<"usage: tests [B0 COM port#] [Non B0 COM port#]" << std::endl;
		return -1;
	}
	gB0ComPort = atoi(argv[1]);
	gNonB0ComPort = atoi(argv[2]);
	return RUN_ALL_TESTS();
}