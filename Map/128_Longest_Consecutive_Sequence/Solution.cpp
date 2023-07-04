// 128. Longest Consecutive Sequence
/*
Thought: 

1. loop through once to save all number in unordered_set
2. loop again to count longest consecutive sequence
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> numsSet;

        for (auto num : nums) 
        {
            numsSet.insert(num);
        }

        int maxSequenceCount = 0;
        for (auto num : nums) 
        {
            if (numsSet.count(num - 1)) 
            {
                continue;
            }

            int count = 0;
            while (numsSet.count(num++)) 
            {
                count++;
            }

            maxSequenceCount = max(maxSequenceCount, count);
        }

        return maxSequenceCount;
    }
};