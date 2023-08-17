// 222. Count Complete Tree Nodes


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
    int countNodes(TreeNode* root) 
    {
        if(root == nullptr) return 0;
        int depth = computeDepth(root);
        TreeNode* node = root;
        int count = 1;

        while(node)
        {
        	if(node->left && node->right)
        	{
        		if(computeDepth(node->right) == --depth)
        		{
        			node = node->right;
        			count = count*2+1;
        		}
        		else
        		{
        			node = node->left;
        			count = count*2;
        		}
        	}
        	else
        	{
        		break;
        	}
        }

        if(node->left == nullptr && node->left == nullptr) return count;
       	else if(node->left && node->right == nullptr) return count*2;

        return count;
    }

private:
	int computeDepth(TreeNode* node)
	{
		int depth = 0;
		while(node->left)
		{
			depth++;
			node = node->left;
		}

		return depth;
	}
};