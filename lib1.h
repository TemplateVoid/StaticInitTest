#pragma once
#define LIB1_API __attribute__((visibility("default")))
namespace Lib1 {
	LIB1_API bool IsInit();
}
