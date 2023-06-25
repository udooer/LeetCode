// 80. Remove Duplicates from Sorted Array II
/*
Thought:

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int number = -10001;
        int count = 0;
        int index = 0;

        for (auto num : nums) 
        {
            if (number != num) 
            {
                number = num;
                count = 0;
                nums[index++] = num;
            }
            else if (number == num && count == 0) 
            {
                count++;
                nums[index++] = num;
            }
        }

        return index;
    }
};