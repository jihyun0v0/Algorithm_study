//
//  11728.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/10
//
#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 1000000
using namespace std;
int main(){
     ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int n, m,tmp, i, j;
    cin>>n;
    cin>>m;
    int a[n], b[m];
    int a_ind=0;
    int b_ind=0;
    for(a_ind=0;a_ind<n;a_ind++){
        cin>>a[a_ind];
    }
    for(b_ind =0;b_ind<m;b_ind++){
        cin>>b[b_ind];
    }
    for(b_ind =0,a_ind=0;b_ind<m&&a_ind<n;){
        if(a[a_ind]<b[b_ind]){
            cout<<a[a_ind++]<<" ";
        }
        else
            cout<<b[b_ind++]<<" ";
    }
    while(b_ind<m){
        cout<<b[b_ind++]<<" ";
    }
    while(a_ind<n){
        cout<<a[a_ind++]<<" ";
    }
   cout<<endl;
}