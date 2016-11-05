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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
         TreeNode *temp=NULL;
        // write your code here
    if(root!=NULL){
      if(root->left!=NULL)
        {
            temp=root->left;
            while(temp->right!=NULL)
                temp=temp->right;
                
           temp->right=root->right;
            root->right=root->left;
            root->left=NULL;
        }
        flatten(root->left);
        flatten(root->right);
    }
       
    }

};

