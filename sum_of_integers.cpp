#include <iostream>
#include <vector>

using namespace std;

int numBits(int n) {
	int num = n;
	int count = 0;
	while (num != 0) {
		num >>= 1;
		count++;
	}
	return count;
}

int getSum(int a, int b) {
	if (a <= 0 && b <= 0) {
		return -(getPosSum(-a, -b));
	} else if (a > 0 && b > 0) {
		return getPosSum(a, b);
	} else if (a > 0 && b < 0) {
		//TODO
	}
}

int getPosSum(int a, int b) {
	int aBits = numBits(a);
	int bBits = numBits(b);
	cout << "aBits is " << aBits << ", and bBits is " << bBits << endl;
	vector<int> aInBin(aBits + 1);
	vector<int> bInBin(bBits + 1);
	aInBin[0] = 0;
	bInBin[0] = 0;
	for (size_t i = 0; i < aBits; i++) {
		aInBin[aBits - i] = a % 2;
		a >>= 1;
		cout << "a's decomposition is " << aInBin[aBits - i] << endl;
	}
	for (size_t j = 0; j < bBits; j++) {
		bInBin[bBits - j] = b % 2;
		b >>= 1;
		cout << "b's decomposition is " << bInBin[bBits - j] << endl;
	}
	for (size_t i = 0; i < aBits + 1; i++) {
		cout << "aBits are " << aInBin[i] << endl;
	}
	for (size_t i = 0; i < bBits + 1; i++) {
		cout << "bBits are " << bInBin[i] << endl;
	}
	int carry = 0;
	int sumBits, small, sign = 0;
	if (aBits >= bBits) {
		sumBits = aBits;
		small = bBits;
	} else {
		sumBits = bBits;
		small = aBits;
		sign = 1;
	}
	vector<int> sumInBin(sumBits + 1);
	for (size_t k = 0; k < sumBits; k++) {
		if (k >= small) {
			for (; k < sumBits; k++) {
				if (sign == 0) {
					if (carry == 0 && aInBin[sumBits - k] == 0) {
						sumInBin[sumBits - k] = 0;
						cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
					} else if (carry == 0) {
						sumInBin[sumBits - k] = 1;
						cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
					} else if (carry == 1 && aInBin[sumBits - k] == 0) {
						sumInBin[sumBits - k] = 1;
						cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
						carry = 0;
					} else {
						sumInBin[sumBits - k] = 0;
						cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
					}
				} else {
					if (carry == 0 && bInBin[sumBits - k] == 0) {
						sumInBin[sumBits - k] = 0;
						cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
					} else if (carry == 0) {
						sumInBin[sumBits - k] = 1;
						cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
					} else if (carry == 1 && bInBin[sumBits - k] == 0) {
						sumInBin[sumBits - k] = 1;
						cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
						carry = 0;
					} else {
						sumInBin[sumBits - k] = 0;
						cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
					}
				}
			}
			break;
		}
		if (aInBin[aBits - k] == 1 && bInBin[bBits - k] == 1) {
			if (carry == 0) {
				sumInBin[sumBits - k] = 0;
				cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
				carry = 1;
			} else {
				sumInBin[sumBits - k] = 1;
				cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
			}
		} else if (aInBin[aBits - k] == 0 && bInBin[bBits - k] == 0) {
			if (carry == 0) {
				sumInBin[sumBits - k] = 0;
				cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
			} else {
				sumInBin[sumBits - k] = 1;
				cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
				carry = 0;
			}
		} else {
			if (carry == 0) {
				sumInBin[sumBits - k] = 1;
				cout << "s's decomposition is >>>" << sumInBin[sumBits - k] << endl;
			} else {
				sumInBin[sumBits - k] = 0;
				cout << "s's decomposition is " << sumInBin[sumBits - k] << endl;
			}
		}
	}
	if (carry == 1) {
		sumInBin[0] = 1;
	}
	for (size_t i = 0; i < sumBits + 1; i++) {
		cout << "SumBits are " << sumInBin[i] << endl;
	}
	int sum = 0;
	for (size_t length = 0; length < sumBits + 1; length++) {
		sum <<= 1;
		sum += sumInBin[length];
		cout << "sum is processed as " << sum << endl;
	}
	return sum;

}


int main(int argc, char const *argv[]) {
	int a = 1;
	int b = 2;
	int sum = getSum(a, b);
	cout << "The sum is " << sum << endl;
	return 0;
}
