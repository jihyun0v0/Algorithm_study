#include <string>
#include <vector>
#include<iostream>
#include <set>
using namespace std;
int stack[500];
int ind = -1;
int totalStamp =0;
int front;
set<int> visited;
int getGraph(int n, vector<vector<int>>& roads){
    char c;
    int i,j,front;
    cin>>n;
    cin>>c;
    cin>>c;
    cin>>i;
    front = i;
    cin>>c;
    cin>>j;
    cin>>c;
    cin>>c;
    vector<int> tmp;
    tmp.push_back(i);
    tmp.push_back(j);
    roads.push_back(tmp);
    while(c==','){
        cin>>c;
        cin>>i;
        cin>>c;
        cin>>j;
        cin>>c;
        cin>>c;
        // graph[i][j] = 1;
        if(front == j){
            front = i;
        }
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back(j);
        roads.push_back(tmp);
    }
    return front;
}
int getMinEdge(int n, vector<vector<int>>& roads){
    int answer=0;
    for(vector<vector<int>>::iterator itr = roads.begin();itr!=roads.end();itr++){
        if((*itr)[1]==n){
            answer++;
        }
    }
    return answer;
}
int DFS(int n, vector<vector<int>> &roads){
    int answer = 0;
    // int flag = 0;
    int minEdge=n;
    vector<vector<int>>::iterator minEdge_itr;
    if(visited.size()>=n)
        return 0;
    front = stack[ind--];
    // visited.insert(front);
    vector<vector<int>>::iterator itr = roads.begin();
    while(itr!=roads.end()){
        if((*itr)[0] == front){
            int tmp = getMinEdge((*itr)[1], roads);
            if(tmp<minEdge){
                minEdge = tmp;
                minEdge_itr = itr;
            }
        } 
        itr++;
    }
    if(minEdge<n){
        // flag = 1;
        //if(visited.find(o[1])!=visited.end())
        visited.insert((*minEdge_itr)[1]);
        stack[++ind] = (*minEdge_itr)[1];
        roads.erase(minEdge_itr);
        answer+=DFS(n, roads);
    }
    // if(flag == 0){
    if(minEdge==n){
        answer+=1;
    }
    
    return answer;
}
int getFront(int n, vector<vector<int>>& roads){
    if(roads.size()<=0)
        return -1;
    // vector<vector<int>>::iterator itr = roads.begin();
    // int front = (*itr)[0];
    // itr++;
    // for(;itr!=roads.end();itr++){
    //     if((*itr)[1] == front)
    //         front = (*itr)[0];
    // }
    // set<int>::iterator itr = visited.begin();
    // int front_tmp;
    // set<int> searched;
    // // front = *itr;
    // for(int i=n;i>=1;i--){
    //     if(visited.find(i)!=visited.end()&&searched.find(i) != searched.end()){
    //         continue;
    //     }
    //     front = i;
    //     searched.insert(i);
    //     vector<vector<int>>::iterator itr = roads.begin();
    //     for(;itr!=roads.end();itr++){       
    //         if((*itr)[1] == i){
    //             front = (*itr)[0];
    //             itr = roads.begin();
    //             searched.insert(front);
    //         }
    //     }
    // }
    vector<vector<int>>::iterator itr = roads.begin();
    int front = (*itr)[0];
    for(;itr!=roads.end();itr++){
        vector<vector<int>>::iterator o = roads.begin();  
        for(;o!=roads.end();o++){
            if((*o)[1] == (*itr)[0])
                break;
        }
        if(o == roads.end()){
            if(front>(*itr)[0]){
                front = (*itr)[0];
            }
        }
    }


    return front;
}
int solution(int n, vector<vector<int>> roads) {
    int answer = 0;
    //  front = getFront(roads);
    // stack[++ind] = front;
    // // totalStamp +=1;

    // answer = DFS(n, roads);
    // cout<<answer;
    // return answer;
    int flag = 0;
    front =1;
    while(visited.size()<n){
        front = getFront(n, roads);
        // front = 1;
        visited.insert(front);
        stack[++ind] = front;
        answer += DFS(n, roads);
    }
    cout<<answer;
    return answer;
}

int main(){
    vector<vector<int>> roads;
    //[[1, 2], [1, 3], [1, 4], [2, 5], [4, 5], [5, 6], [5, 7], [6, 9], [7, 9], [5, 8]]
    int arr[] = {1, 2, 2, 6, 2, 4, 4, 3, 3, 2, 3, 5};

    int n= 6;
    for(int i=0;i<12;i++){
        vector<int>tmp;
        tmp.push_back(arr[i++]);
        tmp.push_back(arr[i]);
        roads.push_back(tmp);
    }
    // getGraph(n, roads);
    solution(n, roads);
}