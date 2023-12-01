#include <bits/stdc++.h> 
int findGcd(int x, int y)
{
   if(x==0){
       return y;
   }
   if(y==0){
       return x;
   }
   while(x!=y){
       if(x>y){
           x = x-y;
       }
       else{
           y = y-x;
       }
   }
   return y;
}


//optimal solution 



int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a>b){
            a = a % b;
        }
        else{
            b = b % a;
        }
    }
    if(a == 0){
        return b;
    }
    else{
        return a;
    }
}

int main() {
    int ans = gcd(68, 119);
    cout << "The greatest common divisor is " << ans <<endl;
    
}
