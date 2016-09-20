// Date   : 2016.09.20
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Follow up for problem "Populating Next Right Pointers in Each Node".
* What if the given tree could be any binary tree? Would your previous solution still work?
* 
* Note:
* You may only use constant extra space.
* 
* For example,
* Given the following binary tree,
* 
*          1
*        /  \
*       2    3
*      / \    \
*     4   5    7
* 
* After calling your function, the tree should look like:
* 
*          1 -> NULL
*        /  \
*       2 -> 3 -> NULL
*      / \    \
*     4-> 5 -> 7 -> NULL
* 
*               
**********************************************************************************/
//O(1) SPACE
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *head=root,*pre=nullptr,*cur=nullptr;
        while (head) {
            cur=head;pre=nullptr;head=nullptr;
            while (cur) {
                if (cur->left) {
                    if (pre) pre->next=cur->left;
                    else head=cur->left;
                    pre=cur->left;
                }
                if (cur->right) {
                    if (pre) pre->next=cur->right;
                    else head=cur->right;
                    pre=cur->right;
                }
                cur=cur->next;
            }
        }
    }
};
