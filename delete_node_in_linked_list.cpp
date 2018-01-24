#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


void deleteNode(ListNode* node) {
	while ((node->next)->next != NULL) {
		node->val = (node->next)->val;
		node = node->next;
	}
	node->val = (node->next)->val;
	node->next = NULL;
}

int main(int argc, char const *argv[]) {
	/* code */
	return 0;
}
