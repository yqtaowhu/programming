//  Date   :2016.07.22
//  Author :qytao
//  https://github.com/yqtaowhu
/**********************************************************************************
*
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
*
* For example, this binary tree is symmetric:
*
*     1
*    / \
*   2   2
*  / \ / \
* 3  4 4  3
*
* But the following is not:
*
*     1
*    / \
*   2   2
*    \   \
*    3    3
*
* Note:
* Bonus points if you could solve it both recursively and iteratively.
*
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*
* OJ's Binary Tree Serialization:
*
* The serialization of a binary tree follows a level order traversal, where '#' signifies
* a path terminator where no node exists below.
*
* Here's an example:
*
*    1
*   / \
*  2   3
*     /
*    4
*     \
*      5
*
* The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
*
*
**********************************************************************************/
//we have two ways to solve this problems
//first rescure  递归方法,与判断是否是同一颗树非常相似。
class Solution {
public:
	bool isSymmetric(TreeNode *p, TreeNode *q) {
		if (p == NULL && q == NULL) return true;
		if (p == NULL || q == NULL) return false;

		return (p->val == q->val) &&
			isSymmetric(p->left, q->right) &&
			isSymmetric(p->right, q->left);
	}
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return isSymmetric(root->left, root->right);
	}
};

//the next solutions iterative solution
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		stack<TreeNode*> sk;
		sk.push(root->left);
		sk.push(root->right);

		TreeNode* pA, *pB;
		while (!sk.empty()) {
			pA = sk.top();
			sk.pop();
			pB = sk.top();
			sk.pop();

			if (!pA && !pB) continue;
			if (!pA || !pB) return false;
			if (pA->val != pB->val) return false;

			sk.push(pA->left);
			sk.push(pB->right);
			sk.push(pA->right);
			sk.push(pB->left);
		}

		return true;
	}
};