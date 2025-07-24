// https://neetcode.io/problems/meeting-schedule
#include <vector>

using namespace std;
/**
 * Definition of Interval:
 */
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
 

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        
        auto comparator = [](auto &a, auto &b) {
            return a.start < b.start;
        };
        sort(intervals.begin(), intervals.end(), comparator);

        for (int i = 1; i < intervals.size(); i++) 
            if (intervals[i].start < intervals[i-1].end)
                return false;
        
        return true;
    }
};
