#include <string>
#include <vector>
#include<iostream>

using namespace std;
int max =0;
int stack[500];
int ind = -1;
int n, totalStamp =0;

int getGraph(vector<vector<int>>& roads){
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

int DFS(vector<vector<int>> &roads){
    if(roads.size()==0)
        return 0;
    int target = stack[ind--];
    int endNode = 1;
    int answer = 0;
    for(vector<vector<int>>::iterator itr = roads.begin();itr!=roads.end()&&roads.size()>0;itr++){
        if((*itr)[0] == target){
            stack[++ind] = (*itr)[1];
            endNode =0;
            totalStamp++;
            roads.erase(itr);
            itr = roads.begin();
            answer += DFS(roads);
        }
    }
    if(endNode == 1 && totalStamp<n)
        answer++;

    return answer;
}
int getFront(vector<vector<int>>& roads){
    vector<vector<int>>::iterator itr = roads.begin();
    int front = (*itr)[0];
    itr++;
    for(;itr!=roads.end();itr++){
        if((*itr)[1] == front)
            front = (*itr)[0];
    }
    return front;
}
int solution(int n, vector<vector<int>> roads) {
    int answer = 0;
    int front = getFront(roads);
    stack[++ind] = front;
    totalStamp +=1;

    answer = DFS(roads);
    cout<<answer;
    return answer;
}

int main(){

}