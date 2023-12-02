#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iterator>


using namespace std;
vector<string> numbers {"one", "two", "three", "four", "five", "six", 
                            "seven", "eight", "nine"};
map<string, int> num 
    {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };



int getCalibration(string str) {

    map<int, string> numOccurence;

    for(string s : numbers) 
    {
        size_t found = str.find(s);
        while(found != string::npos) 
        {
            numOccurence[found] = s;
            found = str.find(s, found+1);
        }
    }

    string itBegin = numOccurence.begin()->second;
    string itEnd = numOccurence.end()->second;
    cout << "first " << itBegin << "second " << itEnd << "\n";
    return stoi(to_string(num[itBegin])
            + to_string(num[itEnd]));

}


int main () {
    ifstream myfile;
    myfile.open("test");
    string str;
    int calibration;
    vector<int> allCalibrations {};
    while(getline(myfile,str)) 
    {
        calibration = getCalibration(str);
        allCalibrations.push_back(calibration);
    }
    cout << accumulate(allCalibrations.begin(), allCalibrations.end(),0);
    return 0;
    	    
}
