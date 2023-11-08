class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // Step 1: Create a stack to track asteroids.
        stack<int> st;

        // Step 2: Calculate the size of the asteroid array.
        int sz = asteroids.size();

        for (int &a : asteroids) {
            // Step 3: Check for possible collisions.
            while (!st.empty() && a < 0 && st.top() > 0) {
                int sum = a + st.top();
                if (sum < 0) {
                    // If the current asteroid is larger, the top asteroid in the stack explodes.
                    st.pop();
                } else if (sum > 0) {
                    // If the top asteroid in the stack is larger, the current asteroid explodes.
                    a = 0;
                } else {
                    // If both asteroids are of equal size, they both explode.
                    a = 0;
                    st.pop();
                }
            }
            if (a != 0) {
                // Current asteroid survives, push it into the stack.
                st.push(a);
            }
        }

        // Step 4: Store the remaining asteroids in a vector.
        vector<int> v(st.size());
        int i = st.size() - 1;
        while (!st.empty()) {
            v[i] = st.top();
            st.pop();
            i--;
        }

        // Step 5: Return the remaining asteroids after collisions.
        return v;
    }
};
