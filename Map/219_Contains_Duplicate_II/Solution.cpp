// 219. Contains Duplicate II
/*
Thought: using hash map to store int value and index
Time complexity: O(n)
Space complexity: O(n)
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.count(nums[i]))
            {
                if (k >= i - mp[nums[i]])
                {
                    return true;
                }
                else
                {
                    mp[nums[i]] = i;
                }
            }
            else 
            {
                mp[nums[i]] = i;
            }
        }

        return false;
    }
};

