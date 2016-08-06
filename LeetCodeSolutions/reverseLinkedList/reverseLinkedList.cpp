// Date   : 2016.08.06
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Reverse a singly linked list.
 * 
 * click to show more hints.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 
 *               
 **********************************************************************************/


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
    ListNode* reverseList(ListNode* head) {
        if (head==NULL||head->next==NULL)
            return head;
        ListNode *pre=head;ListNode *cur=pre->next;
        pre->next=NULL;
        while (cur) {
            ListNode *nxt=cur->next;
            cur->next=pre;
            pre=cur;
            cur=nxt;
        }
        return pre;
    }
};
