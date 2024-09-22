#include <iostream>
#include <iomanip>

using namespace std;


double calculateWaterBill(int units) {
    double cost = 0.0; //double declaration caters for decimal points

    if (units <= 10) {
        cost = units * 150; // First 10 units
    } else if (units <= 20) {
        cost = (10 * 150) + ((units - 10) * 175); // Next 10 units
    } else {
        cost = (10 * 150) + (10 * 175) + ((units - 20) * 200); // Beyond 20 units
    }

    return cost;
}

// Function to Compute VAT and surcharge.
double applyCharges(double totalCost) {
    double surcharge = totalCost * 0.15; // 15/100% surcharge
    double vat = totalCost * 0.18; // VAT ie 18/100%
    return totalCost + surcharge + vat;
}

int main() {
    double loadedAmount;
    int waterUnits;
    char option;

    do {
    	//loop that asks the user to enter info and ontinue
        cout << "Enter the amount of money loaded onto your account (UGX): ";
        cin >> loadedAmount;
        
        cout << "Enter the number of water units consumed: ";
        cin >> waterUnits;

        // To compute the total water bill
        double totalCost = calculateWaterBill(waterUnits);
        
        double finalAmount = applyCharges(totalCost);

        if (finalAmount > loadedAmount) {
            cout << "Error: Insufficient balance." << endl;
            cout << "Remaining balance before usage: " << loadedAmount << " UGX" << endl;
        } else {
            // Deduct from balance and show remaining balance
            loadedAmount -= finalAmount;
            cout << fixed << setprecision(2);
            cout << "Total water bill: " << totalCost << " UGX" << endl;
            cout << "Final amount after charges: " << finalAmount << " UGX" << endl;
            cout << "Remaining balance after usage: " << loadedAmount << " UGX" << endl;
        }

       
        cout << "\nDo you want to make another transaction? (y/n): ";
        cin >>option;

    } while (option == 'y' || option == 'Y'); // Continue if user chooses 'y' or 'Y' , prompts user to continue or exit
    cout << "Thank you for using the water billing system!" << endl;

    return 0;
}
