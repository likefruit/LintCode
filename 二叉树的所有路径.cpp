class Solution {
public:
	/**
	* @param root the root of the binary tree
	* @return all root-to-leaf paths
	*/
	vector<string> binaryTreePaths(TreeNode* root) {
		// Write your code here
		vector<string> res;
		if (root == NULL) return res;
		binaryTreePathsCore(root, res, to_string(root->val));
		return res;
	}

	void binaryTreePathsCore(TreeNode* root, vector<string> &str, string strpath)
	{
		if (root->left == NULL&&root->right == NULL)//叶子结点
		{
			str.push_back(strpath);
			return;
		}
		if (root->left != NULL)
			binaryTreePathsCore(root->left, str, strpath + "->" + to_string(root->left->val));
		if (root->right != NULL)
			binaryTreePathsCore(root->right, str, strpath + "->" + to_string(root->right->val));
	}

};
