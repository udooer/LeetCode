// 66. Plus One
/*
Thought: 

1. reverse the array and add it, then reverse back

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int carry = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            carry = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
            
            if (carry == 0) 
            {
                break;
            }
        }

        if (carry) 
        {
            digits.push_back(1);
        }

        reverse(digits.begin(), digits.end());
        return digits;
    }
};