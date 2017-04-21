// Date   : 2016.08.06
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* 
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
* 
* return 1->4->3->2->5->NULL.
* 
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
* 
*               
**********************************************************************************/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m==n) return head;
        ListNode preHead(0),*pre=&preHead;
        preHead.next=head;
        for (int i=0;i<m-1;i++)
            pre=pre->next;
        ListNode *cur=pre->next;
        for (int i=0;i<n-m;i++) {
            ListNode *nxt=cur->next;
            cur->next=nxt->next;
            nxt->next=pre->next;
            pre->next=nxt;
        }
        return preHead.next;
    }
};
