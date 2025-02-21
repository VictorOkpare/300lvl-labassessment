#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1. Factorial Calculation 
int factorial(int n) {
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return -1;
    }
    if (n == 0) return 1; // Base case: factorial of 0 is 1
    return n * factorial(n - 1);
}

// 2. Fibonacci Sequence 
int fibonacci(int n, vector<int>& memo) {
    if (n < 0) return -1; // Base case: Negative numbers are not valid
    if (n <= 1) return n; // Base cases: F(0) = 0, F(1) = 1
    if (memo[n] != -1) return memo[n]; // Use cached value
    return memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
}

// 3. String Reversal
string reverseString(string str) {
    if (str.empty()) return ""; // Base case: empty string remains empty
    if (str.length() == 1) return str; // Base case: single character remains the same
    return reverseString(str.substr(1)) + str[0]; // Recursive case
}

// 4. Binary Search 
int binarySearch(const vector<int>& arr, int low, int high, int target) {
    if (arr.empty()) return -1; // Base case: empty array
    if (low > high) return -1; // Base case: target not found

    int mid = low + (high - low) / 2;
    if (arr[mid] == target) return mid; // Base case: target found

    return (arr[mid] > target) ? 
        binarySearch(arr, low, mid - 1, target) : 
        binarySearch(arr, mid + 1, high, target);
}

int main() {
    // Factorial Tests
    cout << "Factorial of 5: " << factorial(5) << endl; // Output: 120
    cout << "Factorial of 0: " << factorial(0) << endl; // Output: 1
    cout << "Factorial of -3: " << factorial(-3) << endl; // Output: Error message

    // Fibonacci Tests
    vector<int> memo(10, -1); 
    cout << "Fibonacci(5): " << fibonacci(5, memo) << endl; 
    cout << "Fibonacci(0): " << fibonacci(0, memo) << endl; 
    cout << "Fibonacci(-2): " << fibonacci(-2, memo) << endl; 

    // String Reversal Tests
    cout << "Reverse of 'hello': " << reverseString("hello") << endl; 
    cout << "Reverse of '   ': " << reverseString("   ") << endl;
    cout << "Reverse of '': " << reverseString("") << endl; 

    // Binary Search Tests
    vector<int> arr = {2, 4, 6, 8, 10, 12, 14};
    cout << "Binary search for 8: " << binarySearch(arr, 0, arr.size() - 1, 8) << endl;
    cout << "Binary search for 14: " << binarySearch(arr, 0, arr.size() - 1, 14) << endl; 
    cout << "Binary search for 1: " << binarySearch(arr, 0, arr.size() - 1, 1) << endl; 
    cout << "Binary search in an empty array: " << binarySearch({}, 0, 0, 5) << endl; 

    return 0;
}
