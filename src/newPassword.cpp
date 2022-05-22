/* KS - C 2022 */
/*
A company named Gooli has issued a new policy that their employees account passwords must contain:
At least 7
7
 characters.
At least one uppercase English alphabet letter.
At least one lowercase English alphabet letter.
At least one digit.
At least one special character. There are four special characters: #, @, *, and &.
The company has asked all the employees to change their passwords if the above requirements are not satisfied. Charles, an employee at Gooli, really likes his old password. In case his old password does not satisfy the above requirements, Charles will fix it by appending letters, digits, and special characters. Can you help Charles to find the shortest possible new password that satisfies his company's requirements?
Input
The first line of the input gives the number of test cases, T
T
. T
T
 test cases follow. Each test case consists of two lines. The first line of each test case contains an integer N
N
, denoting the length of the old password. The second line of each test case contains the old password of length N
N
. Old password contains only digits, letters, and special characters.
Output
For each test case, output one line containing Case #x
x
: y
y
, where x
x
 is the test case number (starting from 1) and y
y
 is a valid new password, obtained by possibly fixing the old password in the way that Charles wants and satisfying the company's requirements.
It is guaranteed that at least one solution exists. If there are multiple solutions, you may output any one of them.
Limits
Time limit: 20 seconds.
Memory limit: 1 GB.
1²T²100
1
²
T
²
100
.
Test Set 1
7²N²104
7
²
N
²
10
4
.
The old password contains only digits.
Test Set 2
1²N²104
1
²
N
²
10
4
.
The old password contains only digits, letters, and special characters.
Sample
Note: there are additional samples that are not run on submissions down below.
Sample Input
save_alt
content_copy
2
7
1234567
10
1111234567
Sample Output
save_alt
content_copy
Case #1: 1234567aA&
Case #2: 1111234567@Rc
In Sample Case #1, the old password does not satisfy requirements 2
2
, 3
3
, and 5
5
. One possible shortest new password is 1234567aA&.
In Sample Case #2, the old password does not satisfy requirements 2
2
, 3
3
, and 5
5
. One possible shortest new password is 1111234567@Rc.

Additional Sample - Test Set 2
The following additional sample fits the limits of Test Set 2. It will not be run against your submitted solutions.
Sample Input
save_alt
content_copy
3
1
A
2
1*
7
1234aB&
Sample Output
save_alt
content_copy
Case #1: Aa1*111
Case #2: 1*abAA*
Case #3: 1234aB&
In Sample Case #1, the old password does not satisfy requirements 1
1
, 3
3
, 4
4
, and 5
5
. One possible shortest new password is Aa1*111.
In Sample Case #2, the old password does not satisfy requirements 1
1
, 2
2
, and 3
3
. One possible shortest new password is 1*abAA*.
In Sample Case #3, the old password already meets all the requirements so Charles does not have to change his password.
*/

/* Time Complexity: O() */
/* Space Complexity: O() */

#include <bits/stdc++.h>
#include <cctype>
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

string solve(string& s) {
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSplChar = false;

    trav(i, s) {
        if (isupper(i)) {
            hasUpper = true;
            break;
        }
    }

    trav(i, s) {
        if (islower(i)) {
            hasLower = true;
            break;
        }
    }

    trav(i, s) {
        if (isdigit(i)) {
            hasDigit = true;
            break;
        }
    }

    trav(i, s) {
        switch (i) {
            case '#':
            case '@':
            case '*':
            case '&':
                hasSplChar = true;
                break;
        }
    }

    if (!hasUpper)
        s += 'A';
    if (!hasLower)
        s += 'a';
    if (!hasDigit)
        s += '1';
    if (!hasSplChar)
        s += '*';

    int n = sz(s);
    if (n < 7) {
        do {
            s += 'a';
            n++;
        } while (n < 7);
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, n;
    cin >> T;

    string oldPassword;
    fore(t, 1, T) {
        cin >> n;
        cin >> oldPassword;

        cout << "Case #" << t << ": " << solve(oldPassword) << nl;
    }

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
