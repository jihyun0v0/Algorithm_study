#include <iostream>
using namespace std;

int main(){
    int n;
    int arr[1000]={0,};
    //p(1) = 1
    arr[0] = 1;
    //p(2) = 3
    arr[1] = 3;
    cin>>n;
    for(int i=2;i<n;i++){
        arr[i] = (arr[i-1]+2*arr[i-2])%10007;
    }
    cout<<arr[n-1]<<endl;

}