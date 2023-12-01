#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;


int rearrangeToLargestEven(int num) {
    vector<int> digits;

    // Extract digits and store them in a vector
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }

    // Find the smallest and largest even digits
    int smallestEven = INT_MAX;
    int largestEven = INT_MIN;
    for (int digit : digits) {
        if (digit % 2 == 0) {
            smallestEven = min(smallestEven, digit);
            largestEven = max(largestEven, digit);
        }
    }

    // If no even digit is found, return -1
    if (smallestEven == INT_MAX) {
        return -1;
    }

    // Create a new vector with rearranged elements
    vector<int> rearranged;
    rearranged.push_back(largestEven);

    auto itLargest = find(digits.begin(), digits.end(), largestEven);
    
    if (itLargest != digits.end()) {
        digits.erase(itLargest);
    }
    
    auto itsmallest = find(digits.begin(), digits.end(), smallestEven);
    if (itsmallest != digits.end()) {
        digits.erase(itsmallest);
    }
    
    // digits.erase(remove(digits.begin(), digits.end(), largestEven), digits.end());
    // digits.erase(remove(digits.begin(), digits.end(), smallestEven), digits.end());
    

    sort(digits.begin(), digits.end());

    // Push the sorted digits to the new vector
    rearranged.insert(rearranged.end(), digits.begin(), digits.end());

    // Push the smallest even digit to the end
    rearranged.push_back(smallestEven);

    // Convert the vector to an integer
    int result = 0;
    for (int digit : rearranged) {
        result = result * 10 + digit;
    }

    return result;
}

int main() {
    int num;

    // Input the number
    cout << "Enter a number: ";
    cin >> num;

    // Call the function to rearrange the digits
    int result = rearrangeToLargestEven(num);

    // Display the result
    if (result == -1) {
        cout << "No rearrangement possible to form the largest even number.\n";
    } else {
        cout << "The rearranged number is: " << result << endl;
    }

    return 0;
}
