// 169. Majority Element
/*
Thought:

Time Complextiy: O(n/2)
Space Complexity: O(n/2)
*/

#include <unordered_map>

class Solution_01 {
public:
    int majorityElement(vector<int>& nums) 
    {
        std::unordered_map<int, int> uMap;

        for (auto num : nums) 
        {
            uMap[num]++;

            if (uMap[num] > (nums.size() / 2)) 
            {
                return num;
            }
        }

        return -1;
    }
};

// Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int count = 0;
        int candidate = nums[0];

        for (auto num : nums)
        {
            if (count == 0)
            {
                candidate = num;
            }

            if (candidate != num)
            {
                count--;
            }
            else
            {
                count++;
            }
        }

        return candidate;
    }
};