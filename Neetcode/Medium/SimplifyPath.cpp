// https://leetcode.com/problems/simplify-path/description/
#include <set> 
#include <string>
#include <stack>

using namespace std;

class Solution {
    public: 
        string simplifyPath(string path) {

            stack<string> stk;
            string word;
            set<string> invalidWords = {".", "..", ""};

            for (char c : path + "/") {                
                if (c == '/') {
                    if (word == ".." && !stk.empty()) 
                        stk.pop();

                    else if (invalidWords.find(word) == invalidWords.end()) 
                        stk.push(word);

                    word.clear();
                }
                else {
                    word += c;
                }
            }
            string result;
            if (stk.empty())
                return "/";
            while (!stk.empty()) {
                result = "/" + stk.top() + result;
                stk.pop();
            }

            return result;
        }
};