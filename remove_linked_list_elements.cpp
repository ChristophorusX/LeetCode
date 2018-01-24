#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val) {
	ListNode* pre = head;
	ListNode* trueHead = head;
	if (head == NULL) {
		return NULL;
	}
	while (head->next != NULL) {
		if (head->val == val) {
			if (trueHead == head) {
				trueHead = trueHead->next;
				head = trueHead;
				pre = head;
			} else {
				pre->next = head->next;
				head = head->next;
			}
		} else {
			pre = head;
			head = head->next;
		}
	}
	if (head->val == val) {
		if (trueHead == head) {
			trueHead = NULL;
			head = NULL;
			pre = NULL;
		} else {
			pre->next = NULL;
		}
	}
	return trueHead;
}
