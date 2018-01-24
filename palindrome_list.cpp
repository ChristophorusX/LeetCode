#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
		vector<int> copy(50000);
		int index = 0;
		while (head != NULL) {
			copy[index] = head->val;
			index++;
			head = head->next;
		}
		for (size_t i = 0; i < index; i++) {
			if (copy[i] != copy[index - i - 1]) {
				return 0;
			}
		}
		return 1;
    }
};
