#include<bits/stdc++.h>
using namespace std;

int rec(vector<int> arr, int index, int sum, int &count, int target){
    if(index > arr.size())
       return 0;

    if(sum == target){
        count++;
        return 0;
    }
    
    rec(arr, index+1, sum, count, target);
    sum += arr[index];
    rec(arr, index+1, sum, count, target);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int target = 6;
    int sum = 0;
    int count = 0;
    int index = 0;
    rec(arr, index, sum, count, target);

    cout<<count<<endl;

    return 0;
}