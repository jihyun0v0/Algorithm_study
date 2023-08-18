//
//  2609.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/18
//
#include <iostream>
#include <vector>
using namespace std;

int min(int n, int m){
    int answer; 
    vector<int> div;
    vector<int>::iterator itr;
    //n<m
    if(n<m){
          for(int i = n;i>0;i--){
            if(n%i == 0 ){
                if(m%i == 0)
                    return i;
            }
        }
    }
    else{
        for(int i = m;i>0;i--){
            if(m%i == 0 ){
                if(n%i == 0)
                    return i;
            }
        }
    }
    return -1;
}
int max(int n, int m){
    if(n>m){
        for(int i = 1;i<=m;i++){
            if((i*n)%m == 0)
                return i*n;
        }
    }
    else{
        for(int i = 1;i<=n;i++){
            if((i*m)%n == 0)
                return i*m;
        }
    }
    return -1;
}
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    int min_answer = min(n, m);
    int max_answer = max(n,m);
    cout<<min_answer<<endl;
    cout<<max_answer<<endl;
 }
