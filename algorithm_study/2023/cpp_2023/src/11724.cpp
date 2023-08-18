#include <stdio.h>
#include<vector>
using namespace std;
void DFS(int* stack, int** list, int *index, int n, int* sch, int* searched);
int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int **list= new int*[n+1];
    for(int i=0;i<=n;i++)
        list[i] = new int[n+1];

    int *stack= new int[n];
    int index=-1;

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
    int sch = 0;
    int *searched= new int[n+1];
    for(int i=0;i<=n;i++)
        (searched)[i] = 0;
    int i=1;
    int num =0;
    while(sch<n){
        if(searched[i]==0){
            stack[++index] = i;
            searched[i]=1;
            sch++;
            DFS(stack, list, &index, n, &sch, searched);
            num ++;
        }
        i++;
    }

    printf("%d\n", num);

}

void DFS(int* stack, int** list, int* index, int n, int * sch, int* searched){
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
                searched[i] = 1;
                (*sch)++;
                DFS(stack, list, (index), n, sch, searched);
            }
        }
    }

}
