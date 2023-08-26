// 230. Kth Smallest Element in a BST

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

class Solution 
{
public:
    int kthSmallest(TreeNode* root, int k) 
    {
    	m_remainNode = k;

        inorderTraverse(root);

        return m_kthVal;
    }

private:
	int m_remainNode;
	int m_kthVal{0};

	void inorderTraverse(TreeNode* root)
	{
		if(root->left) inorderTraverse(root->left);

        m_remainNode -= 1;
        if(m_remainNode <= 0)
        {
            if(m_remainNode == 0) m_kthVal = root->val;
        	return;
        } 

        if(root->right) inorderTraverse(root->right);
	}
};