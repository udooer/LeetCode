// 129. Sum Root to Leaf Numbers

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
    int sumNumbers(TreeNode* root) 
    {
        if(root) ComputeSum(root, 0);

        return m_iSum;
    }

    void ComputeSum(TreeNode* node, int number)
    {
        if(node->left) ComputeSum(node->left, number*10 + node->val);
        if(node->right) ComputeSum(node->right, number*10 + node->val);

        if(node->left == nullptr
            && node->right == nullptr)
        {
            m_iSum += number*10 + node->val;
        }
    }

private:
    int m_iSum{0};
};