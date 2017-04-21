// Date   : 2016.09.25
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* A linked list is given such that each node contains an additional random pointer 
* which could point to any node in the list or null.
* 
* Return a deep copy of the list.
* 
*               
**********************************************************************************/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode *str = head;
 	RandomListNode *newNode = NULL;
	if (str == NULL)
		return NULL;
	while (str != NULL)	{
		RandomListNode *newNode = new RandomListNode(0);
		newNode->label = str->label;
		newNode->next = str->next;
		RandomListNode *temp = str->next;
		str->next = newNode;
		str = temp;
	}
	str = head;
	while (str) {
		str->next->random = str->random ? str->random->next : nullptr;
		str = str->next->next;
	}
	str = head;
	RandomListNode *temp = NULL;
	RandomListNode *newLink = str->next;
	newNode = str->next;
	while (str != NULL&&str->next != NULL) {
		temp = str->next;
		str->next = temp->next;
		temp->next = temp->next ? temp->next->next : nullptr;
		str = str->next;
	}
	return newLink;
    }
};
