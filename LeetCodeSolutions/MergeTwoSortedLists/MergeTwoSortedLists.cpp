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