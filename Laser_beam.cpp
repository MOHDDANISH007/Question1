#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count_prev_laser_light = 0;
        int result = 0;

        int floors = bank.size();

        for (int i = 0; i < floors; i++) {

            int cur_beams_light = 0;

            for (auto &ch : bank[i]) {  
                if (ch == '1') {
                    cur_beams_light++;
                }
            }

            result += (cur_beams_light * count_prev_laser_light);

            if (cur_beams_light != 0) {  
                count_prev_laser_light = cur_beams_light;
            }
        }
        return result;
    }
};
