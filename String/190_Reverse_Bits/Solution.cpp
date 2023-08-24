// 190. Reverse Bits

#include <stack>
using namespace std;
class SolutionV1 
{
public:
    uint32_t reverseBits(uint32_t n) 
    {
        if (n == 0) 
        {
            return 0;
        }

        stack<int> binaryStack;
        while (n) 
        {
            binaryStack.push(n % 2);
            n /= 2;
        }

        uint32_t ans = 0;
        uint32_t expon = pow(2, 32 - binaryStack.size());
        while (binaryStack.empty() == false) 
        {
            ans += expon * binaryStack.top();
            binaryStack.pop();
            expon *= 2;
        }

        return ans;
    }
};

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans;
        
        for (int i = 0; i < 32; i++) 
        {
            ans <<= 1;
            ans = ans | (n & 1);
            n >>= 1;
        }

        return ans;
    }
};