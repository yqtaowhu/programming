// Date   : 2016.09.16
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* 
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
* 
*               
**********************************************************************************/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head||!head->next) return head;
        ListNode *cur=head;
        while (cur&&cur->next) {
            ListNode *nxt=cur->next;
            while (nxt&&(cur->val==nxt->val)) nxt=nxt->next;
            cur->next=nxt;
            cur=nxt;
        }
        return head;
    }
};

