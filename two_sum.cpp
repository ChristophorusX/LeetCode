#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
	int length = nums.size();
	vector<int> answer(2);
	for (size_t i = 0; i < length - 1; i++) {
		for (size_t j = i + 1; j < length; j++) {
			if (nums[i] + nums[j] == target) {
				answer.at(0) = i;
				answer.at(1) = j;
				return answer;
			}
		}
	}
	return answer;
}

int main(int argc, char const *argv[]) {
	int array[] = {2, 7, 12, 5, 7, 9};
	vector<int> numbers;
	numbers.insert(numbers.begin(), array, array + 6);
	int target = 9;
	vector<int> answer = twoSum(numbers, target);
	cout << "The output answer is " << answer[0] << ", " << answer[1] << endl;
	return 0;
}
