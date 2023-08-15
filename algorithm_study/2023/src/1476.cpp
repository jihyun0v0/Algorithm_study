#include<iostream>
 
using namespace std;
int solution(int E, int S, int M){
    int n,tmp, i=0;
    while(true){
        tmp=28*i+S;
        if(tmp%15 == E){
            if(tmp%19 == M){
                n = tmp;break;
            }
            else if(tmp%19==0&&M == 19){
                n = tmp;break;
            }
        }
        else if(E == 15&&tmp%15 == 0){
            if(tmp%19 == M){
                n = tmp;break;
            }
            else if(tmp%19==0&&M == 19){
                n = tmp;break;
            }
        }
        i++;
    }
    return n;
}
int main(){
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);
    int n = solution(E, S, M);
    cout<<n;
}