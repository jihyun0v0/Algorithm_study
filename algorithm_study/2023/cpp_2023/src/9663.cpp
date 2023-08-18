//
//  9663.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/01
//
#include<iostream>
using namespace std;
int sum=0;
void queen(int* arr, int h, int n);
int main(){
    int num;
    cin>>num;
    int *arr = new int[num];
    queen(arr, 0, num);
    cout<<sum<<endl;
}
void queen(int* arr, int h, int n){
    int* pallet= new int[n];
    for(int i=0;i<n;i++){
        pallet[i] = 0;
    }
    for(int i=0;i<h;i++){
        if(arr[i]+h-i<n)    
            pallet[arr[i]+h-i]=-1;
        if(arr[i]-(h-i)>-1)
            pallet[arr[i]-(h-i)]=-1;
        pallet [arr[i]] = -1;
    }
    if(h == n-1)
        for(int i=0;i<n;i++){
            if(pallet[i] != -1){
                sum +=1;
            }
        }

    else{
        for(int i=0;i<n;i++){
            if(pallet[i]!=-1){
                arr[h]=i;
                queen(arr, h+1, n);
            }            
        }
    }
    delete[] pallet;
}

