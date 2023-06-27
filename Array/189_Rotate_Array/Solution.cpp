// 189. Rotate Array
/*
Thought:

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution_01 {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1) 
        {
            return;
        }

        k = k % nums.size();
        for (int i = 0; i < k; i++) 
        {
            int tmp = nums[nums.size() - 1];
            for (int j = 0; j < nums.size(); j++)
            {
                swap(nums[j], tmp);
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = (k % nums.size() + nums.size()) % nums.size();
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};