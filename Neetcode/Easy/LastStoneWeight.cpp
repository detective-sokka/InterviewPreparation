// https://leetcode.com/problems/last-stone-weight/

#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> stoneQueue;
        
        for (int &stone : stones) 
            stoneQueue.push(stone);
        
        while (stoneQueue.size() > 1) {
            int y = stoneQueue.top();
            stoneQueue.pop();
            int x = stoneQueue.top();
            stoneQueue.pop();

            if (y != x)
                stoneQueue.push(y-x);
        }

        if (stoneQueue.size() == 0)
            return 0;
        
        return stoneQueue.top();
    }
};