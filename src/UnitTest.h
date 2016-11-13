#ifndef UNIT_TEST_H
#define UNIT_TEST_H





#define TEST(cond) \
do {\
	if (!(cond)) {\
		success = false; os << "Test Failed [" << __FILE__ << ", " << __LINE__ << "]" << endl;\
	}\
}while(false)

//! used to make check that Moves contains the coordinates
#define CONTAINS(x, y ) TEST(Moves.find(Coordinate(x,y)) != Moves.end())
#endif

