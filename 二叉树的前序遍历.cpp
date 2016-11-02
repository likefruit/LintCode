//非递归
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        if(root==NULL) return result;
        stack<TreeNode *> s;
        TreeNode *temp=root;
        while(temp!=NULL)
        {
            result.push_back(temp->val);
            s.push(temp);
            temp=temp->left;
        }
        while(!s.empty())
        {
            temp=s.top()->right;
            s.pop();
            while(temp!=NULL)
            {
                result.push_back(temp->val);
                s.push(temp);
                temp=temp->left;
            }
            
        }
        
        return result;
        
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> result;
        preorder(root,result);
        return result;
        
    }
    void preorder(TreeNode *root,vector<int> &result)
    {
        if(root!=NULL)
        {
            result.push_back(root->val);
            preorder(root->left,result);
            preorder(root->right,result);
        }
    }
};
