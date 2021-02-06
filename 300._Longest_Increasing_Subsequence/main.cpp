#include <bits/stdc++.h>

using namespace std;
// using std::cout
// namespace chrono = std::chrono;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define watch(x) cout << (#x) << " is " << (x) << endl
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FE(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
const double pi = acos(-1.0);
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

VI commaDelimVector(string s) {
    VI v;
    s.pop_back();
    stringstream ss(s.substr(1));
    while (ss.good()) {
        string ts;
        getline(ss, ts, ',');
        v.push_back(stoi(ts));
    }
    return v;
}

int lengthOfLIS_On2(VI& nums) {
    int n = nums.size();
    VI a(n, 1);
    REP(i, n) {
        REP(j, i) {
            if (nums[j] < nums[i]) {
                a[i] = max(a[i], a[j] + 1);
            }
        }
    }
    return *max_element(a.begin(), a.end());
}

int lengthOfLIS_Onlogn(VI& nums) {
    int n = nums.size();
    vector<int> d(n + 1, INF);
    d[0] = -INF;
    REP(i, n) {
        int j = upper_bound(d.begin(), d.end(), nums[i]) - d.begin();
        if (d[j - 1] < nums[i])
            d[j] = nums[i];
    }
    auto ans_it = upper_bound(d.rbegin(), d.rend(), INF, [](int a, int b) {
        return a > b;
    });
    return ans_it.base() - d.begin() - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    VI v;
    while (cin >> s) {
        v = commaDelimVector(s);
        cout << lengthOfLIS_Onlogn(v) << '\n';
    }
}