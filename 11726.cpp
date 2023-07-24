#include<iostream>
using namespace std;

int main(){
    int n, m,index=0;
    cin>>m;
    int** c= new int*[m+1];
    for(int i=0;i<=m;i++)
        c[i] = new int[m+1];
    
    c[0][0] = 1; 
    for(int i=1;i<m+1;i++){
        c[i][0] = 1;
        c[i][i] = 1;
        for(int j=1;j<i;j++){
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%10007;
        }
    }

    int sum=0;
    n=m/2;
    for(int i=0;i<=n;i++){
        // cout<<i<<" "<<c[m-i][m-2*i]<<endl;
        sum+=c[m-i][m-2*i];
        sum%=10007;
    }

    cout<<sum%10007<<endl;

}