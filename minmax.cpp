/*
This program will use the "Current_Reservoir_Levels.tsv" to give the minimum and maximum storage in 2018.
*/

#include<iostream>
#include <fstream>
#include <cstdlib>
#include <climits>

using namespace std;
int main(){
    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    
    string head;
    getline(fin,head);
    string date;
    double eastStorage;
    double eastElevation;
    double westStorage;
    double westElevation;
    double max = INT_MIN;
    double min = INT_MAX;
    
    while(fin>> date>> eastStorage>> eastElevation>> westStorage>> westElevation) {
        // this loop reads the file line-by-line
        // extracting 5 values on each iteration
        fin.ignore(INT_MAX,'\n');
        //ignorring the remaining columns
        
        if(eastStorage>max){
            max = eastStorage;
        }
       
       if(eastStorage<min){
           min = eastStorage;
       }
   }
   
   cout << "Minimum storage in East Basin: " << min << " billion gallons"<< endl;
   cout << "Maximum storage in East Basin: " << max << " billion gallons"<< endl;
   return 0;
}
