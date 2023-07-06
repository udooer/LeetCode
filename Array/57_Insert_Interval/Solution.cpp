// 57. Insert Interval
/*
Thought:

Time complexity: O(n)
Space complexity: O(1)
*/
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        bool isInsert = false;

        for (int i = 0; i < intervals.size(); i++)
        {
            if (intervals[i][0] > newInterval[0])
            {
                intervals.insert(intervals.begin() + i, newInterval);
                isInsert = true;
                break;
            }
        }

        if (isInsert == false)
        {
            intervals.push_back(newInterval);
        }

        std::vector<std::vector<int>> returnVec;
        int startValue = intervals[0][0];
        int endValue = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (endValue >= intervals[i][0])
            {
                endValue = max(endValue, intervals[i][1]);
            }
            else
            {
                returnVec.push_back({ startValue, endValue });
                startValue = intervals[i][0];
                endValue = intervals[i][1];
            }
        }

        returnVec.push_back({ startValue, endValue });

        return returnVec;
    }
};