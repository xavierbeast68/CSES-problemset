/*
    ▄  ██       ▄   ▄█ ▄███▄   █▄▄▄▄ ███   ▄███▄   ██      ▄▄▄▄▄      ▄▄▄▄▀ 
▀▄   █ █ █       █  ██ █▀   ▀  █  ▄▀ █  █  █▀   ▀  █ █    █     ▀▄ ▀▀▀ █    
  █ ▀  █▄▄█ █     █ ██ ██▄▄    █▀▀▌  █ ▀ ▄ ██▄▄    █▄▄█ ▄  ▀▀▀▀▄       █    
 ▄ █   █  █  █    █ ▐█ █▄   ▄▀ █  █  █  ▄▀ █▄   ▄▀ █  █  ▀▄▄▄▄▀       █     
█   ▀▄    █   █  █   ▐ ▀███▀     █   ███   ▀███▀      █              ▀      
 ▀       █     █▐               ▀                    █                      
        ▀      ▐                                    ▀                       
*/
/**
 * xavierbeast68
 * URL : https://cses.fi/problemset/task/1755
 * AVOIDING COMPLEXITY, REDUCES BUGS.
 */

#pragma GCC optimize("O3,Ofast,unroll-loops")

#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

#define fastio                                      ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl                                        '\n'
#define int                                         long long
using ll                                            = long long;
using ull                                           = unsigned long long;
using lld                                           = long double;
#define vi                                          vector<int>
#define vvi                                         vector<vi>

constexpr lld EPS                                   = 1e-9;
constexpr ll MOD                                    = 1e9 + 7; //1000000007
constexpr ll mod1                                   = 998244353;

#define FOR(i,a,b)                                  for(int i = a; i < b; ++i)

#define pb                                          push_back
#define ppb                                         pop_back
#define sz(x)                                       (int)(x).size()
#define all(x)                                      begin(x), end(x)
#define mp(x,y)                                     make_pair(x,y)
#define lb(arr, x)                                  lower_bound(arr.begin(), arr.end(), x) - arr.begin();
#define ub(arr, x)                                  upper_bound(arr.begin(), arr.end(), x) - arr.begin();


/*------------------------------------------------------Read & Print Methods------------------------------------------------------*/

#define read(x)                                     int x; cin >> x; // reads long long
#define readstr(x)                                  string x; cin >> x; // reads string(word)
#define readLine(x)                                 string x; getline(cin, x); // reads string(sentence)
#define print(x)                                    cout<<(x)<<" "
#define println(x)                                  cout<<(x)<<endl

// Vector Read & Print ->
// template <class T> vector<T> readvector(T n) { vector<T> arr(n); for (int i = 0; i < n; i++) {cin >> arr[i];} return arr;}   // vector<ll> arr = readvector(n);
// template <class T> void printvector(vector<T> arr) {for (int i = 0; i < (int)arr.size(); i++) {cout << arr[i] << " ";} cout << endl;}   // printvector(arr, n);

// Streams ->
template<class T, class V>istream& operator>>(istream &in, pair<T, V> &a){in >> a.F >> a.S;return in;}
template<class T>istream& operator>>(istream &in, vector<T> &a){for(auto &i: a){in >> i;} return in;}
template<class T, class V>ostream& operator<<(ostream &os, pair<T, V> &a){os << a.F << " " << a.S;return os;}
template<class T>ostream& operator<<(ostream &os, vector<T> &a){for(int i = 0 ; i < sz(a) ; i++){if(i != 0){os << ' ';}os << a[i];}return os;}

//InputOutputError_From/To_File ->
void file_io()
{
// #ifndef ONLINE_JUDGE
#ifdef XAVIERBEAST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}


/*----------------------------------------------------------------PBDS----------------------------------------------------------------*/

// template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;     // ordered_set <T> a; (work as ordered_set) // ordered_set <pair<T, T>> a; (ordered set of pairs (can also work as ordered_map))
// template <class T> using multi_ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;      // multi_ordered_set <T> a; // multi_ordered_set <pair<T,T>> a;
// order_of_key(k): Returns the number of elements strictly smaller than k.
// find_by_order(k): Returns the address of the element at kth index in the set while using zero-based indexing, i.e the first element is at index zero.


/*--------------------------------------------------------------Debugger--------------------------------------------------------------*/
//            [di:b^b-ing]
// -Being the detective in a crime
//  where you are also the murderer.

#define test(i)                                     cout << "(#" << i << ")" << endl

// #ifndef ONLINE_JUDGE
#ifdef XAVIERBEAST
#define dbg(x)                                      cerr << #x<<" "; _print(x); cerr << endl;
#else
#define dbg(x);
#endif

// void _print(int t) {cerr << t;}
void _print(ll t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
// void _print(auto t) {cerr << *t;} // for ordered_set

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(ordered_set v) {cerr << "[ "; for (int i=0 ; i<(int)v.size();i++) {_print(v.find_by_order(i)); cerr << " ";} cerr << "]";}


/*------------------------------------------------------Functions------------------------------------------------------*/

ll gcd(ll a, ll b)                                  {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll lcm(ll a, ll b)                                  {return a / gcd(a, b) * b;}
ll countDigit(ll n)                                 {return (floor(log10(n) + 1));}
ll log_a_to_base_b(ll a, ll b)                      {return log2(a) / log2(b);}
ll isPowerof2(ll x)                                 {return (x && !(x & (x - 1)));} // Checking if given 64 bit integer is power of 2
bool is_whole(ll a)                                 {return (a - floor(a) < 1e-9);} // floor(a)==ceil(a)
ll factorial(const int& p)                          {if (p <= 1) {return 1;} return p * factorial(p - 1);}
double nCr(ll n, ll r)                                  {double sum = 1; for(int i = 1; i <= r; ++i){sum = sum * (n - r + i) / i;} return sum;}
ll binpow(ll a , ll b)                              {if (b == 0) {return 1;} if (b == 1) {return a;} if (b % 2 == 0) {return binpow((a * a) % MOD, b / 2);} else {return (a * binpow((a * a) % MOD, b / 2)) % MOD;}}    // binary exponentiation

ll mod(ll x)                                        {return (((x) % MOD + MOD) % MOD);}
ll mod_add(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a+b));}
ll mod_mul(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a*b)); }
ll mod_sub(ll a, ll b)                              {a = a % MOD; b = b % MOD; return (mod(a-b));}


// random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r)                      {return uniform_int_distribution<ll>(l, r)(rng); }

// Prime utility
bool isPrime(ll n)                                  {if (n == 2 || n == 3) {return true;} if (n <= 1 || n % 2 == 0 || n % 3 == 0) {return false;} for (int i = 5; i * i <= n; i += 6) { if (n % i == 0 || n % (i + 2) == 0) {return false;}} return true;}

int sz = 1e6 + 5;
bool PrimeSieve[1000005]; // 1e6+5
void buildSieve(){
    for (int i = 2; i <= sz; i++)
        PrimeSieve[i] = 1;
    PrimeSieve[0] = 0; //
    PrimeSieve[1] = 0; // 1 is neither prime nor composite
    for (int i = 2; i < sz; i++){
        if (PrimeSieve[i] == 0)
            continue; // the current number itself is composite
        for (int j = 2; j * i < sz; j++){
            PrimeSieve[i * j] = 0;
        }
    }
}

/*-------------------------------------------------------||||||||||-----------------------------------------------------------------------
------------------------------------------------------------------------------------------------------------------------------------------
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
                                        |H| |e| |r| |e|   |w| |e|   |g| |o| |!| |!| |!|
                                        +-+ +-+ +-+ +-+   +-+ +-+   +-+ +-+ +-+ +-+ +-+
------------------------------------------------------------------------------------------------------------------------------------------
--------------------------------------------------------||||||||||------------------------------------------------------------------------*/

void brute_force(string s){
    unordered_map<char,int> freq;
    for(char ch : s){
        freq[ch]++;
    }

    int oddCnt = 0;
    pair<char, int> odd;
    for(auto i : freq){
        if(i.second%2 == 1){
            oddCnt++;
            odd.first = i.first;
            odd.second = i.second;
        }
        if(oddCnt > 1){
            println("NO SOLUTION");
            return;
        }
    }

    string ans = "";
    if(oddCnt == 1){
        freq.erase(odd.first);

        while(freq.size() > 0){
            auto i = (*freq.begin());

            int times = (i.second)/2;
            while(times){
                ans += i.first;
                times--;
            }

            freq.erase(i.first);
        }

        int times = odd.second;
        string temp = "";
        while(times){
            temp += odd.first;
            times--;
        }

        string ansRev = ans;
        reverse(ansRev.begin(), ansRev.end());
        ans = ans + temp + ansRev;

        println(ans);
    }
    else{
        while(freq.size() > 0){
            auto i = (*freq.begin());

            int times = (i.second)/2;
            while(times){
                ans += i.first;
                times--;
            }

            freq.erase(i.first);
        }

        string ansRev = ans;
        reverse(ansRev.begin(), ansRev.end());
        ans = ans + ansRev;

        println(ans);
    }
}

void brute_2(string s){
    unordered_map <char,int> a;
	for (auto c:s){
		a[c]++;
	}
	string s1 (s.size(),' ');
	int l=0,r=s.size()-1;
	int m=-1;
	if (s.size()%2) m=(l+r)/2;
	for (auto x:a){
		if (x.second%2){
			if (m!=-1){
				s1[m]=x.first;
				m=-1;
			}
			else{
				cout<<"NO SOLUTION\n";
                return;
			}
		}
		for (int c=x.second;c>=2;c-=2){
			s1[l++]=s1[r--]=x.first;
		}	
	}
	cout<<s1<<endl;
}

void solve(){
    //--Let's Code--
    readstr(s);
    
    // brute_force(s);

    brute_2(s);
}

// signed main(signed argc, char const *argv[])
signed main(){
    fastio;

    cout << fixed << setprecision(10);
    // file_io();
    auto start = high_resolution_clock::now();

    //testcases=1: default value for single test case
    int testcases = 1;
    //cin >> testcases;
    while (testcases--){
        solve();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    // #ifndef ONLINE_JUDGE
    #ifdef XAVIERBEAST
        cerr << endl << "Time: " << (float)duration.count()/1000000 << " s" << endl;
    #endif

    return 0;
}