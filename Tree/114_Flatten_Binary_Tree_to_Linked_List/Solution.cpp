// 114. Flatten Binary Tree to Linked List

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root) preOrder(root);

        TreeNode* node = root;
        for(int i=1;i<m_preOrderVec.size();i++)
        {
        	node->left = nullptr;
        	node->right = m_preOrderVec[i];
        	node = m_preOrderVec[i];
        }
    }

    void preOrder(TreeNode* node)
    {
    	m_preOrderVec.push_back(node);
    	if(node->left) preOrder(node->left);
    	if(node->right) preOrder(node->right);
    }

private:
	vector<TreeNode*> m_preOrderVec;
};