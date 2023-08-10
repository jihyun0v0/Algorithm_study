//
//  2845.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/08
//
#include <iostream>
using namespace std;
int main(){
    int n,p, j;
   cin>>n;
   cin>>p;
   int num[5];
   for(int i=0;i<5;i++){
    cin>>j;
    num[i] = j-n*p;
   }
    for(int i=0;i<5;i++){
        cout<<num[i]<<" ";
    }
}