#include<iostream>
#include <vector>
#include <string>
#include <map>
#include <random>

using namespace std;
vector<int> choose_menu(string* names, map<string,vector<int> > todo_map);
int main(){
    std::string names[] = {"dp", "sort", "stack", "queue", "deck", "string", "etc",
     "match", "graph", "sort2", "gridy", "sort3", "all"};
    


}

vector<int> choose_menu(string* names, map<string,vector<int> > todo_map){
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

    return ttd;

}