#include <iostream>
#include <vector>

using namespace std;

int minSubarrayLength(int s, std::vector<int>& nums) {
	int vectorSize = nums.size();
	vector<vector<int> > table(2, vector<int>(vectorSize + 1));
	for (size_t i = 1; i < vectorSize + 1; i++) {
		for (size_t j = 0; j < vectorSize - i + 1; j++) {
			int sum = 0;
			if (i == 1) {
				sum = nums.at(j);
				cout << "i = 1, j = " << j << ", and sum = " << sum << endl;
			} else if (j == 0) {
				if (i % 2 != 0) {
					sum = table[0][j] + nums.at(i - 1);
				} else {
					sum = table[1][j] + nums.at(i - 1);
				}
				cout << "i = " << i << ", j = 0, and sum = " << sum << endl;
			} else {
				if (i % 2 != 0) {
					sum = table[1][j - 1] - nums.at(j - 1) + nums.at(i + j - 1);
				} else {
					sum = table[0][j - 1] - nums.at(j - 1) + nums.at(i + j - 1);
				}
				cout << "i = " << i << ", j = " << j << ", and sum = " << sum << endl;
			}
			if (i % 2 != 0) {
				table[1][j] = sum;
			} else {
				table[0][j] = sum;
			}
			if (sum >= s) {
				return i;
			}
		}
	}
	return 0;
}

int main(int argc, char const *argv[]) {
	vector<int> generatedNums;
	int array[] = {3,5,1,6,4,7,2,4,8,3,6,3,7,4,6,4,7,4,7,4,7,4,7,9,7,4,7,4,7,4,7,4,7};
	generatedNums.insert(generatedNums.begin(), array, array + 29);
	int answer = minSubarrayLength(55, generatedNums);
	cout << "The answer is: " << answer << endl;
	return 0;
}
