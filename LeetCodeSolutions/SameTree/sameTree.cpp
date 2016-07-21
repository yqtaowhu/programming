Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

##非常简单
1.如果p或q为空，如果同时为空则为真，否则为假
2.如果两者都不空，则为真的条件是当前根节点相等，并且递归的调用左子树和右子树。
```
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if (p == NULL || q == NULL) return (p == q);
       return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};
```