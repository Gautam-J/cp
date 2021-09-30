/* Practice */
/*

*/

/* Time Complexity: O(n lg n) */
/* Space Complexity: O(n) */

#include <bits/stdc++.h>
#include <valarray>
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
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;

mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const char nl = '\n';
const double PI = acos(-1);

class Item {
public:
    int weight, value, id, valuePerWeight;

    Item(int w, int v, int _id) {
        weight = w;
        value = v;
        id = _id;
        valuePerWeight = value / weight;
    }

    bool operator <(const Item& i) {
        return valuePerWeight < i.valuePerWeight;
    }
};

string getFraction(int maxCapacity, int weight) {
    string fracString;
    fracString.append(to_string(maxCapacity));
    fracString.append("/");
    fracString.append(to_string(weight));

    return fracString;
}

void solve(int maxCapacity, vi& weights, vi& values) {
    vector<Item> items;

    int n = sz(weights);
    for (int i = 0; i < n; i++) {
        Item temp(weights[i], values[i], i);
        items.push_back(temp);
    }

    sort(items.rbegin(), items.rend());

    int frac, maxValue = 0;
    string fracString;
    vector<string> res(n, "0");
    trav(i, items) {
        if (maxCapacity - i.weight >= 0) {
            maxCapacity -= i.weight;
            res[i.id] = "1";
            maxValue += i.value;
        } else {
            frac = maxCapacity / i.weight;
            maxCapacity += (frac * i.valuePerWeight);
            res[i.id] = getFraction(maxCapacity, i.weight);
            break;
        }
    }

    cout << "Max Value: " << maxValue << nl;
    trav(i, res)
        cout << i << " ";
    cout << nl;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int maxCapacity, n, weight, value;
    cin >> maxCapacity >> n;

    vi w, v;
    for (int i = 0; i < n; i++) {
        cin >> weight >> value;
        w.push_back(weight);
        v.push_back(value);
    }

    solve(maxCapacity, w, v);


#ifdef _GLIBCXX_DEBUG
    cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
#endif

    return 0;
}
