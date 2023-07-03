// 202. Happy Number
/*
Thought: using hash map to keep all existence of number in mind

Time complexity:
Space complexity:
*/

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> numberSet;

        numberSet.insert(n);
        int tmpNumber = n;
        while (true) 
        {
            int addResult = 0;
            while (tmpNumber != 0) 
            {
                addResult += (tmpNumber % 10) * (tmpNumber % 10);
                tmpNumber /= 10;
            }

            if (addResult == 1) 
            {
                return true;
            }
            else if (numberSet.count(addResult)) 
            {
                return false;
            }
            else 
            {
                numberSet.insert(addResult);
                tmpNumber = addResult;
            }
        }
    }
};

// Floyd's Cycle-Finding
class Solution {
public:

    int square_sum(int n) 
    {
        int tmpNumber = n;
        int addResult = 0;
        while (tmpNumber != 0)
        {
            addResult += (tmpNumber % 10) * (tmpNumber % 10);
            tmpNumber /= 10;
        }

        return addResult;
    }

    bool isHappy(int n) {
        
        int tortoise = n;
        int hare = n;
        while (true)
        {
            tortoise = square_sum(tortoise);
            hare = square_sum(square_sum(hare));
            
            if (tortoise == 1)
            {
                return true;
            }
            else if (tortoise == hare)
            {
                return false;
            }
        }
    }
};