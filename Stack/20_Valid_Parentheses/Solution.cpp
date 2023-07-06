// 20. Valid Parentheses
/*
Thought: using stack to check

Time complexity: O(n)
Space complexity: O(n)
*/

#include <stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> parenthesesStack;

        for (auto c : s) 
        {
            if (c == '(' || c == '[' || c == '{') 
            {
                parenthesesStack.push(c);
            }
            else 
            {
                if (parenthesesStack.empty()) 
                {
                    return false;
                }

                char cCheck = parenthesesStack.top();
                parenthesesStack.pop();
                switch (c) 
                {
                case ')':
                    if (cCheck != '(') 
                    {
                        return false;
                    }
                    break;
                case ']':
                    if (cCheck != '[')
                    {
                        return false;
                    }
                    break;
                case '}':
                    if (cCheck != '{')
                    {
                        return false;
                    }
                    break;
                }
            }
        }

        return parenthesesStack.empty() ? true : false;
    }
};