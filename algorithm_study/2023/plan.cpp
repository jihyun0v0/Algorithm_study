#include<iostream>
#include <vector>
using namespace std;

int main(){
    int todo1[] = {1463, 11726, 11727, 9095, 10844, 11057, 2193, 9465, 2156, 11053, 11055, 11722, 11054, 1912, 2579, 1699, 2133, 9461, 2225, 2011, 11052};
    int todo2[] = {2751, 11650, 11651, 10814, 10825, 10989, 11652, 11004};
    int todo3[] = {10828, 9012, 10799};
    int todo4[] = {10845, 10866};
    int todo5[] = {10808, 10809, 10820, 2743, 11655, 10824, 11656};
    int todo6[] = {1406, 1158, 1168};
    int todo7[] = {10430, 2609, 1934, 1850, 9613, 11005, 2745, 1373, 1212, 2089, 11576, 1978, 1929, 11653, 10872, 1676, 2004, 6588};
    int todo8[] =   {1260, 11724, 1707, 10451, 2331, 9466, 2667, 4963, 7576, 2178, 2146, 1991, 11725, 1167, 1967};
    int todo9[] = {1654, 2805, 2110, 10815, 10816, 11662};
    int todo10[] = {11728,1780,11729,1992,2447,2448,1517,2261 };
    int todo11[]={11047, 2875, 10610, 1783, 1931, 11399, 2873, 1744};
    int todo12[]={1476, 1107, 1451, 9095, 10819, 10971, 1697, 1963, 9019, 1525, 2251, 2186, 3108, 5014, 1759, 2580, 1987, 6603, 1182, 2003, 1806, 1644, 1261, 1208, 7453, 2632, 2143};

    vector<int> done;

    int* all;
    int sum = sizeof(todo1)+ sizeof(todo2)+ sizeof(todo3)+ sizeof(todo4)+ sizeof(todo5)+ sizeof(todo6)+ sizeof(todo7)+ sizeof(todo8)+ sizeof(todo9)+ sizeof(todo10)+ sizeof(todo11)+ sizeof(todo12);
    sum = sum/sizeof(int);
    all = new int[sum];

    int perDay = sum/5;
    for(int i=0;i<5;i++)
    done.push_back(todo1[i]);
    done.push_back(todo2[0]);
    done.push_back(todo3[0]);


}