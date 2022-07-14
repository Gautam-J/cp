/* DSA */
/* Time Complexity: O(nlogn) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

template<typename T> T gcd(T a, T b) { return ( b ? __gcd(a, b) : a); }
template<typename T> T lcm(T a, T b) { return (a * (b / gcd(a, b))); }

#define forn(i, l, r) for (int i = (int)l; i < (int)r; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
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

class Node {
public:
    char c;
    int freq;
    Node *left, *right;

    Node(){};

    Node(char c, int freq) {
        this->c = c;
        this->freq = freq;
        this->left = NULL;
        this->right = NULL;
    }
};

class Compare {
public:
    bool operator() (Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

Node* construct_huffman_tree(vector<char>& chars, vi& freqs) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    Node *temp, *left, *right;
    int n = sz(chars);
    forn(i, 0, n) {
        temp = new Node(chars[i], freqs[i]);
        minHeap.push(temp);
    }

    while (minHeap.size() > 1) {
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        temp = new Node('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        minHeap.push(temp);
    }

    return minHeap.top();
}

void encode_chars(Node* root, string s, map<char, string>& res) {
    if (root == NULL)
        return;

    if (root->c != '$')
        res[root->c] = s;

    encode_chars(root->left, s + "0", res);
    encode_chars(root->right, s + "1", res);
}

map<char, string> solve(vector<char>& chars, vi& freqs) {
    // Algorithm:
    // Constuct a node for each char-freq pair
    // Construct a min heap from the given pairs, sorted by freq
    // while size of min heap is greater than 1
    //     take out the first 2 nodes
    //     add their freq
    //     create a new node, and assign the newly calculated freq
    //     set left and right members of the new node
    //     push newly created node (i.e., tree) to min heap
    //
    // Last node in the min heap will be the root
    // Traverse from root to each leaf node, for each char
    // Add 0 for left traversal, 1 for right traversal
    //
    // Time: O(nlogn)
    // Space: O(n)

    map<char, string> res;

    Node* root = construct_huffman_tree(chars, freqs);
    encode_chars(root, "", res);

    return res;
}

int getStandardSize(vi& freqs) {
    int res = 0;
    trav(f, freqs)
        res += (8 * f);
    return res;
}

int getHuffmanSize(vector<char>& chars, vi& freqs, map<char, string>& res) {
    int ans = 0;
    int n = sz(chars);

    forn(i, 0, n)
        ans += (freqs[i] * sz(res[chars[i]]));

    return ans;
}

int getTotalBits(vector<char>& chars, vi& freqs, map<char, string>& res) {
    int ans = 8 * sz(chars);
    trav(p, res)
        ans += sz(p.second);
    ans += getHuffmanSize(chars, freqs, res);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<char> chars(n);
    trav(c, chars)
        cin >> c;
    vi freqs(n);
    trav(f, freqs)
        cin >> f;

    map<char, string> res = solve(chars, freqs);

    map<char, int> count;
    forn(i, 0, n)
        count[chars[i]] = freqs[i];

    cout << "Given chars and freqs:" << nl;
    trav(p, count)
        cout << p.first << ": " << p.second << nl;
    cout << nl;

    cout << "ASCII to Binary Encodings:" << nl;
    trav(c, chars)
        cout << c << ": " << bitset<8>(c) << nl;
    cout << nl;

    cout << "Huffman Encodings:" << nl;
    trav(p, res)
        cout << p.first << ": " << p.second << nl;
    cout << nl;

    cout << "Standard Encoding: " << getStandardSize(freqs) << " bits\n";
    cout << "Huffman Encoding: " << getHuffmanSize(chars, freqs, res) << " bits\n";
    cout << "Total bits needed: " << getTotalBits(chars, freqs, res) << " bits\n";

#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
