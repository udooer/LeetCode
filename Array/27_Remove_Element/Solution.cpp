// 27. Remove Element
/*
Thought:

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        // int numReturn = nums.size();
        int index = 0;

        for (auto num : nums)
        {
            if (num != val)
            {
                nums[index++] = num;
            }
        }

        return index;
    }
};