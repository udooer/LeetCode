// 173. Binary Search Tree Iterator


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

class BSTIterator 
{
public:
    BSTIterator(TreeNode* root) 
    {
        m_CurrentNode = ToLeftMost(root);
    }
    
    int next()
    {
        int val = m_CurrentNode->val;

        if(m_CurrentNode->right)
        {
        	m_CurrentNode = ToLeftMost(m_CurrentNode->right);
        }
        else
        {
        	if(m_TreeStack.empty())
        	{
        		m_CurrentNode = nullptr;
        	}
        	else
        	{
        		m_CurrentNode = m_TreeStack.top();
        		m_TreeStack.pop();
        	}
        }

        return val;
    }
    
    bool hasNext() 
    {
        return m_CurrentNode != nullptr;
    }

    TreeNode* ToLeftMost(TreeNode* node)
    {
    	while(node->left)
    	{
    		m_TreeStack.push(node);
    		node = node->left;
    	}

    	return node;
    }

private:
	TreeNode* m_CurrentNode;
	stack<TreeNode*> m_TreeStack;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */