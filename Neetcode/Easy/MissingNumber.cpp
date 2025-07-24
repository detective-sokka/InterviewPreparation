// https://leetcode.com/problems/missing-number/

#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int start = 0;
        for (int i=0; i <= nums.size(); i++)
            start = start ^ i;
        for (auto &num : nums) 
            start = start ^ num;
        return start;
    }
};