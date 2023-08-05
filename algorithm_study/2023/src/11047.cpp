//
//  11047.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/05
//
#include<iostream>

int main(){
    int n, k, num=0;
    scanf("%d", &n);
    scanf("%d", &k);

    int *arr = new int[n];
    for(int i=0;i<n;i++){
        std::cin>>arr[i];
    }
    for(int i=(n-1);i>-1;i--){
        if(k>=arr[i]){
            ////solve1
            // while(k>=arr[i]){
            //     k= k- arr[i];
            //     num++;
            // }
            //solve2
            num+=(k/arr[i]);
            k=k%arr[i];
        }
    }
    delete[] arr;

    std::cout<<num;
}