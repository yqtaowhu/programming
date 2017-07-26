
/*************************************************************
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
***************************************************************/
//中序遍历的套路
TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree || (!pRootOfTree->left && !pRootOfTree->right))  return pRootOfTree;
        stack<TreeNode*> st;
        TreeNode* p=pRootOfTree,*last=NULL;
        bool isFirst=true;
        while (p||!st.empty()) {
            if(p) {
				st.push(p);p=p->left;
            }
            else {
            	p=st.top();
            	st.pop();
            	if (isFirst) {
                	pRootOfTree=p;
                	last=pRootOfTree;
                	isFirst=false;
            	}
            	else {
					last->right=p;
                	p->left=last;
                	last=p;
           		 }
           	    p=p->right;
        	}
        }
        return pRootOfTree;
    }