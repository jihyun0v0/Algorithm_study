#include <iostream>

void sort(int begin, int end, int *arr);
int main(){
    int num;
    scanf("%d", &num);
    int* arr = new int[num];

    for(int i =0;i<num;i++){
        scanf("%d", &arr[i]);
    }

    sort(0, num,arr);

    for(int i =0;i<num;i++){
        printf("%d\n", arr[i]);
    }


}
void sort(int begin, int end, int *arr){
    if(begin>=(end-1))
        return;

    int num = end - begin;
    int mid = begin + num/2;
    sort(begin, mid, arr);
    sort(mid,end, arr);
    
    int *arr2 = new int[num];
    int i = begin;
    int j = mid;
    int k=0;
  
    while(i<mid&&j<end){
        while(arr[j]> arr[i]&&i<mid&&j<end){
            arr2[k++] = arr[i++];
        }
        while(arr[j]<=arr[i]&&i<mid&&j<end){
            arr2[k++] = arr[j++];
        }
    }
    if(j<end)
        while(j<end){
            arr2[k++] = arr[j++];
        }
    else if(i<mid)
        while(i<mid){
            arr2[k++] = arr[i++];
        }

    i =0;
    for(int k = begin;k<(end);k++){
        arr[k] = arr2[i++];
    }

}