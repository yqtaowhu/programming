// Date   : 2016.09.04
// Author : yqtao
// https://github.com/yqtaowhu


/********************************************************************************** 
* 
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list, 
* only nodes itself can be changed.
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
 // beats 96.70% of cppsubmissions
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