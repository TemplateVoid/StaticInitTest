#pragma once

#include <cstdio>

#define LIB2_API __attribute__((visibility("default")))

extern "C" {
	LIB2_API int test();
}

namespace Lib2 {

constexpr int arraySize = 5;

bool &value( int index );

template<int N>
struct Init {
	Init() {
		for (int i = 0; i < arraySize; ++i) {
			if ((i < N && !value(i)) || (i >= N && value(i))) {
//				throw "Oops";
			}
		}
		printf("Call Lib2::Init<%i>()\n", N);
		value(N) = true;
	}
	~Init() {
		for (int i = 0; i < arraySize; ++i) {
			if ((i <= N  && !value(i)) || (i > N && value(i))) {
//				throw "Oops";
			}
		}
		printf("Call Lib2::~Init<%i>()\n", N);
		value(N) = false;
	}
};

}

