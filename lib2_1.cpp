#include <lib1.h>
#include <lib2.h>

int test() {
	printf("test() from Lib2\n");
	return 42;
}

namespace Lib2 {

bool& value(int index){
	static bool val[arraySize] = {false};
	return val[index];
}

struct Init0
{
	Init0() {
      		if (!Lib1::IsInit()) {
			// Валим gtest в abort
//			throw "Oops";
		}
		printf("Call Lib2::Init()\n");		
	}

	~Init0() {
		if (!Lib1::IsInit()) {
//			throw "Oops";
		}
		
		printf("Call Lib2::~Init()\n");
	}
};

static Init0 init;

static Init<1> init1 __attribute__((init_priority(102)));
static Init<4> init4;
static Init<3> init3 __attribute__((init_priority(5000)));

}

