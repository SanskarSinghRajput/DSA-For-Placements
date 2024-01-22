#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int start, int end, int x){
    while(start<=end){
        int mid = (start+end)/2;
        if(a[mid]==x)
          return mid;
        else if(x > a[mid])
          start = mid+1;
        else
          end = mid-1;
    }
    return -1;
}

int expoSearch(int a[], int n, int x){
    if(a[0]==0)
      return 0;
    int i = 1;
    while(i<n  && a[i]<x){
        i=i*2;
    }
    return binarySearch(a,i/2,min(n-1,i),x);
}


int main(){

  int a[] = {1,3,12,43,56,67,76,79,90};
  int ans = expoSearch(a,9,90);
  cout<<ans;

  return 0;
}