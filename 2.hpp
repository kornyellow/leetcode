class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* rootResult = new ListNode();

		int l1Val = l1->val;
		int l2Val = l2->val;
		int carry = 0, sum = l1Val + l2Val;
		carry = sum / 10;
		sum %= 10;

		ListNode* nextNode1 = l1->next;
		ListNode* nextNode2 = l2->next;

		rootResult->val = sum;
		ListNode* oldResult = rootResult;
		while (nextNode1 || nextNode2 || carry != 0) {
			ListNode* newResult = new ListNode();
			oldResult->next = newResult;

			l1Val = 0;
			l2Val = 0;
			if (nextNode1) {
				l1Val = nextNode1->val;
				nextNode1 = nextNode1->next;
			}
			if (nextNode2) {
				l2Val = nextNode2->val;
				nextNode2 = nextNode2->next;
			}

			sum = l1Val + l2Val + carry;
			carry = sum / 10;
			sum %= 10;

			newResult->val = sum;
			oldResult = newResult;
		}
		return rootResult;
	}
};