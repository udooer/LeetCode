// 228. Summary Ranges
/*
Thought: 

Time complexity: O(n)
space complexity: O(1)
*/

#include <sstream>

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> stringVec;

        if (nums.size() == 0) 
        {
            return stringVec;
        }

        int startInt = nums[0];
        int endInt = nums[0];
        
        for (int i = 1; i < nums.size(); i++) 
        {
            if (nums[i] == endInt + 1) 
            {
                endInt = nums[i];
            }
            else 
            {
                if (startInt == endInt) 
                {
                    std::stringstream ss;
                    ss << startInt;
                    stringVec.push_back(ss.str());
                }
                else 
                {
                    std::stringstream ss;
                    ss << startInt;
                    ss << "->";
                    ss << endInt;
                    stringVec.push_back(ss.str());
                }

                startInt = nums[i];
                endInt = nums[i];
            }
        }

        if (startInt == endInt)
        {
            std::stringstream ss;
            ss << startInt;
            stringVec.push_back(ss.str());
        }
        else
        {
            std::stringstream ss;
            ss << startInt;
            ss << "->";
            ss << endInt;
            stringVec.push_back(ss.str());
        }

        return stringVec;
    }
};