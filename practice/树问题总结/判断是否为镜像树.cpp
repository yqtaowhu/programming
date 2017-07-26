  
	// 此题和两个树是否一样的那题类似的思路
	// 递归
	bool help(TreeNode* p,TreeNode* q) {
        if (!p||!q) return p==q;
        return p->val==q->val&&help(p->left,q->right)&&help(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return help(root->left,root->right);
    }
	
	// 循环，用栈去实现
	bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> sk;
        sk.push(root->left);
        sk.push(root->right);
        
        TreeNode* pA, *pB;
        while(!sk.empty()) {
            pA = sk.top();
            sk.pop();
            pB = sk.top();
            sk.pop();
            
            if(!pA && !pB) continue;
            if(!pA || !pB) return false;
            if(pA->val != pB->val) return false;
            
            sk.push(pA->left);
            sk.push(pB->right);
            sk.push(pA->right);
            sk.push(pB->left);
        }
        
        return true;
    }
	