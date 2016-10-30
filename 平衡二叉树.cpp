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
     * @return: True if this Binary tree is Balanced, or false.
     */
     int height(TreeNode *root)
     {
         if(root==NULL)
            return 0;
         int lh = height(root->left);    
         int rh = height(root->right);    
         return lh > rh ? lh + 1 : rh + 1;    
     }
     bool isBalanced(TreeNode *root) {
        // write your code here
         if(root==NULL)
             return true;
         int lh = height(root->left);    
         int rh = height(root->right);    
         int result=(lh>rh?lh-rh:rh-lh);
         if(result>1)
            return false;
         return isBalanced(root->left) && isBalanced(root->right);  
    }
};
