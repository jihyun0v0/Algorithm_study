#include <stdio.h>
#include<vector>
using namespace std;
void DFS(int* stack, int** list, int *index, int n);
void BFS(int* queue, int** list, int* top, int* bot, int n);
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
    int index=0;
    stack[index] = st;
    int *queue = new int[n];
    int top=1, bot=0;
    queue[bot] = st;

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

    DFS(stack, list, &index, n);
    BFS(queue, list, &top, &bot, n);
    for(int i=0;i<=index;i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
    for(int i=0;i<top;i++){
        printf("%d ", queue[i]);
    }
    printf("\n");

}

void DFS(int* stack, int** list, int* index, int n){
    int target = stack[(*index)];
    int i=1;
    for(int i=1;i<n+1;i++){
        if(list[target][i]==1){
            int j;
            for(j=0;j<=(*index);j++){
                if(stack[j]==i)
                    break;
            }
            if(j==((*index)+1)){
            stack[++(*index)] = i;
            DFS(stack, list, (index), n);
            }
        }
    }

}

void BFS(int* queue, int** list, int* top, int* bot, int n){
    int target = queue[(*bot)++];
    int j;
    for(int i=1;i<=n;i++){
        if(list[target][i]==1){
            for(j=0;j<(*top);j++)
                if(i == queue[j])
                    break;
            if(j==(*top))
                queue[(*top)++] = i;            
        }
    }
    if((*top)>(*bot))
        BFS(queue,list, top, bot, n);

}