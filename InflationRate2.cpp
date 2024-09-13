//
//  main.cpp
//  InflationRate.cpp
//
//  Created by Dennis Frenkel on 9/6/23.
//
#include <iostream>
using namespace std;

/*
 * calcInflationRate - calculates the inflation rate given the old and new consumer price index (both must be greater than 0)
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently
 * @returns the computed inflation rate or 0 if inputs are invalid.
 */
double calcInflationRate(double old_cpi, double new_cpi);

int main()   //C++ programs start by executing the function main
{
    // TODO #1: declare two float variables for the old consumer price index (cpi) and the new cpi
    float old_cpi, new_cpi, inflation_rate;
    char attempt;
    float sum = 0, average;
    int i = 0;
    // TODO #2: Read in two float values for the cpi and store them in the variables
    do
    {
        cout << "Enter the old and new consumer price indices: ";
        cin >> old_cpi >> new_cpi;
        // TODO #3: call the function calcInflationRate with the two cpis
        inflation_rate = calcInflationRate(old_cpi, new_cpi);
        // TODO #4: print the results
        cout << "Inflation rate is " << inflation_rate << endl;
        if(inflation_rate !=0)
            i++;
        sum = sum + inflation_rate;
        // user enters to continue or end
        cout << "Try again? (y or Y): ";
        cin >> attempt;
    }
    while (attempt == 'y' || attempt == 'Y');
    average = sum/ i;
    cout << "Average rate is " << average;
    
    return 0;
}
    

// double calcInflationRate(float old_cpi, float new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or 0 for invalid inputs
double calcInflationRate(double old_cpi, double new_cpi)
{
   // TODO: Implement InflationRate to calculate the percentage increase or decrease
   //(new_cpi - old_cpi) / old_cpi * 100
    
    double results;
    if (old_cpi > 0 && new_cpi > 0)
    {
        results = (new_cpi - old_cpi) / old_cpi * 100;
        return results;
    }
    return 0;
}

 /* Test Case
  Enter the old and new consumer price indices:  238.343 238.250
  Inflation rate is -0.0390204
  Try again? (y or Y) y
  Enter the old and new consumer price indices: 238.250 237.852
  Inflation rate is -0.167888
  Try again? (y or Y) n
  The Average rate is -0.103454
*/
