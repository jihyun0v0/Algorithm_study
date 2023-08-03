#include <fstream>
#include <iostream>
// #include <map>
// #include <nlohmann/json.hpp>

// struct Person {
//     std::string name;
//     int age;
// };

// void to_json(nlohmann::json& j, const Person& p) {
//     j = nlohmann::json{{"name", p.name}, {"age", p.age}};
// }

// void from_json(const nlohmann::json& j, Person& p) {
//     j.at("name").get_to(p.name);
//     j.at("age").get_to(p.age);
// }

// int main() {
//     std::map<std::string, Person> myMap = {
//         {"Alice", {"Alice", 25}},
//         {"Bob", {"Bob", 30}},
//         {"Charlie", {"Charlie", 35}}
//     };

//     nlohmann::json j = myMap;

//     std::ofstream outfile("output.json");
    
//     if (outfile.is_open()) {
//         outfile << j.dump(2); // pretty print with 2 spaces
//         outfile.close();
//     }
// }

int main(){
    printf("hello world!");
}