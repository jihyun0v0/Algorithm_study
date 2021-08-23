#include <iostream>

using namespace std;

struct contest{
    int min;
    int reward;

};

int main(){
    int N,  sum=0, max=0;
    int i;
    int noGo=-1;
    int noGo2=-1;
    struct contest* thisYear;
    
    cin>>N;
    thisYear=new struct contest[N];
    
    for(i=0;i<N;i++){
        cin>>thisYear[i].min;
        cin>>thisYear[i].reward;
        
        
        if(sum>thisYear[i].min){
            
            if(noGo==-1){      //불참 대회가 한번도 없었을 경우
                if((sum-thisYear[max].reward)>thisYear[i].min){//여태껏 나온 상금 중 가장 큰 상금을 제외해도 이번 대회 기준 금액보다 큰 경우
                noGo=i;
                }
                else{
                    noGo=max;
                    noGo2=i;        //참여 불가 대회가 나올 경우, 후보 불참대회
                }
            
            sum-=thisYear[noGo].reward;
            }
            
            else{ //불참 대회가 있었을 경우   noGo!=0
                if(noGo2==-1||(sum+thisYear[noGo].reward-thisYear[noGo2].reward)>thisYear[i].min){
                    cout<<"Zzz"<<endl;
                    break;
                }
                else{
                    sum+=thisYear[noGo].reward-thisYear[noGo2].reward;
                    noGo=noGo2;
                    noGo2=-1;
                }
            }
        }
        
        if(thisYear[max].reward<thisYear[i].reward)
            max=i;
        sum+=thisYear[i].reward;
    }
   
    if(i==N)
        cout<<"Kkeo-eok"<<endl;
    
    
    
    return 0;
        
    
    
}
