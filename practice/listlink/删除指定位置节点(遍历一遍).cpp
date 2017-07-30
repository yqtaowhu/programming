//删除从后往前的第n个节点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //遍历一遍
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode preHead(0);
        ListNode *p1=&preHead,*p2=&preHead;
        p1->next=head;
        for (int i=0;i<n;i++) {
            if (p2==nullptr) return nullptr;
            p2=p2->next;
        }
        while (p2->next) {
            p1=p1->next;
            p2=p2->next;
        }
        p1->next=p1->next->next;
        return preHead.next;
    }
};
//遍历两遍
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=0;
        ListNode* tmp=head;
        while (tmp) {
            len++;
            tmp=tmp->next;
        }
        ListNode preHead(0);
        ListNode *pre=&preHead;pre->next=head;
        for (int i=0;i<len-n;i++) 
            pre=pre->next;
        ListNode* nxt=pre->next;
        pre->next=nxt->next;
        delete nxt;
        return preHead.next;
    }
};