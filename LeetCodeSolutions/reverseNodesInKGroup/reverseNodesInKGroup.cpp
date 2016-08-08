// Date   : 2016.08.08
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* 
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
* 
* You may not alter the values in the nodes, only nodes itself may be changed.
* 
* Only constant memory is allowed.
* 
* For example,
* Given this linked list: 1->2->3->4->5
* 
* For k = 2, you should return: 2->1->4->3->5
* 
* For k = 3, you should return: 3->2->1->4->5
* 
*               
**********************************************************************************/
ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || k == 1) return head;
        int listLen = 0;
        ListNode preHead(0);
        preHead.next = head;
        ListNode* cur = &preHead, *pre = &preHead, *next = NULL;
        while (cur = cur->next) listLen++;
        while (listLen >= k) {
            cur = pre->next;
            next = cur->next;
            for (int i = 0; i < k - 1; i++) {
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
                next = cur->next;
            }
            pre = cur;
            listLen -= k;
        }
        return preHead.next;
    }
