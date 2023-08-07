int majorityElement(vector<int> v) {
	//finding which element is in majority case but u don't know how many times
    // come in array..
    int count =1, res = 0;
    for(int i=1; i<v.size(); i++){
      if (v[i] == v[res]) {
        count++;
      }
      else{
        count --;
      }
      if(count == 0){
          res = i;
          count = 1;
      }
    }
    // count how many time it comes
    count = 0;
    for(int i=0; i<v.size(); i++){
        if(v[i] == v[res]){
            count ++;
        }
    }
    if(count > v.size()/2){
        return v[res];
    }
    else{
        return  -1;
    }
}
