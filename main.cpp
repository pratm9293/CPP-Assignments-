#include <iostream>
#include <cmath> //We use this cmath.lib (cmath library) because we need to use the power function for calculating interest rate and gains financially

using namespace std;

int main()
{

    float amt;                                                      //float is for using decimals.
    float rate;
    float days;
    float total;


    cout << "Enter the percentage earned each day in decimals \n" << endl;                  //We ask the user the interest rate, amt of days, amt of money invested
    cin >> rate;
    cout << "Enter the worth of your investments starting \n" << endl;                      // and store them in variables
    cin >> amt;

    cout << "Enter how many days you were in the market \n" << endl;
    cin >> days;
        if(days<30){                                                                        // our condition is at least 30 days

            cout << "Sorry you need a contract of at least 30 days." << endl;
        }else{

            for(int d=1;d<=days;d++){                                 // we run the loop for however many days the user needs

            total = amt * pow(1 + rate, d);                           // the formula is the starting amt times the interest rate + 1 to the power of what day # it is.

            cout << "Your total money through investments after 30 days was: " << total << endl;    // printing the values
            cout << "Your investments earned you: " << total - amt << endl;                         // showing only the gains
    }
    }

}
/*
This is a stock market simulator for money earned at a specific rate
*/
