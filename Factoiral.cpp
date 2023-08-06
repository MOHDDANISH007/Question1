  GNU nano 7.2                     Factoiral.cpp                      Modified
   return result;
}long long findFact(long long n){
    if(n==0)
        return 1;
    return n*findFact(n-1);
}

vector<long long> factorialNumbers(long long n) {
    // Write Your Code Here
    vector<long long> ans;
    for(long long i=1; i<=n; i++){
        long long f = findFact(i);
        if (f<=n)
            ans.push_back(f);
        if(f>n)
            break;

    }
    return ans;
}
  
