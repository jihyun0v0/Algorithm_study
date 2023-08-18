//
//  10430.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/12
//
#include<iostream>
using namespace std;
int ridx, idx;
char buffer[1<<20];
static inline char read(){
    if(ridx == idx){
        ridx = fread(buffer, 1, 1<<20, stdin);
        idx = buffer[ridx] = 0;
    }
    return buffer[idx++];
}
static inline int readint() {
    int r =0;
    bool n = 0;
    char c = read();
    while(c<33) 
    c = read();
    if(c == '-')n = 1, c=read();
    while(c>=48&&c<=57){
        r = r*10+(c&15);
        c=read();
    }
    return n? -r:r;
}
int main(){
    int a, b, c;
    //for baekjoon input
    a = readint();
    b= readint();
    c = readint();
    // // for human input
    // cin>>a;
    // cin>>b;
    // cin>>c;
    cout<<(a+b)%c<<endl;
    cout<<(a%c+b%c)%c<<endl;
    cout<<(a*b)%c<<endl;
    cout<<((a%c)*(b%c))%c<<endl;
}