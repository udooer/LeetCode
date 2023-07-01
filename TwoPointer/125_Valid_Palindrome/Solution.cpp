// 125. Valid Palindrome
/*
Thought:

1. using two pointer two check palindrome

Time complexity: O(n)
Space complexity: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int frontIndex = 0;
        int rearIndex = s.size() - 1;
        
        while(rearIndex > frontIndex)
        {
        	char frontChar = std::tolower(s[frontIndex]);
        	char rearChar = std::tolower(s[rearIndex]);
        	
        	if((frontChar >= 'a' && frontChar <= 'z') == false 
        	&& (frontChar >= '0' && frontChar <= '9') == false)
        	{
        		frontIndex++;
        		continue;
        	}
        	
        	if((rearChar >= 'a' && rearChar <= 'z') == false
        	&& (rearChar >= '0' && rearChar <= '9') == false)
        	{
        		rearIndex--;
        		continue;
        	}
        	
        	if(frontChar != rearChar)
        	{
        		return false;
        	}
        	
        	frontIndex++;
        	rearIndex--;
        }
        
        return true;
    }
};
