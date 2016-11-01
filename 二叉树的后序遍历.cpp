        vector<int> postSeq;
        stack<TreeNode *> s;
        if(root == NULL){
            return postSeq;
        }
        TreeNode *cur;
        s.push(root);
        TreeNode * pre = NULL;
        while(!s.empty())
        {
            cur = s.top();
            if((cur->left == NULL && cur->right == NULL)||(pre!=NULL)&&(pre == cur->left||pre == cur->right)){
                postSeq.push_back(cur->val);//cur栈顶元素为叶节点或者栈顶元素的左右节点已被访问过了，则直接访问栈顶元素
                pre = cur;
                s.pop();
            }else{
                if(cur->right != NULL){
                    s.push(cur->right);
                }
                if(cur->left != NULL){
                    s.push(cur->left);
                }
            }
        }
    }
