// 217. Contains Duplicate
/*
Thought:

Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <map>
#include <unordered_map>
#include <iostream>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) 
    {
        bool isContainsDuplicate = false;
        std::unordered_map<int, int> intCount;
        
        for (int i = 0; i < nums.size(); i++) 
        {
            if (intCount.find(nums[i]) != intCount.end()) 
            {
                isContainsDuplicate = true;
                break;
            }

            intCount[nums[i]] = 1;
        }

        return isContainsDuplicate;
    }
};

void test() 
{
    std::unordered_map<int, int> uMap;
    auto a = uMap[1];
    std::cout << a;
}

int main() 
{
    test();
}