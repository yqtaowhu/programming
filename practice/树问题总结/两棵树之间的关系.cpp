
问题1: 给定两棵树，判断是不是一样的树

	// 递归
	bool isSameTree(TreeNode* p, TreeNode* q) {
       if (p == NULL || q == NULL) return (p == q);   //终止条件
	   // 当前值，左子树，右子树三个条件同时满足是返回真
        return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
	
	

问题2： 一颗树是否为另一颗的子结构，规定空树不是任意个树的子结构
	bool HasSubtree(TreeNode* p1, TreeNode* p2) {
        if(p1==NULL||p2==NULL) return false;
        return Hbtree(p1,p2);
    }
	//先遍历P1,知道值相同一起遍历
    bool Hbtree(TreeNode* p1, TreeNode* p2){
        if(p2==NULL) return true;
        if(p1==NULL) return false;
        if(p1->val==p2->val){
             if(Hbtree(p1->left,p2->left)&&Hbtree(p1->right,p2->right)) return true;
        }
        return Hbtree(p1->left,p2)||Hbtree(p1->right,p2);    
    }
