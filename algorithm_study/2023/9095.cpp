
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int num,largest=-1;

    cin>>num;
    int *arr = new int[num];
    for(int i=0;i<num;i++){
        cin>>arr[i];
        largest = max(largest, arr[i]);
    }
    int *arr2 = new int[largest];
    arr2[0] = 1;
    arr2[1] = 2;
    arr2[2] = 4;
    for(int i=3;i<largest;i++){
        arr2[i] = arr2[i-1]+arr2[i-2]+arr2[i-3]; 
    }

    for(int i=0;i<num;i++){
        cout<<arr2[arr[i]-1]<<endl;
    }
    
       

}