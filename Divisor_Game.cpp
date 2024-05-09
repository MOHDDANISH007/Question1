class Solution {
public:
    bool divisorGame(int n) {
        if(n <= 1){
            return false;
        }   
        if(n%2 != 0){
            return false;
        }
        return true;
    }

    // // Function to determine if Alice can win the game starting with number n
    // bool divisorGame(int n) {
    //     // Base case: If n <= 1, Alice cannot make a move and loses
    //     if (n <= 1) {
    //         return false;
    //     }
        
    //     // Try all possible moves for Alice
    //     for (int x = 1; x < n; ++x) {
    //         if (n % x == 0) { // Check if x is a divisor of n
    //             int newN = n - x; // Subtract x from n
    //             // Check if Bob will lose in the next move
    //             if (!divisorGame(newN)) {
    //                 return true; // Alice can force a win
    //             }
    //         }
    //     }
        
    //     // If no winning move found for Alice, Alice loses
    //     return false;
    // 
};
