/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
//i非递归
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
 vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> postSeq;
        stack<TreeNode *> s;
        if(root == NULL)
        {
            return postSeq;
        }
        s.push(root);
        TreeNode *cur=NULL;
        TreeNode *pre = NULL;
        while(!s.empty())
        {
            cur=s.top();
            if(cur->left==NULL&&cur->right==NULL||(pre!=NULL)&&(cur->left==pre||cur->right==pre))
            {
                //当一个结点是叶子结点或者左右结点都没有被访问过的时候出栈
                postSeq.push_back(cur->val);
                pre=cur;
                s.pop();
            }
            else{
                if(cur->right!=NULL)
                    s.push(cur->right);
                if(cur->left!=NULL)
                    s.push(cur->left);
            }
           
        }
            return postSeq;
 }          
};

//递归
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
 vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        post(root,result);   
        return result;
 }       
        void post(TreeNode *root,vector<int> &result)
        {
            if(root!=NULL)
            {
                post(root->left,result);
                post(root->right,result);
                result.push_back(root->val);
            }
        }
};
