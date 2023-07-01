// 49. Group Anagrams
/*
Thought:

Time complexity: O(nlogn)
Space complexity: O(n) 

1. construct a pair with index and string value 
2. sort all string first
3. then sort vector
4. then construct the return vector 
*/

class Solution_1 {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
			vector<std::pair<std::string, int>> pairs;
			pairs.reserve(strs.size());

			// make pair of (string, index)
			for(int i=0; i<strs.size(); i++)
			{
				pairs.push_back(std::make_pair(strs[i], i));
				// printf("%s, %d\n", strs[i].c_str(), i);
			}
			
			// sort string itself
			for(int i=0; i<pairs.size(); i++)
			{
				std::sort(pairs[i].first.begin(), pairs[i].first.end());  
			}

			/*for(int i=0; i<pairs.size(); i++)
			{
				printf("%s, %d\n", pairs[i].first.c_str(), pairs[i].second);
			}*/
			
			std::sort(pairs.begin(), pairs.end());
			
			std::vector<std::vector<std::string>> resultVec;
			
			std::string previousStr = pairs[0].first;
			std::vector<std::string> tmpVec;
			tmpVec.push_back(strs[pairs[0].second]);
			
			for(int i=1; i<pairs.size(); i++)
			{
				std::string currentStr = pairs[i].first;
				if(previousStr == currentStr)
				{
					tmpVec.push_back(strs[pairs[i].second]);
				}
				else
				{
					resultVec.push_back(tmpVec);
					previousStr = currentStr;
					tmpVec = std::vector<std::string>();
					tmpVec.push_back(strs[pairs[i].second]);
				}
			}
			
			if(tmpVec.size() != 0)
			{
				resultVec.push_back(tmpVec);
			}
		
			return resultVec;
    }
};


// 1. sort the string and using map to store origin string 
// 2. construct the return vector
// Time complexity: O(n)
// Space complexity: O(n)  
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	std::unordered_map<std::string, std::vector<std::string>> mp;
			
		for(auto str: strs)
		{
			std::string sortString = str;
			std::sort(sortString.begin(), sortString.end());
			mp[sortString].push_back(str);
		}
		
		std::vector<std::vector<std::string>> returnVec;
		returnVec.reserve(mp.size());
		
		for(auto x: mp)
		{
			returnVec.push_back(x.second);
		}
		
		return returnVec;
    }
};
