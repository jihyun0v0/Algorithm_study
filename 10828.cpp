//
//  10828.cpp
//  algorithm_study
//
//  Created by Jihyun Kyoung on 2023/07/31
//
#include <iostream>
using namespace std;

class Instance{
    private:
        Instance* ptr;
        int n;

    public:
        Instance(int num){
            n = num;
        }

        void push(Instance* n_ins){
            ptr = n_ins;
        }

        Instance *get_self(){
            return &*this;
        }
        Instance *get_ptr(){
            return ptr;
        }
        int getNum(){
            return n;
        }

};

class Stack{
    private:
        Instance *ptr;
        int size_n;

    public:
        Stack(){
            size_n = 0;
            ptr = NULL;
        }

// push X: 정수 X를 스택에 넣는 연산이다.
    void push(int n){
        Instance* tmp = new Instance(n);
        (*tmp).push(ptr);
        ptr = (*tmp).get_self();
        size_n++;
    }
// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    int pop(){
        if(size_n == 0)
            return -1;
        int tmp = (*ptr).getNum();
        ptr = (*ptr).get_ptr();
        size_n--;
        return tmp;
    }
// size: 스택에 들어있는 정수의 개수를 출력한다.
    int size(){
        return size_n;
    }
// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
    int empty(){
        if(size_n == 0)
            return 1;
        else 
            return 0;
    }
// top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    int top(){
        if(size_n == 0)
            return -1;
        int tmp = (*ptr).getNum();
        return tmp;
    }
};

int main(){
    int num, n, tmp;
    string menu;
    Stack stack;

    cin>>num;
    for(int i =0;i<num;i++){
    cin>>menu;  
    if(menu.compare("push")==0){
        cin >> tmp;
        stack.push(tmp);
    }
    else if(menu.compare("pop")==0){
            tmp = stack.pop();
            cout<<tmp<<endl;
    }
    else if(menu.compare("top")==0){
            tmp = stack.top();
            cout<<tmp<<endl;
    }
    else if(menu.compare("empty")==0){
        tmp = stack.empty();
        cout<<tmp<<endl;
    }
    else if(menu.compare("size")==0){
        tmp = stack.size();
        cout<<tmp<<endl;
    }
    

    }

}