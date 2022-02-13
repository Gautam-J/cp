/* CF - 800 */
/*
A. Haiku
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Haiku is a genre of Japanese traditional poetry.

A haiku poem consists of 17 syllables split into three phrases, containing 5, 7 and 5 syllables correspondingly (the first phrase should contain exactly 5 syllables, the second phrase should contain exactly 7 syllables, and the third phrase should contain exactly 5 syllables). A haiku masterpiece contains a description of a moment in those three phrases. Every word is important in a small poem, which is why haiku are rich with symbols. Each word has a special meaning, a special role. The main principle of haiku is to say much using a few words.

To simplify the matter, in the given problem we will consider that the number of syllable in the phrase is equal to the number of vowel letters there. Only the following letters are regarded as vowel letters: "a", "e", "i", "o" and "u".

Three phases from a certain poem are given. Determine whether it is haiku or not.

Input
The input data consists of three lines. The length of each line is between 1 and 100, inclusive. The i-th line contains the i-th phrase of the poem. Each phrase consists of one or more words, which are separated by one or more spaces. A word is a non-empty sequence of lowercase Latin letters. Leading and/or trailing spaces in phrases are allowed. Every phrase has at least one non-space character. See the example for clarification.

Output
Print "YES" (without the quotes) if the poem is a haiku. Otherwise, print "NO" (also without the quotes).

Examples
inputCopy
on  codeforces
beta round is running
   a rustling of keys
outputCopy
YES
inputCopy
how many gallons
of edo s rain did you drink
                                cuckoo
outputCopy
NO
*/

/* Time Complexity: O(n) */
/* Space Complexity: O(1) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define FOR(i, n) for (int i = 0; i < n; i++)
#define all(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define trav(i, a) for (auto& i : a)
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< pi > vpi;

// mt19937_64 for 64 bit random numbers
mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());

bool isVowel(char i) {
    return (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u');
}

bool solve(string& s1, string& s2, string& s3) {
    int cnt;

    cnt = 0;
    trav(i, s1) {
        if (isVowel(i))
            cnt++;
    }
    if (cnt != 5)
        return false;

    cnt = 0;
    trav(i, s2) {
        if (isVowel(i))
            cnt++;
    }
    if (cnt != 7)
        return false;

    cnt = 0;
    trav(i, s3) {
        if (isVowel(i))
            cnt++;
    }
    if (cnt != 5)
        return false;

    return true;
}

const char nl = '\n';
const double PI = acos(-1);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);

    cout << (solve(s1, s2, s3) ? "YES" : "NO") << nl;

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
