#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;


int getCalibration(string str) {
    vector<char> digits {};
    for(char& c : str) 
    {
        if(isdigit(c))  
        {
            digits.push_back(c);
        }
    }

    if(digits.size() == 1) {
        return stoi(string()+digits[0]+digits[0]);
    }
    return stoi(string()+digits[0]+digits[digits.size()-1]);
}



int main () {
    ifstream myfile;
    myfile.open("input");
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
