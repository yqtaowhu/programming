/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //第一种情况： 链表的头节点为低位
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        int carry=0;
        ListNode preHead(0),*cur=&preHead;
        while(l1||l2||carry) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a+b+carry;
            carry = sum/10;
            ListNode* nxt = new ListNode(sum%10);
            cur->next = nxt;
            cur = cur->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return preHead.next;
    }
};
//链表的头节点为高位
//1.将输入的链表反转，然后计算，方法略
//2.用栈去做此题
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>st1,st2;
        while(l1) {
            st1.push(l1->val);
            l1=l1->next;
        }
        while(l2) {
            st2.push(l2->val);
            l2=l2->next;
        }
        int sum=0;
        ListNode* list = new ListNode(0);
        while(!st1.empty()||!st2.empty()){
            if(!st1.empty()) {
                sum+=st1.top();
                st1.pop();
            }
            if(!st2.empty()){
                sum+=st2.top();
                st2.pop();
            }
            list->val=sum%10;
            ListNode* head = new ListNode(sum/10); //进位
            head->next=list;
            list = head;
            sum/=10;
        }
        return list->val==0 ? list->next:list;
    }
};