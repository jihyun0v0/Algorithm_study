//
//  1780.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/08/11
//
#include<iostream>
#include <cstdio>
using namespace std; 
short int* arr;
int* num;
int idx, ridx;
char buffer[1<<20];
int check(int a, int b, int n, int N);
static inline char read();
static inline int readint();

int main(){
    int N;
    N = readint();
    int tmp[4]={0,};
    num = &tmp[1];
    arr = new short int[N*N];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            arr[i*N+j]=readint();
    num[check(0,0, N,N)]++;
    for(int i=-1;i<2;i++)
        cout<<num[i]<<endl;
}

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

int check(int a, int b, int n, int N){
    int chk_arr[9],chk_ind =0, same =1;
    if(n==1){
        return arr[a*N+b];
    }
    
    int k = n/3;
    chk_arr[0] = check(a, b, k, N); chk_arr[1] = check(a, b+k, k, N); chk_arr[2] = check(a, b+k*2, k, N);

    chk_arr[3] = check(a+k, b, k, N); chk_arr[4] = check(a+k, b+k, k, N); chk_arr[5] = check(a+k, b+k*2, k, N);

    chk_arr[6] = check(a+k*2, b, k, N); chk_arr[7] = check(a+k*2, b+k, k, N); chk_arr[8] = check(a+k*2, b+k*2, k, N);

    for(int i = 1;i<9;i++)
        if(chk_arr[0] != chk_arr[i]){
            same = 0;
            break;
        }
    if(same==1&&chk_arr[0]!=2)
        return chk_arr[0];

    for(auto& o:chk_arr){
        num[o] +=1;
    
        return 2;
    }
}

