// 56. Merge Intervals
/*
Thought: save in result vec, and try to merge

Time complexity: O(n^2)
Space complexity:
*/
#include <vector>

class Solution {
public:
    bool isOverlapped(int& frontA, int& rearA, int frontB, int rearB)
    {
        int maxI = max(rearA, rearB);
        int minI = min(frontA, frontB);

        int lengthA = rearA - frontA;
        int lengthB = rearB - frontB;
        if (maxI - minI <= (lengthA + lengthB))
        {
            frontA = minI;
            rearA = maxI;
            return true;
        }

        return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        for (int i = 0; i < intervals.size();)
        {
            bool isMerged = false;
            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (isOverlapped(intervals[i][0], intervals[i][1], intervals[j][0], intervals[j][1]))
                {
                    intervals.erase(intervals.begin() + j);
                    isMerged = true;
                    break;
                }
            }

            if (isMerged == false)
            {
                i++;
            }
        }

        return intervals;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::vector<std::pair<int, int>> pairVec;
        
        // O(n)
        for (auto& vec : intervals) 
        {
            pairVec.push_back({ vec[0], vec[1] });
        }

        // O(nlogn) 
        std::sort(pairVec.begin(), pairVec.end());

        std::vector<std::vector<int>> returnVec;

        int startValue = pairVec[0].first;
        int endValue = pairVec[0].second;

        for (int i = 1; i < pairVec.size(); i++) 
        {
            if (endValue >= pairVec[i].first) 
            {
                endValue = max(endValue, pairVec[i].second);
            }
            else 
            {
                returnVec.push_back({ startValue, endValue });
                startValue = pairVec[i].first;
                endValue = pairVec[i].second;
            }
        }

        returnVec.push_back({ startValue, endValue });

        return returnVec;
    }
};

