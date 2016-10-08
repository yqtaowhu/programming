// Date   : 2016.10.08
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.
 *               
 **********************************************************************************/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head==NULL) return NULL;
        ListNode preHead(0),*pre=&preHead;
        preHead.next=head;
        ListNode *cur=pre->next;
        while (cur) {
            ListNode *nxt=cur->next;
            if (cur->val==val) {
                pre->next=nxt;
                cur=nxt;
            }
            else {
                pre=cur;
                cur=nxt;
            }
        }
        return preHead.next;
    }
};


