// 55. Jump Game
/*
Thought:
Accumulate the max jump from start

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        
        for (int i = 0; i <= maxReach; i++)
        {
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= nums.size() - 1) 
            {
                return true;
            }
        }

        return false;
    }
};