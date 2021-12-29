
/*
This program will use the "Current_Reservoir_Levels.tsv" to find out the east basin storage during the given date.
*/

#include<iostream>
#include<fstream>
#include <cstdlib>
#include <climits>

using namespace std;

int main() {
    string date;
    double eastSt,eastEl,westSt,westEl;
    string userdate;
    cout<<"Enter date: ";
    cin>>userdate;
    ifstream fin("Current_Reservoir_Levels.tsv");
    
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); // exit if failed to open the file
    }
    
    string junk; // new string variable
    getline(fin, junk);
    
    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration
        fin.ignore(INT_MAX, '\n'); //skips to the end of line,
        //ignorring the remaining columns
        if(date==userdate) {
            cout<<"East basin storage: "<<eastSt<<" gallons"<<endl;
            break;
        }
    }
    
    fin.close();
    return 0;
    
}
