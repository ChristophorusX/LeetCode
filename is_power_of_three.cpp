#include <iostream>
#include <vector>

using namespace std;

bool isPowerOfThree(int n) {
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	while (n % 3 == 0) {
		if (n == 0) {
			return 1;
		}
		n /= 3;
		if (n == 0) {
			return 1;
		}
	}
	return 0;
    }
