vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> result;
        if (!pRoot) return result;
        queue<TreeNode*> que;que.push(pRoot);
        int leftToRight;
        while (!que.empty()) {
            int size=que.size();vector<int> v(size);
            for (int i=0;i<size;i++) {
                TreeNode* node=que.front();
                que.pop();
                int index=leftToRight ? i : (size-i-1);
                v[index]=node->val;
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            result.push_back(v);
            leftToRight=!leftToRight;
        }
        return result;
    } 