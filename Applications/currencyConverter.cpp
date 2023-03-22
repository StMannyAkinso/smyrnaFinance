#include <iostream>
using namespace std;

int main()
{
    double gbp, usd, eur, naira;

    // Ask user for GBP input
    cout << "Enter the amount of GBP you want to convert: ";
    cin >> gbp;

    // GBP conversion rates
    usd = gbp * 1.39;
    eur = gbp * 1.17;
    naira = gbp * 616.36;

    // Display results
    cout << gbp << " GBP is equal to " << usd << " USD, " << eur << " EUR, and " << naira << " Naira." << endl;

    return 0;
}
