// https://leetcode.com/problems/counting-bits

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        int curr = 0;
        vector<int> result;

        for (int i=0; i <= n; i++)
        {
            int temp = i;
            int count = 0;
            
            while (temp > 0) {
                count += temp & 1;
                temp = temp >> 1;
            }

            result.push_back(count);
        }

        return result;
    }
};