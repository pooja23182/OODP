#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class ElectricityBill {
private:
    int consumerNumber;
    string consumerName;
    double unitsConsumed;
    double costPerUnit;

public:
    // Parameterized Constructor with Validation
    ElectricityBill(int cNum, string name, double units) {
        consumerNumber = cNum;
        consumerName = name;
        
        // Validation: Units cannot be negative
        if (units < 0) {
            cout << "Error: Units cannot be negative. Setting units to 0." << endl;
            unitsConsumed = 0;
        } else {
            unitsConsumed = units;
        }
    }

    // Function to compute total amount using Slab Rates
    double calculateBill() {
        double total = 0;

        if (unitsConsumed <= 100) {
            total = unitsConsumed * 1.5;
        } 
        else if (unitsConsumed <= 300) {
            // 100 units at 1.5 + remaining at 2.5
            total = (100 * 1.5) + (unitsConsumed - 100) * 2.5;
        } 
        else {
            // 100 units at 1.5 + 200 units at 2.5 + remaining at 4.0
            total = (100 * 1.5) + (200 * 2.5) + (unitsConsumed - 300) * 4.0;
        }
        return total;
    }

    // Display function
    void displayBill() {
        cout << "\n--- ELECTRICITY BILL DETAILS ---" << endl;
        cout << "Consumer No.   : " << consumerNumber << endl;
        cout << "Consumer Name  : " << consumerName << endl;
        cout << "Units Consumed : " << unitsConsumed << endl;
        cout << "--------------------------------" << endl;
        cout << "Total Amount   : $" << fixed << setprecision(2) << calculateBill() << endl;
        cout << "--------------------------------" << endl;
    }
};

int main() {
    // Creating object with parameterized data
    ElectricityBill myBill(10293, "Alice Smith", 350.5);

    // Displaying the final result
    myBill.displayBill();

    return 0;
}