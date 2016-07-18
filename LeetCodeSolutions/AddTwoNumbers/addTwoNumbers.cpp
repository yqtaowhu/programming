// Author : yqtao
// Date   : 2016-7-3
// Email  : yqtao@whu.edu.cn
/******************************************************************************************************************
*You are given two linked lists representing two non-negative numbers. 
*The digits are stored in reverse order and each of their nodes contain a single digit. 
*Add the two numbers and return it as a linked list.
*
*Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
*Output: 7 -> 0 -> 8
*******************************************************************************************************************/
#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode preHead(0), *p = &preHead;//preHead is a ListNode,p is point to preHead;
	int carry = 0;
	while (l1 || l2 || carry) {
		int v1 = l1 ? l1->val : 0; //if l1==null,v1=0;
		int v2 = l2 ? l2->val : 0;
		int sum = v1 + v2 + carry;
		carry= sum / 10;
		p->next = new ListNode(sum % 10);
		p = p->next;
		l1 = l1 ? l1->next : l1;
		l2 = l2 ? l2->next : l2;
	}
	return preHead.next;  //return a pointer;
}
//test
int main()
{
	ListNode *p1 = new ListNode(2); ListNode *p2 = new ListNode(4); ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(5); ListNode *p5 = new ListNode(6); ListNode *p6 = new ListNode(4);
	p1->next = p2; p2->next = p3; p3->next = nullptr;
	p4->next = p5; p5->next = p6; p6->next = nullptr;
	ListNode* result = addTwoNumbers(p1, p4);
	while (result)
	{
		cout << result->val << " ";
		result = result->next;
	}
}