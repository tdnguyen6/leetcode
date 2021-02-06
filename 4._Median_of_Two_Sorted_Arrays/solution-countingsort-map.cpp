#include <bits/stdc++.h>

using namespace std;
// using std::cout
// namespace chrono = std::chrono;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
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

/****** Template of some basic operations *****/
template <typename T, typename U>
inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T>
inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';

    do
    {
        buf[--i] = x % 10 + '0';
        x /= 10;
    } while (x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}

template <typename T>
inline T readInt()
{
    T n = 0, s = 1;
    char p = getchar();
    if (p == '-')
        s = -1;
    while ((p < '0' || p > '9') && p != EOF && p != '-')
        p = getchar();
    if (p == '-')
        s = -1, p = getchar();
    while (p >= '0' && p <= '9')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n * s;
}
/************************************/

/******* Debugging Class Template *******/
#define DEBUG

#ifdef DEBUG

#define debug(args...) (Debugger()), args

class Debugger
{
public:
    Debugger(const std::string &_separator = " - ") : first(true), separator(_separator) {}

    template <typename ObjectType>
    Debugger &operator,(const ObjectType &v)
    {
        if (!first)
            cerr << separator;
        std::cerr << v;
        first = false;
        return *this;
    }
    ~Debugger()
    {
        cerr << endl;
    }

private:
    bool first;
    std::string separator;
};

#else
#define debug(args...) // Just strip off all debug tokens
#endif

/**************************************/

/******** Utilities Function *******/
void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void file()
{
    auto a = freopen("a.in", "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if (!a || !b)
        cout << "uh oh" << endl;
}

/* void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
} */

/**************************************/

/******** User-defined Function *******/
void countFreq(string str, map<int, int> &freqMap)
{
    str.pop_back();
    str = str.substr(1);
    stringstream ss(str);
    while (!str.empty() && ss.good())
    {
        string substr;
        getline(ss, substr, ',');
        int i = stoi(substr);
        freqMap[i]++;
    }
}

vector<int> countingSortUsingMap(map<int, int> freqMap)
{
    vector<int> vec;

    for (auto e : freqMap)
    {
        int val = e.first;
        int freq = e.second;
        while (freq--)
            vec.push_back(val);
    }
    return vec;
}

double medianOf(vector<int> vec)
{
    int size = vec.size();
    if (size % 2 != 0)
    {
        return (double)vec[(int)floor(size / 2)];
    }
    else
    {
        int mid = size / 2;
        int small = (double)vec[mid - 1];
        int large = (double)vec[mid];
        return (small + large) / 2.0;
    }
}

void solve()
{
    string A, B;
    cin >> A >> B;
    map<int, int> freqMap;
    if (A != "[]") countFreq(A, freqMap);
    if (B != "[]") countFreq(B, freqMap);
    vector<int> vec = countingSortUsingMap(freqMap);
    cout << fixed << setprecision(5)
         << medianOf(vec) << endl;
}

/**************************************/

/********** Main()  function **********/

int main()
{
    fast();
    // file();

    int n_test;
    cin >> n_test;
    while (n_test--)
    {
        solve();
    }
}