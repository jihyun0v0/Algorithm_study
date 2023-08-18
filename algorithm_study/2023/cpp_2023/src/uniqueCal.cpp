#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cctype>
typedef long long ll;
using namespace std;

void solve();
int priority();
int get_op_pri(char& a);
ll cal(ll a, ll b, char op);
void push(ll result,char loc);

deque <char> op;
deque <ll> nums;

int main(){
    int tmp;
    ll sum=0;
    
    if((tmp=getchar())=='-'){
        while(isdigit(tmp=getchar()))
            sum=sum*10+tmp-'0';
        nums.push_back(sum*-1);
    }
    
    while(tmp!='\n'){
        if(isdigit(tmp)){
            sum=tmp-'0';
            while(isdigit(tmp=getchar()))
                sum=sum*10+tmp-'0';
            nums.push_back(sum);
                    }
        else{
            op.push_back(tmp);
            tmp=getchar();
        }
    }
    
    while(nums.size()!=1)
        solve();
    
    
    cout<<nums[0]<<endl;
    
}

void solve(){
    int p=priority();
    ll result;
    
    if(p==1){
        result=cal(*nums.begin(), *(nums.begin()+1), *op.begin());
        push(result, 'b');
    }
    else if(!p){
        result=cal(*nums.begin(), *(nums.begin()+1), *op.begin());
        ll result2=cal(*(nums.end()-2), *(nums.end()-1), *(op.end()-1));
        if(result<result2)push(result2, 'e');
        else push(result, 'b');
    }
    else{
        result=cal(*(nums.end()-2), *(nums.end()-1), *(op.end()-1));
        push(result, 'e');
    }
}

int priority(){
    int a=get_op_pri(*op.begin());
    int b=get_op_pri(*(op.end()-1));
    
    if(a==b)
        return 0;
    if(a>b)
        return 1;
    return -1;
}

int get_op_pri(char& a){
    
    switch (a) {
        case '+':
        case '-':
            return -1;
        case '*':
        case '/':
            return 1;
            
        default:
            break;
    }
    return 0;
}

ll cal(ll a, ll b, char op){
    switch (op) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        case '/':
            return a/b;
        default:
            break;
    }
    return a;
}

void push(ll result,char loc){
    if(loc=='b'){
        nums[1]=result;
        nums.pop_front();
        op.pop_front();
        return;
    }
    *(nums.end()-2)=result;
    nums.pop_back();
    op.pop_back();

}
