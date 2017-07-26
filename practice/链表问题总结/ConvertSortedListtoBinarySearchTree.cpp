/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //一定要明确的是递归的思路
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        ListNode *slow=head,*fast=head->next->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->next->val);
        root->right = sortedListToBST(slow->next->next);
        slow->next = nullptr;
        root->left = sortedListToBST(head);
        return root;
    }
};
