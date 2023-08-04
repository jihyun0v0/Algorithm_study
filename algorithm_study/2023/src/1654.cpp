#include<iostream>
#include<vector>
using namespace std;
void cal1(vector<unsigned long > &len, unsigned long *max,unsigned long *min, unsigned long* size, int n);
int cal2(vector<unsigned long > &len, unsigned long size);
int main(){
    int k, n;
    unsigned long max =0, min, tmp, size;
    cin>>k;
    cin>>n;
    vector<unsigned long > len;
    for(int i =0;i<k;i++){
        cin>>tmp;
        len.push_back(tmp);
        if(tmp>max)
            max = tmp;
    }
    min = 1;
    size = max;
    cal1(len, &max,&min, &size, n);
    cout<< min<<endl;
}

void cal1(vector<unsigned long > &len, unsigned long *max,unsigned long *min, unsigned long* size, int n){
    int sum = cal2(len, *size);
    if(sum<n&&(*min<(*max-1))){
        *max = *size;
        *size = *min +(*max-*min)/2;
        cal1(len,max, min, size, n);
    }
    else if(sum>=n&&*min<(*max-1)){
        *min= *size;
        *size = *min +(*max-*min)/2;
        cal1(len, max, min, size, n);
    }   
    return;
}

int cal2(vector<unsigned long > &len, unsigned long size){
    int sum =0;
    for(int i=0;i<len.size();i++){
        sum += len[i]/(size);
    }
    return sum;
}
