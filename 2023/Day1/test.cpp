#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <map>

int main() {
    std::string str = "abcone2threexyz";
    std::string s = "one";

    size_t found = str.find(s);
    std::cout << found << "hej";
}
