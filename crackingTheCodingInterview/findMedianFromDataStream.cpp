//https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
private:
    priority_queue<int>left;
    priority_queue<int, vector<int>, greater<int>>right;
public:
    vector<int> database;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //maintain two heaps, one with larger elements and one with smaller elements
        //determine which to push to
        //if one now is larger by more than one element, shift the largest/smallest element
        //to the appropriate heap to rebalance

        double median = findMedian();
        if(num > median)
        {
            right.push(num);
            if(right.size() - left.size() > 1)
            {
                left.push(right.top()); right.pop();
            }
        }
        else
        {
            left.push(num);
            if(left.size() - right.size() > 1)
            {
                right.push(left.top()); left.pop();
            }
        }

    }
    
    double findMedian() {
        if(left.size() == right.size())
        {
            if(left.empty())
            {
                return 0;
            }
            return ( (double) left.top() + right.top()) /2;
        }
        else if(left.size() > right.size())
        {
            return left.top();
        }
        else
        {
            return right.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */