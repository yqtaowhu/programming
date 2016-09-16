// Date   : 2016.09.16
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a sorted linked list, delete all nodes that have duplicate numbers, 
* leaving only distinct numbers from the original list.
* 
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
* 
*               
**********************************************************************************/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head||!head->next) return head;
        ListNode preHead(0),*pre=&preHead,*cur=head;
        preHead.next=head;
        while (cur&&cur->next) {
            ListNode *nxt=cur->next;
            if (cur->val==nxt->val) {
                while(nxt&&cur->val==nxt->val) nxt=nxt->next;
                pre->next=nxt;
                cur=nxt;
            }
            else {
                pre=pre->next;
                cur=cur->next;
            }
        }
        return preHead.next;
    }
};

