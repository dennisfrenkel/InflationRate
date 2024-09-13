/* Dennis Frenkel
 * Inflation LAB 3
 * CISC 2010
 * Due Date: 18 September 2023
 */

#include <iostream>
using namespace std;
const int MAX_RATES = 20;

// Function to get CPI values
void getCPIvalues(float &old_cpi, float &new_cpi)
{
    // Enter the old and new CPI values
    do
    {
        cin >> old_cpi >> new_cpi;
        if (!(old_cpi > 0 && new_cpi > 0)) // Corrected the condition
        {
            cout << "Error: CPI values must be greater than 0.\n";
        }
    } while (!(old_cpi > 0 && new_cpi > 0)); // Removed the extra while loop
}

// Function to sort array
void sort_array(double cpi[MAX_RATES], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (cpi[j] > cpi[j + 1]) // Corrected the condition
                swap(cpi[j], cpi[j + 1]);
        }
    }
}

int main()
{
    float old_cpi, new_cpi, inflation_rate;
    double cpi[MAX_RATES]; // Changed the data type to double
    char attempt;
    float sum = 0, average; // Changed the data type to double
    int i = 0, p = 0;

    do
    {
        cout << "Enter the old and new consumer price indices: ";
        getCPIvalues(old_cpi, new_cpi);
        
        inflation_rate = ((new_cpi - old_cpi) / old_cpi) * 100;
        sum = sum + inflation_rate;
        if (i < MAX_RATES)
            cpi[p++] = inflation_rate;
        else
            break;

        cout << "Inflation rate is " << inflation_rate << endl;
        cout << "Try again? (y or Y): ";
        cin >> attempt;
        i++; // Increment i inside the loop
    } while (attempt == 'y' || attempt == 'Y');

    if (i > 0) // Check if i is greater than 0 to avoid division by zero
    {
        average = sum / i;
        cout << "Average rate is " << average << endl;
    }
    else
    {
        cout << "No valid CPI values entered." << endl;
    }

    sort_array(cpi, i);
    if (i % 2 == 1)
        cout << "Median rate is " << cpi[i / 2] << endl;
    else if (i > 0)
        cout << "Median rate is " << (cpi[i / 2] + cpi[(i - 1) / 2]) / 2 << endl;

    return 0;
}

double calcInflationRate(double old_cpi, double new_cpi)
{
    double result;
    if (old_cpi > 0 && new_cpi > 0)
    {
        result = ((new_cpi - old_cpi) / old_cpi) * 100;
        return result;
    }
    return 0;
}

/*Test Case:
 Enter the old and new consumer price indices: 238.343 238.250
 Inflation rate is -0.0390204
 Try again? (y or Y): y
 Enter the old and new consumer price indices: 238.250 237.852
 Inflation rate is -0.167049
 Try again? (y or Y): y
 Enter the old and new consumer price indices: 237.852 238.123
 Inflation rate is 0.113935
 Try again? (y or Y): n
 Average rate is -0.0307116
 Median rate is -0.0390204
 */
