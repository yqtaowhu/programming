// Date   : 2016.07.25
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
 * 
 * Follow up:
 * What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
 * How would you optimize the kthSmallest routine?
 * 
 *   Try to utilize the property of a BST.
 *   What if you could modify the BST node's structure?
 *   The optimal runtime complexity is O(height of BST).
 * 
 * Credits:Special thanks to @ts for adding this problem and creating all test cases.
 **********************************************************************************/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    // in-order travel - non-recursive way
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        stack<TreeNode*>st;
        while (root||st.size()>0) {
            if (root) {
                st.push(root);
                root=root->left;
            }
            else {
                if (st.size()>0) {
                    root=st.top();
                    st.pop();
                    result.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return result[k-1];
    }
};
