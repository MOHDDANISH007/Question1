bool ispossile(vector<int> &boards, int k, int mid){
  int paiinter = 1;
  int painted = 0 ;
  for(int i=0; i<boards.size(); i++){
    if(painted + boards[i] <= mid){
      painted += boards[i];
    }
    else{
      paiinter++;
      if(paiinter > k || boards[i] > mid){
        return false;
      }
      painted = boards[i];
    }
  }
  return true;
}




int findLargestMinDistance(vector<int> &boards, int k)
{
  if(boards.size() < k){
    return -1;
  }
  int s = 0;
  int sum  = 0;
  for(int i=0; i<boards.size(); i++){
    sum += boards[i];
  }
  int e = sum;
  int ans = -1;
  int mid = s + (e-s)/2;
  while(s <= e){
    if(ispossile(boards, k, mid)){
      ans = mid;
      e = mid-1;
    }
    else{
      s = mid+1;
    }
    mid = s + (e-s)/2;
  }
  return ans;
}

