#include <iostream>
using namespace std;
#include <vector>

 // first function

int firstocc(std::vector<int>& arr, int size, int key) {
    int starting = 0;
    int ending = size - 1;
    int ans = -1;
    while (starting <= ending) {
        int mid = starting + (ending - starting) / 2;
        if (key == arr[mid]) {
            ans = mid;
            ending = mid - 1;
        } else if (key > arr[mid]) {
            starting = mid + 1;
        } else if (key < arr[mid]) {
            ending = mid - 1;
        }
    }
    return ans;
}

// second function

int lastocc(std::vector<int>& arr, int size, int key) {
    int starting = 0;
    int ending = size - 1;
    int ans = -1;
    while (starting <= ending) {
        int mid = starting + (ending - starting) / 2;
        if (key == arr[mid]) {
            ans = mid;
            starting = mid + 1;
        } else if (key > arr[mid]) {
            starting = mid + 1;
        } else if (key < arr[mid]) {
            ending = mid - 1;
        }
    }
    return ans;
}


int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int occurence;
	std::pair<int, int> p;
    p.first = firstocc(arr, n, x);
    p.second = lastocc(arr, n, x);
	
	if(p.first == -1 && p.second == -1){
		occurence=0;
	}
	else{
		occurence= (p.second - p.first) + 1;
	}	
	return occurence;
}


