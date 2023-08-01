#include<iostream>
using namespace std;

int main(){
    int num;

    //while(true){
    cin>>num;
    int **result = new int*[num];
    int first_arr[11]= {0,1,1,1,1,1,1,1,1,1,0};
    for(int i=1;i<num;i++){
        result[i] = new int[11];
    }
    result[0] = first_arr;

    for(int i=1;i<num;i++){
       for(int j=0;j<10;j++){
        if(j == 0)
        result[i][j] = result[i-1][1]%1000000000;
       
       else if(j ==9)
       result[i][j] = result[i-1][8]%1000000000;

      else
       result[i][j] = (result[i-1][j-1]+result[i-1][j+1])%1000000000;
    
       }
    }
    int sum =0;
    for(int i = 0;i<10; i++)
        sum = (sum+result[num-1][i])%1000000000;
    cout<<sum<<endl;
    delete[] result;

   // }
    return 0;
}

