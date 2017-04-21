
/**********************************************************************************
*
* Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
*
* For example,
* Given n = 3, your program should return all 5 unique BST's shown below.
*
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
**********************************************************************************/
//递归方法解决
//I start by noting that 1..n is the in-order traversal for any BST with nodes 1 to n. 
//So if I pick i-th node as my root, the left subtree will contain elements 1 to (i-1), 
//and the right subtree will contain elements (i+1) to n.
//I use recursive calls to get back all possible trees for left and right subtrees 
//and combine them in all possible ways with the root.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> generateTrees(int low, int high);

vector<TreeNode*> generateTrees(int n) {
	
	vector<TreeNode*> v;
	if (n==0) return v;  //i find add this can ac ,if do not add it is return wrong.
	v = generateTrees(1, n);  
	return v;
}

vector<TreeNode*> generateTrees(int low, int high) {
	vector<TreeNode*> v;
	if (low > high || low <= 0 || high <= 0) {
		v.push_back(NULL);
		return v;
	}
	if (low == high) {
		TreeNode* node = new TreeNode(low);
		v.push_back(node);
		return v;
	}
	//the i is root,and construct the left subtree and right subtree.
	for (int i = low; i <= high; i++) {
		vector<TreeNode*> vleft = generateTrees(low, i - 1);
		vector<TreeNode*> vright = generateTrees(i + 1, high);
		for (int l = 0; l<vleft.size(); l++) {
			for (int r = 0; r<vright.size(); r++) {
				TreeNode *root = new TreeNode(i);
				root->left = vleft[l];
				root->right = vright[r];
				v.push_back(root);
			}
		}
	}
	return v;
}

void printTree(TreeNode *root) {
	if (root == NULL) {
		printf("# ");
		return;
	}
	printf("%d ", root->val);

	printTree(root->left);
	printTree(root->right);
}


int main(int argc, char** argv)
{
	int n = 2;
	vector<TreeNode*> v = generateTrees(n);
	for (int i = 0; i<v.size(); i++) {
		printTree(v[i]);
		printf("\n");
	}
	return 0;
}
