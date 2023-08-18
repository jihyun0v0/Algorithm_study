#include <iostream>
#define MAX 1000000

using namespace  std;
int s[1000000] = {0,};

int shortest(int n){
    int s3, s2, s1;
    int result;

    if(n<4){
        if(n<2)
            return 0;
        else 
            return 1;
    }

    if(n%3==0){
        if(s[n/3-1]==0)
            s[n/3-1] = shortest(n/3);
        s3 = s[n/3-1]+1;
    }
    else{
        s3 = MAX;
    }
     if(n%2==0){
        if(s[n/2-1]==0)
            s[n/2-1] = shortest(n/2);
        s2 = s[n/2-1]+1;
    }
    else{
        s2 = MAX;
    }
    if(s[n-2]==0)
            s[n-2] = shortest(n-1);
    s1 = s[n-2]+1;

    if(s1<s2){
        result = s1;
    }
    else
        result = s2;

    if(result>s3)
        result = s3;
    // cout<<"shortest for"<<n<<"is"<<result;
    s[n-1] = result ;
    return result;
}

int main(){
    int num=10;
    //cout<<"enter the number:"<<endl;
    cin>>num;

    // cout<<"enetered number: "<<num<<endl;
    int result = shortest(num);
    cout << result<<endl;
return 0;

}