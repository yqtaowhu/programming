
//Given 1->2->3->4, you should return the list as 2->1->4->3.
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode preHead(0);
        ListNode *pre=&preHead,*cur=head;
        pre->next=head;
        while (cur&&cur->next) {
            ListNode* nxt=cur->next;
            cur->next=nxt->next;
            nxt->next=pre->next;
            pre->next=nxt;
            pre=cur;
            cur=cur->next;
        }
        return preHead.next;
    }
};