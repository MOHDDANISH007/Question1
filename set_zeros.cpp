#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[3][3] = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<int> row;
    vector<int> col;

    // Find the positions of zeros in the array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == 0) {
                row.push_back(i);
                col.push_back(j);
            }
        }
    }

    // Set the rows to zero
    for (int i = 0; i < row.size(); i++) {
        int rowIndex = row[i];
        for (int j = 0; j < 3; j++) {
            arr[rowIndex][j] = 0;
        }
    }

    // Set the columns to zero
    for (int i = 0; i < col.size(); i++) {
        int colIndex = col[i];
        for (int j = 0; j < 3; j++) {
            arr[j][colIndex] = 0;
        }
    }

    // Printing the matrix after setting the zeroes
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
