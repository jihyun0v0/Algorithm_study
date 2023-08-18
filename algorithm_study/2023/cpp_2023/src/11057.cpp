//
//  11057.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/04
//
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int num;
    cin>>num;   
    vector<vector<int>> num_arr;
    for(int i=0;i<10;i++){
        vector<int> *tmp = new vector<int>;
        tmp->push_back(1);
        num_arr.push_back(*tmp);
        delete tmp;
    }
    for(int i=1;i<num;i++){
        //i+1자릿수의 각 숫자의 갯수 구하기
        for(int j=0;j<10;j++){
            int sum=0;
            for(int k=0;k<=j;k++)
                sum= (sum +num_arr[k][i-1])%10007; 
            num_arr[j].push_back(sum);
        }
    }

    int sum=0;
    for(int i=0;i<10;i++)
        sum=(sum+num_arr[i][num-1])%10007;
    cout<<sum<<endl;
}