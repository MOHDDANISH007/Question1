class Solution {
public:
    // Checking whether the number is a power of 2 with the help of (n & (n - 1) == 0).
        // Afterward, we determine if the number is a power of 4 by checking (n % 3 == 1).
        // This means that powers of four have their set bit at an odd bit position.
        // Power of 2's -> 1, 2, 4, 8, 16, 32, 64...
        // Binary representation of power of 2's: 1 -> 0001, 2 -> 0010, 4 -> 0100, 8 -> 1000, 16 -> 10000...
        // Here, power of 2's bit position: 1 -> 1, 2 -> 2, 4 -> 3, 8 -> 4...
        // Power of 4's -> 1, 4, 16, 64...
        // Binary representation of power of 4's: 1 -> 0001, 4 -> 0100, 16 -> 10000...
        // Here, power of 4's bit position: 1 -> 1, 4 -> 3, 16 -> 5.
        
    bool isPowerOfFour(int n) {
        if (n > 0 && (n & (n - 1)) == 0 && (n % 3 == 1)) {
            return true;
        }
        return false;
    }
};
