// Date   : 2016.09.19
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*               
**********************************************************************************/
class Solution {
public:
        TreeNode* sortedArrayToBST(vector<int>& nums) {
            return help(nums, 0, nums.size()-1);
        }
    
        TreeNode* help(vector<int> &nums, int start, int end){
            if (start>end) return nullptr;
            int mid=(start+end)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            root->left=help(nums, start, mid-1);
            root->right=help(nums, mid+1, end);
            return root;
        }
};
