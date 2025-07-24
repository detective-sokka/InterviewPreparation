// https://leetcode.com/problems/climbing-stairs/
#include <map>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        switch (n)
        {
        case 0:
            return 1;
            break;
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        default:
            if (ways.find(n) != ways.end())
                return ways[n];
        }
        
        ways[n] = climbStairs(n - 1) + climbStairs(n - 2);        
        return ways[n];
    }
private: 
    unordered_map<int, int> ways;
};