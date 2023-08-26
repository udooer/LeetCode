// 236. Lowest Common Ancestor of a Binary Tree
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
    	if(root == nullptr)
    	{
    		return nullptr;
    	}
    	if(root.val == p.val || root.val == q.val)
    	{
    		return root;
    	}

    	TreeNode* leftAncestor = lowestCommonAncestor(root->left, p, q);
    	TreeNode* rightAncestor = lowestCommonAncestor(root->right, p, q);

    	if(leftAncestor == nullptr) return rightAncestor;
    	if(rightAncestor == nullptr) return leftAncestor;

    	return root;
    }
};
