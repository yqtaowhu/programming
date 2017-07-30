
/****************************************************************************
find next node of inordertravel 
********************************************************************************/

TreeLinkNode* GetNext(TreeLinkNode* pNode) {
       TreeLinkNode *p=pNode;
	   //if node have right node
       if (pNode->right) {              
            p=pNode->right;
            while (p->left) p=p->left;
            return p;
        }
        else {                           
			p=pNode->next;
			//remember conditional
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
