class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* root_result = new ListNode();

		int l1_val = l1->val;
		int l2_val = l2->val;
		int carry = 0, sum = l1_val + l2_val;
		carry = sum / 10;
		sum %= 10;

		ListNode* next_node_1 = l1->next;
		ListNode* next_node_2 = l2->next;

		root_result->val = sum;
		ListNode* old_result = root_result;
		while (next_node_1 || next_node_2 || carry != 0) {
			ListNode* new_result = new ListNode();
			old_result->next = new_result;

			l1_val = 0;
			l2_val = 0;
			if (next_node_1) {
				l1_val = next_node_1->val;
				next_node_1 = next_node_1->next;
			}
			if (next_node_2) {
				l2_val = next_node_2->val;
				next_node_2 = next_node_2->next;
			}

			sum = l1_val + l2_val + carry;
			carry = sum / 10;
			sum %= 10;

			new_result->val = sum;
			old_result = new_result;
		}
		return root_result;
	}
};