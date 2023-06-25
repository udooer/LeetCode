// 26. Remove Duplicates from Sorted Array
/*
Thought:
Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int index = 0;
        int number = -101;

        for (auto num : nums) 
        {
            if (num != number) 
            {
                nums[index++] = num;
                number = num;
            }
        }

        return index;
    }
};