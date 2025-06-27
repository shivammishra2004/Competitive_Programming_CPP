#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
        i += 6;
    }
    return true;
}

std::string finalBulbState(int n) {
    if (isPrime(n))
        return "On";  // Prime number, same state
    else
        return "Off"; // Not a prime number, opposite state
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    while(n--){
    int numBulbs;
    cin >> numBulbs;
    if(numBulbs){
        string finalState = finalBulbState(numBulbs);
        cout << finalState << std::endl;
    }
    }
    cout << "off";


    return 0;
}
