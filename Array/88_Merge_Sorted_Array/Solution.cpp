// 88. Merge Sorted Array
/* Thought:
Time complexity:  O(m+n)
Space complexity: O(1)

1. Two flag in both sorted array. 
2. Start from the back
*/ 

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if (n == 0 || m == 0) 
        {
            return;
        }

        int indexM = m - 1;
        int indexN = n - 1;
        int indexMerged = m + n - 1;
        
        while (indexM != -1 && indexN != -1) 
        {
            if (nums2[indexN] > nums1[indexM]) 
            {
                nums1[indexMerged--] = nums2[indexN--];
            }
            else 
            {
                nums1[indexMerged--] = nums1[indexM--];
            }
        }

        if (indexM == -1) 
        {
            for (int i = 0; i < indexN + 1; i++) 
            {
                nums1[i] = nums2[i];
            }
        }
    }
};