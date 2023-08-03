#include<iostream>
#include <vector>
#include <string>
#include <map>
#include <random>

using namespace std;
void get_todo(string* names, map<string,vector<int> > &todo_map);
int main(){
    std::string names[] = {"dp", "sort", "stack", "queue", "deck", "string", "etc",
     "match", "graph", "sort2", "gridy", "sort3", "all"};

    map<string, vector<int>> todo_map;
    int menu;
    FILE* fp = fopen("/Users/jihyunkyoung/Documents/Alogorithm_study/Algorithm_study/algorithm_study/2023/PLAN/file/todo", "rb");
    fread(&todo_map, sizeof(todo_map),1, fp);
    while(true){
        printf("select your menu: \n");
        printf("1. get problems\n");
        printf("2. solved problems\n");
        printf("3. add problem\n");
        printf("4. the end\n");

        cin>>menu;
        
        switch(menu){
            case 1:
                get_todo(names, todo_map);
                break;
            case 2:
                // solved(names, todo_map);
                break;
            case 3: 
                break;
            case 4:
                exit(0);
        }
    }
    get_todo(names, todo_map);
    fclose(fp);
}

void get_todo(string* names, map<string,vector<int> > &todo_map){
    int cate, num, size;
    vector<int> ttd, td_list;

    cout<<"원하는 카테고리와 갯수 선택: \n ";
    for(int i=0;i<12;i++){
        printf("%d. ",i+1);
        cout<<names[i]<<endl;
    }
    printf("--------------------\n");
    cin>>cate;
    cate-=1;
    cin>>num;
    td_list = todo_map[names[cate]];
    size = td_list.size()-1;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,size);


    for (int i = 0; i < num; i++) {
        int j=dis(gen);
        ttd.push_back(td_list[i]);
    }
    int i=0;
    for(vector<int>::iterator itr = ttd.begin();itr!=ttd.end();itr++, i++){
        printf("%d. %d\n", i++, *itr);
    }
}

// void solved(string* names, map<string,vector<int> > todo_map);