#include<iostream>
using namespace std;
int main(){
    long long a,b,n,ans,k;
    int sum=0;
    cin>>a>>b>>n;
    k=5*a+2*b;
    ans=n/k*7;
    n%=k;
    for(int i=1;i<=7&&sum<n;i++){
        if(i%7==0||i%7==6)
            sum+=b;
        else
            sum+=a;
        ans++;
    }
    cout<<ans<<endl;
}