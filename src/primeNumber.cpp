/* CCC */
/*
Given a number, find out if it is a prime or not.
*/

/* Time Complexity: O(sqrt(n)) or to find all prime numbers till n, O(n * log(log(n))) */
/* Space Complexity: O(1) or to find all prime numbers till n, O(n) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, n) for (int i = 0; i < n; i++)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; i++)
#define trav(i, a) for (auto& i : a)
#define allit(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define SHUF(v) shuffle(all(v), mt_rand)
#define umap unordered_map
#define uset unordered_set
#define imax INT_MAX
#define imin INT_MIN

#ifdef _GLIBCXX_DEBUG
#define debug(...) cerr << "[DEBUG]: [" << #__VA_ARGS__ << "]:", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

const char nl = '\n';
/* const ld PI = acos(-1.0); */

bool isPrime1(int n) {
    // naive brute force
    // Time Complexity: O(n)

    if (n == 0 || n == 1)
        return false;

    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool isPrime2(int n) {
    // 2 is the only even prime number, thus check for odd factors
    // Time Complexity: O(n / 2) = O(n)

    if (n == 0 || n == 1)
        return false;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i < n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool isPrime3(int n) {
    // i * i < n, or i < sqrt(n), thus runs in O(sqrt(n)) time
    // Time Complexity: O(sqrt(n / 2)) = O(sqrt(n))

    if (n == 0 || n == 1)
        return false;

    if (n % 2 == 0)
        return false;

    for (int i = 3; i * i < n; i += 2) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool isPrime4(int n) {
    // simplified version of isPrime3
    // Time Complexity: O(sqrt(n))

    if (n == 0 || n == 1)
        return false;

    for (int i = 2; i * i < n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool sieveOfEratosthenes(int n) {
    // Time Complexity: O(n * log(log(n)))
    // Space Complexity: O(n)

    bool primes[n + 1];
    memset(primes, true, sizeof(primes));

    primes[0] = false;
    primes[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (primes[i]) {
            // update all multiples of i, starting from square of i, to n
            for (int j = i * i; j <= n; j += i)
                primes[j] = false;
        }
    }

    // primes contain all prime number from 0 to n
    return primes[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << (isPrime1(n) ? "YES" : "NO") << nl;
    cout << (isPrime2(n) ? "YES" : "NO") << nl;
    cout << (isPrime3(n) ? "YES" : "NO") << nl;
    cout << (isPrime4(n) ? "YES" : "NO") << nl;
    cout << (sieveOfEratosthenes(n) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
