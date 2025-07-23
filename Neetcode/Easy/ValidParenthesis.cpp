// https://leetcode.com/problems/valid-parentheses/description/
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char &c : s) {
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else {
                if (stk.empty())
                    return false; 
                if (c == ')' && stk.top() != '(')
                    return false;
                if (c == ']' && stk.top() != '[')
                    return false;
                if (c == '}' && stk.top() != '{')
                    return false;
                
                stk.pop();
            }
        }

        if (stk.size() > 0)
            return false;
        
        return true;
    }
};

// Think case - "([)]"