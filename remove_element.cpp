#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	int length = nums.size();
	int t = 0;
	for (size_t i = 0; i < length - t; ) {
		if (nums[i] == val) {
			int temp = nums[length - t - 1];
			nums[length - t - 1] = nums[i];
			nums[i] = temp;
			t++;
		} else {
			i++;
		}
	}
	return length - t;
    }
