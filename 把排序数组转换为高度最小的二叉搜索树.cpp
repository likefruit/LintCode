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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        if(0==A.size()) return NULL;
        TreeNode *root=NULL;
        create(root,A,0,A.size());
        return root;
        
    }
    void create(TreeNode *&root,vector<int> &A,int begin,int end)
    {
        if(begin<end)
        {
            int mid;
            mid=(begin+end)/2;
            root=new TreeNode(A[mid]);
            create(root->left,A,begin,mid);
            create(root->right,A,mid+1,end);
        }
        
    }
    
};


