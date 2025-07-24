// https://leetcode.com/problems/single-number

#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto &num : nums) 
            result = result ^ num;
        return result;
    }
};