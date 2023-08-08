int floor(int arr[], int n, int x){

    int s=0;

    int e=n-1;

    int ans=-1;

    while(s<=e){

        int mid=s+(e-s)/2;

        if(arr[mid]<=x){

            ans=arr[mid];

            s=mid+1;

        }

        else{

            e=mid-1;

        }

    }

    return ans;

}

 

int ceil(int arr[], int n, int x){

    int s=0;

    int e=n-1;

    int ans=-1;

    while(s<=e){

        int mid=s+(e-s)/2;

        if(arr[mid]>=x){

            ans=arr[mid];

            e=mid-1;

        }

        else{

            s=mid+1;

        }

    }

    return ans;

}

 
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	sort(arr, arr + n); // Sort the array before using floor and ciel functions
	pair<int, int> p;
	p.first = floor(arr, n, x);
	p.second = ceil(arr, n, x);
	return p;
}
