#include<iostream> 
using namespace std;

int Fib(int n){
    if(n==0 || n==1)
      return n;

    return Fib(n-1)+Fib(n-2);
}

int main(){
    int n;
    cin>>n; 

    int ans = Fib(n);
    cout<<endl<<ans;

    return 0;
}