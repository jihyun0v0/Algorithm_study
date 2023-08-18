//
//  10610.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/10
//
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, sum =0;
    list<int> lst;
    string s;
    cin>>s;
    sort(s.begin(), s.end(),greater<>());
    if(*(--s.end()) == '0'){
        for(auto& o:s){
            sum += o-'0';
        }
        if(sum%3 ==0)
          cout<<s;
        else
            cout<<-1;
    }
    else
        cout<<-1;
    
}