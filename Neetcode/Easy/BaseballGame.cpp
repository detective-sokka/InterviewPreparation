// https://leetcode.com/problems/baseball-game/description/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> result;

        for (auto &operand : operations) {
            if (operand == "C") {
                result.pop_back();                
            } else if (operand == "D") {
                int n = result.size();
                int op1 = result[n-1];            
                result.push_back(op1 * 2);
            } else if (operand == "+") {
                int n = result.size();
                int op1 = result[n-1];
                int op2 = result[n-2];
                result.push_back(op1 + op2);
            } else 
                result.push_back(stoi(operand));
        }

        int total = 0;

        for (int &num : result) 
            total += num;
        
        return total;
    }
};