#include <iostream>
#include <string>
#include <bitset>
#include <cmath> // For log2
using namespace std;

// Function to generate the binary concatenated string for a given number n
string generateBinaryString(int n) {
    string binaryString = "";

    for (int i = 1; i <= n; ++i) {
        string binary = bitset<64>(i).to_string();           // Get 64-bit binary representation
        binary = binary.substr(binary.find('1'));           // Remove leading zeros
        binaryString += binary;                             // Append to the result
    }

    return binaryString;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    string binaryString = generateBinaryString(n);
    cout << "Binary Concatenated String: " << binaryString << endl;

    return 0;
}
