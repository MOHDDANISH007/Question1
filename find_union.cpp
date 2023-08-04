vector < int > sortedArray(vector < int > a, vector < int > b) {
    vector<int> temp;
    vector<int> ans;
    for(int i=0; i<a.size(); i++){
        temp.push_back(a[i]);
    }
    for(int i=0; i<b.size(); i++){
        temp.push_back(b[i]);
    }
     sort(temp.begin(),temp.end());
    for(int i=0; i<temp.size(); i++){
        if(temp[i] != temp[i+1]){
            ans.push_back(temp[i]);
        }
    }
    return ans;
}
