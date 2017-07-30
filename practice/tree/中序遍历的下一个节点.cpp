/****************************************************************************
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
********************************************************************************/

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
         TreeLinkNode *p=pNode;
        if (pNode->right) {               //当前节点有右子树
            p=pNode->right;
            while (p->left) p=p->left;
            return p;
        }
        else {                            //没有右子树，向上查找
			p=pNode->next;
            while (p) {
             	if (p->left==pNode) return p;  
                else {
                    pNode=p;
                    p=p->next;
                }
            }
            return nullptr;
        }
    }