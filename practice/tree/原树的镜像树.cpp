
   //题目链接https://www.nowcoder.com/ta/coding-interviews
   //1. 递归
   void Mirror(TreeNode *pRoot) {
		if (pRoot) {
            Mirror(pRoot->left);
            Mirror(pRoot->right);
            swap(pRoot->left,pRoot->right); //等价于下面三条
            //TreeNode* node = pRoot->left;
            //pRoot->left = pRoot->right;
            //pRoot->right = node;
        }
        return;
    }
	//2. 迭代
	 void Mirror(TreeNode *pRoot) {
		if (!pRoot) return;
        stack<TreeNode*> st;
        st.push(pRoot);
        while (st.size()>0) {
            pRoot = st.top();
            st.pop();
			swap(pRoot->left,pRoot->right);
            if (pRoot->left)
                st.push(pRoot->left);
            if (pRoot->right)
                st.push(pRoot->right);
        }
    }