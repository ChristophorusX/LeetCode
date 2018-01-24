#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
		int guessN = n / 2;
		int upper = n;
		int lower = 0;
		int result = guess(guessN);
		while (guessN != (upper - 1) || lower != guessN) {
			if (result == 1) {
				lower = guessN;
				guessN = (lower + upper) / 2;
				result = guess(guessN);
				if (result == 0) {
					return guessN;
				}
			} else {
				upper = guessN;
				guessN = (lower + upper) / 2;
				result = guess(guessN);
				if (result == 0) {
					return guessN;
				}
			}
		}
		return upper;
    }
};
