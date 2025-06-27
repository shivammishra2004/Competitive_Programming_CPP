#include <iostream>
#include <bitset>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    
    for (int i = l; i <= r; i++) {
        string binary = bitset<32>(i).to_string();
        size_t first_one = binary.find('1');
        
        // Output the bit representation from the first '1' found to the end of the string
        cout << "Number: " << i << " => Bit Representation: " << binary.substr(first_one) << endl;
    }
}

int main() {
    solve();
    return 0;
}
