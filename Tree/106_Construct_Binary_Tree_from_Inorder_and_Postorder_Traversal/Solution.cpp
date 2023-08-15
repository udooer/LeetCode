// 106. Construct Binary Tree from Inorder and Postorder Traversal

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

#include<unordered_map>
using namespace std;

class Solution_V1
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for(int i=0;i<inorder.size();i++)
        {
            m_inorderValToIndexMap[inorder[i]] = i;
        }

        for(int i=0;i<postorder.size();i++)
        {
            m_postorderValToIndexMap[postorder[i]] = i;
        }

        return ConstructTree(inorder, postorder, 0, 0, postorder.size()-1);
    }

    TreeNode* ConstructTree(vector<int>& inorder, vector<int>& postorder,int inLeft, int postLeft, int postRight)
    {
        if(postLeft > postRight) return nullptr;
        // printf("inLeft: %d, postLeft: %d, postRight: %d", inLeft, postLeft, postRight);

        int nodeVal = postorder[postRight];
        TreeNode* node = new TreeNode(nodeVal);

        int maxIndex = -1;
        for(int i=inLeft; i<m_inorderValToIndexMap[nodeVal];i++)
        {
            if(m_postorderValToIndexMap[inorder[i]] > maxIndex)
            {
                maxIndex = m_postorderValToIndexMap[inorder[i]];
            }
        }

        if(maxIndex == -1)
        {
            node->right = ConstructTree(inorder, postorder, m_inorderValToIndexMap[nodeVal]+1, postLeft, postRight-1);
        }
        else
        {
            node->left = ConstructTree(inorder, postorder, inLeft, postLeft, maxIndex);
            node->right = ConstructTree(inorder, postorder, m_inorderValToIndexMap[nodeVal]+1, maxIndex+1, postRight-1);
        }
        
        return node;
    }

private:
    unordered_map<int, int> m_inorderValToIndexMap;
    unordered_map<int, int> m_postorderValToIndexMap;
};

class Solution 
{
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for(int i=0;i<inorder.size();i++)
        {
            m_inorderValToIndexMap[inorder[i]] = i;
        }

        m_postOrderIndex = postorder.size()-1;

        return ConstructTree(inorder, postorder, 0, inorder.size()-1);
    }

    TreeNode* ConstructTree(vector<int>& inorder, vector<int>& postorder,int inLeft, int inRight)
    {
        if(inLeft > inRight) return nullptr;

        int postVal = postorder[m_postOrderIndex];
        TreeNode* node = new TreeNode(postVal);
        m_postOrderIndex--;

        node->right = ConstructTree(inorder, postorder, m_inorderValToIndexMap[postVal]+1, inRight);
        node->left = ConstructTree(inorder, postorder, inLeft, m_inorderValToIndexMap[postVal]-1);
        
        return node;
    }

private:
    unordered_map<int, int> m_inorderValToIndexMap;
    int m_postOrderIndex;
};
