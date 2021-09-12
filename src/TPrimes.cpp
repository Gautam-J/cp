/* CF - 1300 */
/*
B. T-primes
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
We know that prime numbers are positive integers that have exactly two distinct positive divisors. Similarly, we'll call a positive integer t Т-prime, if t has exactly three distinct positive divisors.

You are given an array of n positive integers. For each of them determine whether it is Т-prime or not.

Input
The first line contains a single positive integer, n (1 ≤ n ≤ 105), showing how many numbers are in the array. The next line contains n space-separated integers xi (1 ≤ xi ≤ 1012).

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is advised to use the cin, cout streams or the %I64d specifier.

Output
Print n lines: the i-th line should contain "YES" (without the quotes), if number xi is Т-prime, and "NO" (without the quotes), if it isn't.

Examples
inputCopy
3
4 5 6
outputCopy
YES
NO
NO
Note
The given test has three numbers. The first number 4 has exactly three divisors — 1, 2 and 4, thus the answer for this number is "YES". The second number 5 has two divisors (1 and 5), and the third number 6 has four divisors (1, 2, 3, 6), hence the answer for them is "NO".

Only the square of a prime number can be a tPrime. Thus, find all prime
numbers from 2 - sqrt(10^12), i.e., 10^6, and store their squares.
Compare the input with the stored squares of primes.
*/

/* Time Complexity: O(n) approximately */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)

#ifdef _GLIBCXX_DEBUG
#define debug(x) cerr << "\e[91m"<<"[DEBUG] "<<__func__<<":"<<__LINE__<<" [" << #x << "] = [" << x << "]" << "\e[39m" << '\n';
#else
#define debug(x)
#endif

typedef long long ll;
typedef vector<int> vi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

bool solve(ll n) {
    // Time Limit Exceeds.

    ll nDiv = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            nDiv++;
        }
    }

    return (nDiv == 3);
}

vector<ll> sieveOfEratosthenes(ll n) {
    vector<ll> tPrimes;

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));  // initialize with true values

    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            // all multiples of i, starting from square of it are not prime
            for (ll j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    for (ll k = 2; k <= n; k++) {
        if (prime[k])
            tPrimes.push_back(k * k);
    }

    return tPrimes;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<ll> a(t);
    trav(i, a)
        cin >> i;

    ll maxElement = *max_element(all(a));
    vector<ll> tPrimes = sieveOfEratosthenes(sqrt(maxElement));

    trav(i, a) {
        cout << (binary_search(all(tPrimes), i) ? "YES" : "NO") << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
