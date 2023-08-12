//
//  plan_gen.cpp
//  PLAN
//
//  Created by Jihyun Kyoung on 2023/08
//
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main() {
    // Create a map with sample data
    int todo[13][130] = {{1463, 11726, 11727, 9095, 10844, 11057, 2193, 9465, 2156, 11053,
     11055, 11722, 11054, 1912, 2579, 1699, 2133, 9461, 2225, 2011, 11052},
     {2751, 11650, 11651, 10814, 10825, 10989, 11652, 11004},
     {10828, 9012, 10799},
     {10845, 10866},
     {10808, 10809, 10820, 2743, 11655, 10824, 11656},
     {1406, 1158, 1168},
     {10430, 2609, 1934, 1850, 9613, 11005, 2745, 
     1373, 1212, 2089, 11576, 1978, 1929, 11653, 10872, 1676, 2004, 6588},
     {1260, 11724, 1707, 10451, 2331, 9466, 2667, 4963, 7576, 2178, 2146, 1991, 11725, 1167, 1967},
     {1654, 2805, 2110, 10815, 10816, 11662},
     {11728,1780,11729,1992,2447,2448,1517,2261 },
     {11047, 2875, 10610, 1783, 1931, 11399, 2873, 1744},
     {1476, 1107, 1451, 9095, 10819, 10971, 1697, 1963, 9019, 1525, 2251, 2186, 3108, 
     5014, 1759, 2580, 1987, 6603, 1182, 2003, 1806, 1644, 1261, 1208, 7453, 2632, 2143}
     };

    std::string names[] = {"all", "deck", "dp", "etc", "graph", "gridy", "match", "queue",
     "sort", "sort2", "sort3", "stack", "string"};
    vector<int> done;

    map<string, vector<int>> todo_map;
    
    for(int i=0, k=0;i<12;i++){
        int j=0;
        while(todo[i][j]!=0)
            todo[12][k++] =todo[i][j++];
    }

    for(int i=0;i<13;i++){
        vector<int> *tmp = new vector<int>;
        int j=0;
        while(todo[i][j]!=0){
            tmp->push_back(todo[i][j++]);
        }
        todo_map.insert(pair<string, vector<int> >(names[i], *tmp));
        delete tmp;
    }

    // Specify the CSV file path
    std::string filename = "/Users/jihyunkyoung/Documents/Alogorithm_study/Algorithm_study/algorithm_study/2023/PLAN/file/data.csv";

    // Open the file for writing
    std::ofstream outputFile(filename);

    // Write data to the file in CSV format
    for (const auto& entry : todo_map) {
        outputFile << entry.first << ",";
        for (size_t i = 0; i < entry.second.size(); ++i) {
            outputFile << entry.second[i];
            if (i != entry.second.size() - 1) {
                outputFile << ",";
            }
        }
        outputFile << "\n";
    }

    // Close the file
    outputFile.close();

    std::cout << "Data transferred to " << filename << " successfully.\n";

    return 0;
}
