// https://leetcode.com/problems/remove-element/description/
#include <vector>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int high = nums.size() - 1;
        int low = 0;

        while (low <= high) {
            if (nums[low] != val)
                low++;
            else if (nums[high] == val)
                high--;
            else {
                swap(nums[low], nums[high]);
                low++;
                high--;
            }
        }

        return low;
    }
};