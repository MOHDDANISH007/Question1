#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    vector<int> n1 = {1, 2, 3, 4, 5};
    vector<int> n2 = {6, 7, 8, 9};

    int m = n1.size();
    int n = n2.size();

    // Resize n1 to accommodate the additional elements from n2
    n1.resize(m + n);

    for (int j = 0, i = m; j < n; j++) {
        n1[i] = n2[j];
        i++;
    }

    for (int i = 0; i < n1.size(); i++) {
        cout << n1[i] << " ";
    }
    cout << endl;

    int size = n1.size();

    if (size % 2 == 1) {
        cout  << fixed << setprecision(8) << "Median: " << (double) n1[size / 2] << endl;
    } else {
        double median = ((double) n1[size / 2] + (double) (n1[(size / 2) - 1])) / 2.0000;
        cout  << fixed  << setprecision(8) << "Median: " << median << endl;
    }

    return 0;
}
