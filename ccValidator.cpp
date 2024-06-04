/* This program focus on checking wheather the
provided Credit card number is Valid or not Not */

#include <iostream>
#include <string>
using namespace std;

bool ValidOrNot(const string& CCnumber)
{
    int sum = 0 ;
    bool alternate = false ;

    // here we use for loop to transverse the digits from left to right
    for (size_t i = CCnumber.size(); i-- > 0;) {
        int n = CCnumber[i] - '0';  // this converts character into number 
  
        if (alternate) {
            n *= 2; // it doubles every digit
            if (n > 9) // if doubling the digit results into number>9, it is substracted from 9
            {
                n -= 9;
            }
        }

        sum += n; // sum is them increased by n
        alternate = !alternate;
    }

    return (sum % 10 == 0); // returns true or false value

}

int main()
{
    string CCnumber; // initializing a variable for credit card number
    cout << "Enter your Credit Card Number: ";
    cin >> CCnumber ; // geting input for credit card number

    if (ValidOrNot(CCnumber))
    {
        cout << "The Credit Card Number provided here is Valid." ;
    }
    else{
        cout << "The Credit Card Number provided here is Not Valid." ;
    }

return 0;

}