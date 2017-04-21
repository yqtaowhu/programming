// Author : yqtao
// Date   : 2016-09-13
// Email  : yqtao@whu.edu.cn

/********************************************************************************** 
* 
* Given a list, rotate the list to the right by k places, where k is non-negative.
* 
* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
*               
**********************************************************************************/
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
       if (!head||k<=0) return head;
       ListNode *p=head;int len=1;
       while (p->next) {     //count the length
           len++;            
           p=p->next;        //notice:p is the last node ,but not NULL
       }
       p->next=head;
       k=len-k%len; //find the new head
       for (int i=0;i<k;i++) 
           p=p->next;
        head=p->next;
        p->next=NULL;
        return head;
    }
};
