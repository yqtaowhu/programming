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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode preHead(0);
        ListNode* pre=&preHead;
        while (l1&&l2) {
            if (l1->val<l2->val) {
                pre->next=l1;
                l1=l1->next;
            }
            else {
                pre->next=l2;
                l2=l2->next;
            }
            pre=pre->next;
        }
        pre->next=l1 ? l1 : l2;
        return preHead.next;
    }
};
//多个有序链表
class Solution {
public:
	//合并两个表
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		const size_t k = lists.size();
		if (k == 0) return NULL;
		if (k == 1) return lists[0];
		for (size_t i = 1; i < k; i = i * 2) 
			for (size_t j = 0; j < k - i; j += i * 2)
				lists[j] = mergeTwoLists(lists[j], lists[i + j]);
		return lists[0];
	}
};