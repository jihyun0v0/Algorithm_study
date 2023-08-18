#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

vector <vector<int>> city;

void search_bomb(int x, int y, int n);

int main(){
    int n, i,j;
    char ch;
    cin>>n;
  
    
   
    vector <int> v;
    for(j=0;j<n;j++){
        v.clear();
        for(i=0;i<n;i++){
            cin>>ch;
            v.push_back(ch);
        }
    city.push_back(v);
    }
    
    
    for(j=0;j<n;j++)
        for(i=0;i<n;i++)
            if(city[j][i]=='O')
                search_bomb(j, i, n);
    
    
    for(j=0;j<n;j++){
        for(i=0;i<n;i++)
            switch (city[j][i]) {
                case -1:
                    cout<<".";
                    break;
                case '.':
                    cout<<"B";
                    break;
                case 'X':
                    cout<<"X";
                    break;
                case 'O':
                    cout<<"O";
                    break;
            }
            cout<<endl;
        }
    
}


void search_bomb(int x, int y, int n){
    int i;

    for(i=1;(y-i)>=0&&city[x][y-i]!=88&&city[x][y-i]!=79;i++)city[x][y-i]=-1;
    for(i=1;(y+i)<n&&city[x][y+i]!=88&&city[x][y+i]!=79;i++)city[x][y+i]=-1;

    for(i=1;(x-i)>=0&&city[x-i][y]!=88&&city[x-i][y]!=79;i++)city[x-i][y]=-1;
    for(i=1;(x+i)<n&&city[x+i][y]!=88&&city[x+i][y]!=79;i++)city[x+i][y]=-1;
       
    
    return;
}
