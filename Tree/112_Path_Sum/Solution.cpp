// 112. Path Sum


// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
    	if(root == nullptr) return false;

    	hasPathSumR(root, targetSum);

    	return m_blHasPathSum;
    }

    void hasPathSumR(TreeNode* node, int targetSum) 
    {
        // printf("node val: %d, targetVal: %d\n", node->val, targetSum);
    	if(node->left) hasPathSumR(node->left, targetSum - node->val);
    	if(node->right) hasPathSumR(node->right, targetSum - node->val);

    	if(node->left == nullptr && node->right == nullptr)
    	{
    		if(targetSum == node->val)
    		{
    			m_blHasPathSum = true;
    			return;
    		}
    	}
    }

private:
	bool m_blHasPathSum{false};
};