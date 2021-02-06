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

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
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

/**************************************/

/******** User-defined Function *******/

vector<int> makeVector(string str)
{
    str.pop_back();
    str = str.substr(1);
    vector<int> vec;
    if (!str.empty())
    {
        stringstream ss(str);
        while (ss.good())
        {
            string substr;
            getline(ss, substr, ',');
            vec.push_back(stoi(substr));
        }
    }
    return vec;
}

pair<vector<int>, vector<int>> input()
{
    string A, B;
    cin >> A >> B;
    vector<int> vecA = makeVector(A);
    vector<int> vecB = makeVector(B);
    return MP(vecA, vecB);
}

void solve()
{
    vector<int> A, B;
    tie(A, B) = input();
    int sum_mn = A.size() + B.size();
    int halfLen = ceil(sum_mn / 2.0);
    if (A.size() > B.size())
        swap(A, B);

    int A_count_min = 0;
    int A_count_max = A.size();

    while (A_count_min <= A_count_max)
    {
        int A_count = (A_count_max + A_count_min) / 2;
        int B_count = halfLen - A_count;
        if (A_count < (int) A.size() && A[A_count] < B[B_count - 1])
            A_count_min = A_count + 1;
        else if (A_count > 0 && A[A_count - 1] > B[B_count])
            A_count_max = A_count - 1;
        else
        {
            int leftHalfEnd =
                (A_count == 0)         // A not contributing?
                    ? B[B_count - 1]       // A_count = 0 implies B_count > 0
                    : (B_count == 0)   // B is not contributing?
                          ? A[A_count - 1] // B_count = 0 implies A_count > 0
                          : max(A[A_count - 1], B[B_count - 1]);

            if (sum_mn % 2 != 0)
            {
                cout << fixed << setprecision(5)
                    << (double) leftHalfEnd << '\n';
                return;
            }

            int rightHalfStart =
                (A_count == (int)A.size())       // A is all in the left half?
                    ? B[B_count]                 // A_count = aLen implies B_count < B.Length
                    : (B_count == (int)B.size()) // B is all in the left half?
                          ? A[A_count]           // B_count = B.Length implies A_count < A.Length
                          : min(A[A_count], B[B_count]);
            cout << fixed << setprecision(5)
                << (leftHalfEnd + rightHalfStart) / 2.0 << '\n';
            return;
        }
    }
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