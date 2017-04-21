// Date   : 2016.09.19
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given a singly linked list where elements are sorted in ascending order, 
* convert it to a height balanced BST.
*               
**********************************************************************************/
//the first solution ,just using a array to restore list ,and convert array to bst tree
class Solution {
public:
    TreeNode* help(vector<int> &nums, int start, int end){
            if (start>end) return nullptr;
            int mid=(start+end)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            root->left=help(nums, start, mid-1);
            root->right=help(nums, mid+1, end);
            return root;
        }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        if(!head) return nullptr;
        while (head) {
            nums.push_back(head->val);
            head=head->next;
        }
        return help(nums,0,nums.size()-1);
    }
};
//another way,it little difficult to understand,it O(1)space
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        ListNode *fast = head->next->next, *slow = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->next->val);
        root->right = sortedListToBST(slow->next->next);
        slow->next = NULL;
        root->left = sortedListToBST(head);
        return root;
    }
};
