#include <lib1.h>
#include <cstdio>
namespace Lib1 {

struct Init
{
	Init(): val( 42 ) {
      		printf("Call Lib1::Init()\n");
	}

	~Init() {
		val = -1;
		printf("Call Lib1::~Init()\n");
	}

	int val;
};

static Init init;


bool IsInit() 
{
	return init.val == 42;
}
}
