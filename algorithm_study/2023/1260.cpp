#include <stdio.h>
#include<vector>
using namespace std;
void DFS(int* stack, int** list, int index, int n);

int main(){
    int n, m, st;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &st);
    // vector<vector<int>> list;
    // vector<int> **list = new vector<int>[n];
    // int  list[1001][1000];
    int **list= new int*[n+1];
    for(int i=0;i<=n;i++)
        list[i] = new int[n+1];

    int *stack= new int[n];
    int *result = new int[n];
    for(int i=0;i<n+1;i++)
    for(int j=0;j<n+1;j++)
        list[i][j] = 0;
   
    int tmp1, tmp2;

    for(int i=0;i<m;i++){
        scanf("%d", &tmp1);
        scanf("%d", &tmp2);
        list[tmp1][tmp2] = 1;
        list[tmp2][tmp1] = 1;
    }
    stack[0] = st;
    DFS(stack, list, 0, n);
for(int i=0;i<n;i++)
    printf("%d ", stack[i]);

}

void DFS(int* stack, int** list, int index, int n){
    int target = stack[index];
    int i=1;
    for(int i=1;i<n+1;i++){
        if(list[target][i]==1){
            for(int j=0;j<index;j++){
                if(stack[j]==i)
            }

            stack[++index] = i;
            DFS(stack, list, index, n);
        }
    }

}