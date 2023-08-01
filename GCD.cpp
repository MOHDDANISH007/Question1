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
