// 295. Find Median from Data Stream

#include <queue>
using namespace std;

class MedianFinder 
{
public:
    MedianFinder() 
    {

    }

    void addNum(int num) 
    {
        if (maxHeapForSmallerHalf.empty() || maxHeapForSmallerHalf.top() >= num) 
        {
            maxHeapForSmallerHalf.push(num);
        }
        else 
        {
            minHeapForLargerHalf.push(num);
        }

        if (maxHeapForSmallerHalf.size() == minHeapForLargerHalf.size() + 2) 
        {
            int tmp = maxHeapForSmallerHalf.top();
            maxHeapForSmallerHalf.pop();
            minHeapForLargerHalf.push(tmp);
        }
        else if (minHeapForLargerHalf.size() == maxHeapForSmallerHalf.size() + 1) 
        {
            int tmp = minHeapForLargerHalf.top();
            minHeapForLargerHalf.pop();
            maxHeapForSmallerHalf.push(tmp);
        }
    }

    double findMedian() 
    {
        if (maxHeapForSmallerHalf.size() == 0) 
        {
            return 0;
        }
        else if (maxHeapForSmallerHalf.size() == minHeapForLargerHalf.size()) 
        {
            return (double)(maxHeapForSmallerHalf.top() + minHeapForLargerHalf.top()) / 2;
        }
        else 
        {
            return maxHeapForSmallerHalf.top();
        }
    }

private:
    priority_queue<int> maxHeapForSmallerHalf;
    priority_queue<int, vector<int>, std::greater<int>> minHeapForLargerHalf;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */