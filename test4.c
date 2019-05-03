//将两个有序链表合并为一个有序链表并返回
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	struct ListNode* result = NULL;
	struct ListNode* last = NULL;
	while (l1&&l2) {
		if (l1->val<l2->val) {
			if (result == NULL) {
				result = l1;
				last = l1;
			}
			else {
				last->next = l1;
				last = last->next;
			}
			l1 = l1->next;
		}
		else {
			if (result == NULL) {
				result = l2;
				last = l2;
			}
			else {
				last->next = l2;
				last = last->next;
			}
			l2 = l2->next;
		}
	}
	if (l1) {
		last->next = l1;
	}
	if (l2) {
		last->next = l2;
	}
	return result;
}

