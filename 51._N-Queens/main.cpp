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

bool safe(VS board, size_t r, size_t c) {
    int s = board.size();

    REP(i, r) {
        if (board[i][c] == 'Q')
            return false;
    }

    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = r, j = c; i >= 0 && j < s; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;
}

void recurse(VS& tmp, vector<VS>& res, int r = 0) {
    int bS = tmp.size();
    if (r == bS) {
        res.push_back(tmp);
        return;
    }
    REP(i, bS) {
        if (safe(tmp, r, i)) {
            tmp[r][i] = 'Q';
            recurse(tmp, res, r + 1);
            tmp[r][i] = '.';
        }
    }
}

vector<VS> solveNQueens(int n) {
    VS tmp(n, string(n, '.'));
    vector<VS> ans;
    recurse(tmp, ans);
    return ans;
}

void printAns(vector<VS> ans) {
    cout << setw(11) << setfill('-') << '\n';
    REP(i, ans.size()) {
        REP(j, ans[i].size()) {
            cout << ans[i][j] << '\n';
        }
        if (i < (int)(ans.size() - 1))
            cout << "\n";
    }
    cout << setw(12) << setfill('-') << "\n\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    while (cin >> n) {
        printAns(solveNQueens(n));
    }
}