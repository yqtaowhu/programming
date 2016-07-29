// Date   : 2016.07.29
// Author : yqtao
// https://github.com/yqtaowhu


/********************************************************************************** 
* 
* Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
* An example is the root-to-leaf path 1->2->3 which represents the number 123.
* 
* Find the total sum of all root-to-leaf numbers.
* 
* For example,
* 
*     1
*    / \
*   2   3
* 
* The root-to-leaf path 1->2 represents the number 12.
* The root-to-leaf path 1->3 represents the number 13.
* 
* Return the sum = 12 + 13 = 25.
* 
*               
**********************************************************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //solution 1,copy others way
class Solution {
public:
    int sumNumbers(TreeNode *root) {
    
        if (!root) return 0;
        
        int sum = 0;       
        vector<TreeNode*> v;
        v.push_back(root);
        while(v.size()>0){
            TreeNode* node = v.back();
            v.pop_back();
            if (node->left){
                node->left->val += (10*node->val); 
                v.push_back(node->left);
            }
            if (node->right){
                node->right->val += (10*node->val); 
                v.push_back(node->right);
            }
            if(!node->right && !node->left){
                sum += node->val;
            }
        }
        
        return sum;
    }
};
//solution 2，my way,i think i am vety low ,haha,but it can ac this problem ,
//and it can very easy to understand;
class Solution {
public:
    void dfs(TreeNode* root,string s) {
        s+=to_string(root->val);
        if (!root->left&&!root->right) {
            TreePaths.push_back(s);
        }
        else {
            if (root->left)
                dfs(root->left,s);
            if (root->right)
                dfs(root->right,s);
        }
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        dfs(root,"");
        int total=0;
        for (int i=0;i<TreePaths.size();i++) {
            int temp=0;
            for (int j=0;j<TreePaths[i].size();j++)
                temp=10*temp+(TreePaths[i][j]-'0');
            total+=temp;
        }
        return total;
    }
private:
    vector<string> TreePaths;    
};