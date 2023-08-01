//
//  15649.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/01
//
#include <iostream>
#include <vector>
using namespace std;
template <typename T>
void combi(vector<T>* result,vector<T>* left, int m);
    
int main(){
    int n,m;
    cin>>n;
    cin>>m;
   
    vector<int> left;
    vector<int> result;
    for(int i =0;i<n;i++)
        left.push_back(i+1);
    combi(&result,&left, m);

}
template <typename T>
void combi(vector<T>* result,vector<T>* left, int m){
    int result_size = (*result).size();
    int n = left->size();


    if(m == 1){
        for(int i =0;i<n;i++){
            for(int j = 0;j<result_size;j++)
                printf("%d ", (*result)[j]);
            printf("%d\n", (*left)[i]);
            }
    }
    else{
        vector<int> *result_n= new vector<int>;
        vector<int> *left_n = new vector<int>;
        for(int i =0;i<result_size;i++){
            result_n->push_back((*result)[i]);
        }
        (*result_n).push_back((*left)[0]);
        for(int i =1;i<n;i++)
            (*left_n).push_back((*left)[i]);


        for(int i =0;i<left_n->size();i++){
            combi(result_n, left_n,  m-1);
            //swap
            int tmp = ((*result_n)[result_size]);
            (*result_n)[result_size] = (*left_n)[i];
            (*left_n)[i] = tmp;
       }
        combi(result_n, left_n,  m-1);
    }
}
