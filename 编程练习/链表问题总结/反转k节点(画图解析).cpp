

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head||!head->next||k<=1) return head;
        int len=0;
        ListNode preHead(0),*pre=&preHead;pre->next=head;
        ListNode* p=head,*cur=head;
        while(p){
            len++;
            p=p->next;
        }
        for (int i=0;i<=len-k;i+=k){
            for(int j=0;j<k-1;j++) {
                ListNode* nxt=cur->next;
                cur->next=nxt->next;
                nxt->next=pre->next;
                pre->next=nxt;
            }
            pre=cur;                      //for循环后才改变pre,cur的指向
            cur=cur->next;
        }
        return preHead.next;
    }
};