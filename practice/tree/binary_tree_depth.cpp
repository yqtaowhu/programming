
//1. binary tree depth recusive
	int TreeDepth(TreeNode* pRoot){
    	return pRoot ? max(TreeDepth(pRoot->left),TreeDepth(pRoot->right)) + 1 : 0;
	}

//2.loop traversal

 int TreeDepth(TreeNode* pRoot) {
        if (!pRoot) return 0;
        queue<TreeNode*> que;
        que.push(pRoot);int depth=0;
        while (!que.empty()) {
            int size=que.size();
            depth++;
            for (int i=0;i<size;i++) {      //一次处理一层的数据
                TreeNode *node=que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return depth;
    }
 
 
 //1.min depth of tree ,this mean root->left && root->right nullptr,this is left node 
 
  int minDepth(TreeNode* root) {
        if(!root)  return 0;
        if(root->left && root->right)  //判断是否为叶子节点
            return min(minDepth(root->left),minDepth(root->right))+1;
        else      
            return max(minDepth(root->left),minDepth(root->right))+1;
    }
//2. loop travesal
	  int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> que;
        int depth = 0;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            depth++;
            for (int i=0;i<size;i++) {
                root = que.front();
                que.pop();
                if (root->left==nullptr&&root->right==nullptr)
                    return depth;
                if (root->left)
                    que.push(root->left);
                if (root->right)
                    que.push(root->right);
            }
        }
        return depth;
    }
