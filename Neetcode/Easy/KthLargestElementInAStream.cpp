// https://leetcode.com/problems/kth-largest-element-in-a-stream

#include <functional>
#include <queue>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : mK{k}, mPriorityQueue{} {        
        for (auto &num : nums)
            add(num);      
    }
    
    int add(int val) {

        mPriorityQueue.push(val);    

        if (mPriorityQueue.size() > mK)
            mPriorityQueue.pop();
                    
        return mPriorityQueue.top();        
    }

private: 
    int mK;
    priority_queue<int,vector<int>,greater<int>> mPriorityQueue;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */