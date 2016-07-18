// Author : yqtao
// Date   : 2016-7-3
// Email  : yqtao@whu.edu.cn
/**********************************************************************************
*
* Merge two sorted linked lists and return it as a new list.The new list should be
* made by splicing together the nodes of the first two lists.
*
********************************************************************************** /

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//
//Dummy is there to store a pointer to the new head of the list.Tail starts off as what will be the head, 
//but it changes, so dummy stores the pointer to the head.
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode dummy(INT_MIN);
		ListNode *tail = &dummy;

		while (l1 && l2) {
			if (l1->val < l2->val) {
				tail->next = l1;
				l1 = l1->next;
			}
			else {
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}

		tail->next = l1 ? l1 : l2;
		return dummy.next;
	}
};