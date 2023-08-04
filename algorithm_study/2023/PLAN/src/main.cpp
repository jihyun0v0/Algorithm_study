#include<iostream>
#include <vector>
#include <string>
#include <map>
#include <random>
#include <fstream>
#include <algorithm>
using namespace std;

void get_vector(vector<int> &vc, int ind);
void get_todo(string* names);
void rewrite_file(vector<int> vc, int ind);
void solved(string *names);
void add_problem(string *names);
void print_probs(string* names);
void print_vc(vector<int> vc);
int main(){
    std::string names[] = {"dp", "sort", "stack", "queue", "deck", "string", "etc",
     "match", "graph", "sort2", "gridy", "sort3", "all"};

    map<string, vector<int>> todo_map;
    int menu;
    
    while(true){
        printf("============================\nselect your menu: \n");
        printf("1. get problems\n");
        printf("2. solved problems\n");
        printf("3. add problem\n");
        printf("4. show problems\n");
        printf("5. the end\n");
        printf("=>");
        cin>>menu;
        
        switch(menu){
            case 1:
                get_todo(names);
                break;
            case 2:
                solved(names);
                break;
            case 3: 
                add_problem(names);
                break;
            case 4:
                print_probs(names);
                break;
            case 5:
                exit(0);
        }
    }
}

void get_todo(string* names){
    int cate, num, size, random_ch;
    vector<int> ttd, td_list;

    cout<<"choose category and numbers: \n";
    for(int i=0;i<13;i++){
        printf("%d. ",i+1);
        cout<<names[i]<<endl;
    }
    printf("============================\n=>");
    cin>>cate;
    cate-=1;
    cin>>num;
    get_vector(td_list, cate);
    print_vc(td_list);
    size = td_list.size()-1;

    printf("\nrandom?(1:yes, 2:no)\n============================\n=>");
    scanf("%d", &random_ch);
    //random choice
    if(random_ch==1){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0,size);
    for (int i = 0; i < num; i++) {
        int j=dis(gen);
        ttd.push_back(td_list[j]);
    }
    }
    //not random
    else{
        for (int i = 0; i < num; i++) {
        ttd.push_back(td_list[i]);
        }
    }
    //print todo
    print_vc(ttd);

}

// void solved(string* names, map<string,vector<int> > todo_map);
void get_vector(vector<int> &vc, int ind){
    string str= "/Users/jihyunkyoung/Documents/Alogorithm_study/Algorithm_study/algorithm_study/2023/PLAN/file/todo";
    str= str+ to_string(ind);
    ifstream in(str);
    char tmp;

    //read {
    in.read(&tmp, 1);
    string s;
    while(in){
        getline(in, s,',');
        for(auto itr:s){
        if(!isdigit(itr)&&itr!=' '){
            return;
        }
       }   vc.push_back(stoi(s));
    }
    
}

void solved(string *names){
    vector<int> vc;
    int cate, num, conti=1;
    vector<int>::iterator itr;
    while(conti==1){
    printf("============================\n");
    printf("input the number of category that you solved: \n");
    for(int i=0;i<13;i++){
        printf("%d. ",i+1);
        cout<<names[i]<<endl;
    }
    printf("============================\n=>");
    cin>>cate;
    cate-=1;
    get_vector(vc, cate);
    print_vc(vc);
    printf("============================\nenter number of the problem that you solved \n=>");
    cin>>num;
    if(cate == 13){
        for(int i=0;i<12;i++){
            vector<int> tmp;
            get_vector(tmp,i);
            if(find(tmp.begin(), tmp.end(), num)!=tmp.end()){
                
                itr = find(tmp.begin(), tmp.end(), num);
                tmp.erase(itr);
                rewrite_file(tmp, i);
            }
        }
    }
    if(find(vc.begin(), vc.end(), num)!=vc.end()){
        itr = find(vc.begin(), vc.end(), num);
        vc.erase(itr);
        rewrite_file(vc, cate);
    }
    printf("============================\ndo you want to continue?(1: yes, 2:no)\n=>");
    cin>>conti;
}}
void print_vc(vector<int> vc){
    printf("============================\n");
    //print vc
    for(vector<int>::iterator itr = vc.begin();itr!=vc.end();itr++){
        printf("%d, ", *itr);
    }
    printf("\n");
    printf("size : %d\n", vc.size());
}
void add_problem(string *names){
    vector<int> vc;
    int cate, num, conti=1;
    vector<int>::iterator itr;
    while(conti==1){
    printf("============================\n");
    printf("input the number of category that you want to add: \n");
    for(int i=0;i<13;i++){
        printf("%d. ",i+1);
        cout<<names[i]<<endl;
    }
    printf("============================\n=>");
    cin>>cate;
    cate-=1;
    get_vector(vc, cate);
    printf("============================\nenter number of the problem that you want to add \n=>");
    cin>>num;
    vector<int> tmp;
    if(cate != 13){
        get_vector(tmp,cate);
        tmp.push_back(num);
        rewrite_file(tmp, cate);
    }
    get_vector(vc, 12);
    vc.push_back(num);
    rewrite_file(tmp, 12);
    
    printf("============================\ndo you want to continue?(1: yes, 2:no)\n=>");
    cin>>conti;
}
}
void print_probs(string* names){
    int cate;
    vector<int> vc;
    printf("============================\n");
    printf("input the number of category that you want to add: \n");
    for(int i=0;i<13;i++){
        printf("%d. ",i+1);
        cout<<names[i]<<endl;
    }
    printf("============================\n=>");
    cin>>cate;
    cate-=1;
    if(cate == 12){
        for(int i=0;i<12;i++){
            get_vector(vc, i);
            cout<<"========================"<<names[i];
            print_vc(vc);
        }
    }
    else {   
        get_vector(vc, cate);
        print_vc(vc);
}}
void rewrite_file(vector<int> vc, int ind){
    string str= "/Users/jihyunkyoung/Documents/Alogorithm_study/Algorithm_study/algorithm_study/2023/PLAN/file/todo";
    str= str+ to_string(ind);
    ofstream out(str);

    out<<"{";
    vector<int>::iterator itr;
    for(itr = vc.begin();(itr)!=vc.end();itr++)
        out<<to_string(*itr)<<", ";
    out<<"}";
}