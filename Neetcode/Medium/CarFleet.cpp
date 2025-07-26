// https://leetcode.com/problems/car-fleet/description/

#include <vector>
#include <utility>

using namespace std;

// [10, 8, 0, 5, 3]
// [2, 4, 1, 1, 3]
// [(0,1),(3,3),(5,1),(8,4),(10,2)]
// [(0,1), (12, 1), (10,2)]
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> posSpeed;
        // [(6, 3), (8, 2)]
        for (int i=0; i < position.size(); i++)
            posSpeed.push_back({position[i], speed[i]});            
        
        // [(6, 3), (8, 2)]
        sort(posSpeed.begin(), posSpeed.end(), [](auto &car1, auto &car2) {
            return car1.first > car2.first;
        });

        int fleets = 0;
        double lastTime = 0;
        
        for (auto &[pos, speed] : posSpeed) {
            double time = static_cast<double>(target - pos) / speed;
            if (time > lastTime)
            {
                lastTime = time;
                fleets++;                
            }
        }

        return fleets;        
    }
};