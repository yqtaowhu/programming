class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next) return false;
        ListNode* slow=head,*fast=head;
        while(fast&&fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
//如有环，找出入口节点
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while (fast&&fast->next) {
            fast=fast->next->next;
            slow=slow->next;
            if (slow==fast) {
                slow=head;
                while (slow!=fast) {
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};