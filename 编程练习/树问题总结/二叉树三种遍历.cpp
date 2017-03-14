vector<int> result;
//中序递归，前序，后序递归类似，不再重复
vector<int> InoderTraversal(binaryTreeNode* root)
{
    if (root != nullptr)
    {
        if (root->m_pLeft != nullptr)
            InoderTraversal(root->m_pLeft);
        result.push_back(root->m_nValue);
        if (root->m_pRight != nullptr)
            InoderTraversal(root->m_pRight);
    }
    return result;
}
//循环
vector<int> InoderTraversal1(binaryTreeNode* root)
{
    stack<binaryTreeNode*>stack;
    vector<int>v;
    while (stack.size() > 0||root!=nullptr)
    {
        if (root != nullptr)
        {
            stack.push(root);
            root = root->m_pLeft;
        }
        else
        {
            if (stack.size()>0)
            {
                root = stack.top();//获得尾指针
                stack.pop();
                v.push_back(root->m_nValue);
                root = root->m_pRight;
            }
        }   
    }
    return v;
}


//循环,同样可以用栈实现
vector<int> PreoderTraversal1(binaryTreeNode *root)
{
    vector<int> v;
    vector<binaryTreeNode*> stack;
    if (root) {
        stack.push_back(root);
    }
    while (stack.size()>0) {
        binaryTreeNode* n = stack.back();
        v.push_back(n->m_nValue);
        stack.pop_back();
        if (n->m_pRight) {                //注意顺序
            stack.push_back(n->m_pRight);
        }
        if (n->m_pLeft) {
            stack.push_back(n->m_pLeft);
        }
    }
    return v;
}
// We have two methods here.
//   1) the first one acutally is pre-order but reversed the access order.
//   2) the second one is the traditional one 
vector<int> PostoderTraversal1(binaryTreeNode *root) {
    vector<int> v;
    vector<binaryTreeNode*> stack;
    if (root) {
        stack.push_back(root);
    }
    while (stack.size()>0) {
        binaryTreeNode *n = stack.back();
        stack.pop_back();
        v.push_back(n->m_nValue);
        if (n->m_pLeft) {
            stack.push_back(n->m_pLeft);
        }
        if (n->m_pRight) {
            stack.push_back(n->m_pRight);
        }
    }
    std::reverse(v.begin(), v.end());  // the trick
    return v;
}
// traditional and standard way.
// using the stack to simulate the recursive function stack.
vector<int>  PostoderTraversal2(binaryTreeNode *root) {
    vector<int> v;
    vector<binaryTreeNode*> stack;
    binaryTreeNode *node = root;
    binaryTreeNode *lastVisitNode = NULL;
    while (stack.size()>0 || node != NULL) {

        if (node != NULL) {
            // keep going the left
            stack.push_back(node);
            node = node->m_pLeft;
        }
        else {
            binaryTreeNode *n = stack.back();
            // left way is finsised, keep going to the right way
            if (n->m_pRight != NULL && lastVisitNode != n->m_pRight) {
                node = n->m_pRight;
            }
            else {
                // both left and right has been accessed.
                stack.pop_back();
                v.push_back(n->m_nValue);
                lastVisitNode = n;
            }
        }
    }
    return v;
}