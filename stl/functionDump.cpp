
/****** Prime Number ********/
// Primality Check
// T.C = root(n);

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

// Generate list of primes
//T.C = n log(logn);
const int MAXN = 1e6;  // at max
vector<bool> sieve(MAXN + 1, true);

void generatePrimes() {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i <= MAXN; ++i) {
        if (sieve[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                sieve[j] = false;
            }
        }
    }
}

// Generate list of divisors of each number
//T.C = nlogn;
const int MAXN= 1e5; // at max
vector<bool> sieve(MAXN+1,true);
vector<vector<int>> divisors(MAXN+1);
void generatePrimes() {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) {
            for (int j = 2 * i; j <= MAXN; j += i) {
                divisors[j].push_back(i);
                sieve[j] = false;
            }
        }
    }
}


// DSU

class DisjointSet {
public:
    vector<int> parent,size;
    DisjointSet(int n) {
        size.resize(n+1,1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }


    bool unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return false;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        return true;
    }
};