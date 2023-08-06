#include <bits/stdc++.h> 
using namespace std;

void sort012(int *arr, int n)
{
   int f = 0, s = 0, t = 0;

   // Counting where 0s, 1s, and 2s are in the array
   for (int i = 0; i < n; i++) {
      if (arr[i] == 0) {
         f++;
      } else if (arr[i] == 1) {
         s++;
      } else if (arr[i] == 2) {
         t++;
      }
   }
   
   // Filling the array with 0s, 1s, and 2s in order
   for (int i = 0; i < f; i++) {
      arr[i] = 0;
   }

   for (int i = f; i < f + s; i++) {
      arr[i] = 1;
   }

   for (int i = f + s; i < f + s + t; i++) {
      arr[i] = 2;
   }
}


