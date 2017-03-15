

// 直接中序遍历
TreeNode* KthNode(TreeNode* pRoot, unsigned int k) {
        if (pRoot==nullptr||k<0) return nullptr;
        stack<TreeNode*> st;int count=0;
        while (pRoot||!st.empty()) {
            if (pRoot) {
                st.push(pRoot);
                pRoot=pRoot->left;
            }
            else {
                pRoot=st.top();
                st.pop();
                if (++count==k) return pRoot;
                pRoot=pRoot->right;
            }
        }
        return nullptr;
    }