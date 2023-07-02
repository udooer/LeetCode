// 1. Two Sum

/*
Thought: 

1. using hash table to solve it

Time complexity: O(n)
Space complexity: O(n) 
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	std::unordered_map<int, int> mp; 
    	
    	for(int i=0; i<nums.size(); i++)
    	{
    		int tar = target - nums[i];
    		
    		if(mp.count(tar))
    		{
    			return {mp[tar], i};
    		}
    		else
    		{
    			mp[nums[i]] = i;
    		}
    	}
    	
    	return {};
    }
};
