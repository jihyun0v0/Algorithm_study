#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int g, b, k, l, t;
    cin>>g;
    cin>>b;
    cin>>k;

    if((g/2)>b){
        t = b;
        l = (g/2-b)*2+g%2;
    }
    else{
        t = g/2;
        l = b-g/2+g%2;
    }   

    if(l>=k){
        cout<< t;
    }
    else{
        if((k-l)%3>0)
            cout<<t - (k-l)/3-1;
        else
            cout<<t-(k-l)/3;
    }
}