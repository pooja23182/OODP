#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;

    cout << "Enter number of elements: ";
    cin >> N;

    // Uniform initialization with vector
    vector<int> arr(N);

    cout << "Enter " << N << " integer elements:\n";
    for (auto i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }

    cout << "\nElements are: ";
    for (auto value : arr)   // Range-based for loop
    {
        cout << value << " ";
    }

    auto sum = 0;

    for (auto value : arr)
    {
        sum += value;
    }

    // Explicit type conversion
    auto average = static_cast<double>(sum) / N;

    cout << "\nAverage = " << average << endl;

    // Conditional statement
    if (average >= 50)
        cout << "Pass" << endl;
    else
        cout << "Fail" << endl;

    return 0;
}