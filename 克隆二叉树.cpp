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
     * @param root: The root of binary tree
     * @return root of new tree
     */
    TreeNode* cloneTree(TreeNode *root) {
        // Write your code here
      if(NULL==root) return NULL;
      TreeNode* temp=new TreeNode(root->val);
      temp->left=cloneTree(root->left);
      temp->right=cloneTree(root->right);
      
      return temp;     
    }
};
