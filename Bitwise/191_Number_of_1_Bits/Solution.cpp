// 191. Number of 1 Bits

class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        if (n == 0) return 0;

        int count = 0;
        for (int i = 0; i < 32; i++) 
        {
            if (n & 1 == 1) count++;
            n >>= 1;
        }

        return count;
    }
};