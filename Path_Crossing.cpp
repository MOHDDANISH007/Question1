class Solution {
public:
    bool isPathCrossing(string path) {
        int ans = -1;
        int length = path.size();
        int x = 0;
        int y = 0;
        unordered_set<string> st{"0_0"};

        for (int i = 0; i < length; i++) {
            if (path[i] == 'N') {
                y++;
            } else if (path[i] == 'E') {
                x++;
            } else if (path[i] == 'S') {
                y--;
            } else if (path[i] == 'W') {
                x--;
            }
            string current_pos = to_string(x) + "_" + to_string(y);
            if (st.find(current_pos) != st.end()) {
                return true;
            } else {
                st.insert(current_pos);
            }
        }
        return false;
    }
};
