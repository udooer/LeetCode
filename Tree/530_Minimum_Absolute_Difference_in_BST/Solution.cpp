// 530. Minimum Absolute Difference in BST


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

#include <stack>
using namespace std;

class SolutionV1
{
public:
    int getMinimumDifference(TreeNode* root) 
    {
    	int minDiffernece = 100000 + 1;
        TreeNode* currentNode = ToLeftMost(root);
        int currentVal = currentNode->val;

        while(true)
        {
        	currentNode = inOrderNext(currentNode);
        	if(currentNode == nullptr)
        	{
        		break;
        	}

        	if(currentNode->val - currentVal < minDiffernece)
        	{
        		minDiffernece = currentNode->val - currentVal;
        	}

        	currentVal = currentNode->val;
        }

        return minDiffernece;
    }

private:
	stack<TreeNode*> parentStack;

	TreeNode* ToLeftMost(TreeNode* node)
	{
		while(node->left)
		{
			parentStack.push(node);
			node = node->left;
		}

		return node;
	}

	TreeNode* inOrderNext(TreeNode* node)
	{
		if(node->right)
		{
			return ToLeftMost(node->right);
		}

		if(parentStack.empty() == false)
		{
			TreeNode* tmp = parentStack.top();
			parentStack.pop();
			return tmp;
		}

		return nullptr;
	}
};

class Solution 
{
public:
    int getMinimumDifference(TreeNode* root) 
    {
    	int minDiffernece = 100000 + 1;

    	inOrderTraverse(root);

    	return m_minDifference;
    }

private:
	bool m_blIsFirst{true};
	int m_minDifference{100000 + 1};
	int m_currentVal;

	void inOrderTraverse(TreeNode* node)
	{
		if(node->left) inOrderTraverse(node->left);
		if(m_blIsFirst)
		{
			m_currentVal = node->val;
			m_blIsFirst = false;
		}
		else
		{
			if(node->val - m_currentVal < m_minDifference) m_minDifference = node->val - m_currentVal;
			m_currentVal = node->val;
		}
		if(node->right) inOrderTraverse(node->right);
	}
};