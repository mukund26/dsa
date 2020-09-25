#include <bits/stdc++.h>
using namespace std;
#define pow5 100000 
#define pow6 1000000 
#define pow7 10000000
#define pow8 100000000
#define pow9 1000000000
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
void limits() { 
	cout << "LONG_MAX: " << scientific << (double)LONG_MAX << endl; 
	cout << "INT_MAX: " << scientific << (double)INT_MAX << endl;
	cout << "DBL_MAX: " << DBL_MAX << endl;
	cout << "2^20: " << pow(2,20) << endl;
	cout << "2^30: " << pow(2,30) << endl;
}
// clang-format off
#define dout if(debug and (debug_test == 0 or _t == debug_test) ) cerr<<" "
#define endl "\n"
#define substring(i,j) substr(i,(j-i+1)) // both i,j are included

#ifdef ONLINE_JUDGE
#define DEBUG 0.0
#else
#define DEBUG 1
#endif
int debug = DEBUG;// it will take care of itself on online-judge
int debug_test = 0; // test_case to be debugged ... 0 means all ... -1 means none
int _t = 0;// test_case counter

#define all(container) container.begin(),container.end()
#define umap unordered_map
#define pqueue priority_queue // kept them macro coz we need to use <> also
template<class T>int sz(T &x){return (int)x.size();}
template<class T>void show(T first){dout<<first<<"\n";}
template<class T>bool sort_fun(T a,T b){return a>b;} // for descending sort // normally sory is ascending, use <() fxn
template<class T,class U>bool found(T t,U u){if(t.find(u)==t.end())return false;return true;}

// helping templates ignore them
template<class T,class... Args>void show(T first,Args... args){dout<<first;show(args...);}
template<class T>void _p(T x){int i=0;for(auto a: x){dout<<a<<",";if(i++ > 20)break;}}
template<class T,class U>ostream &operator<<(ostream &o,pair<T,U> &x){return o<<"("<<x.first<<","<<x.second<<")";}
template<class T>ostream &operator<<(ostream &os,vector<T> &x){dout<<"[";_p(x);dout<<"] ";return os;}
template<class T>ostream &operator<<(ostream &os,set<T> &x){dout<<"{";_p(x);dout<< "} ";return os;}

struct Desc{bool operator()(int a,int b){return a>b;}}desc; // for descending sort, PQ does descending sort by default
// clang-format off

// code begins here
//-------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------------------------------------------------//


int solve() 
{
    string str; cin >> str;
    auto prev = str[0];
    int count = 0;
    string newstr = "";
    for(auto ch : str) {
        if(ch!=prev) {
            newstr+=(prev+to_string(count));
            prev = ch; count = 1;
        }
        else count++; 
    }
    newstr = newstr + prev + to_string(count);
    if(newstr.length() <= str.length()) cout << newstr << endl;
    else cout << str << endl;
    exit(EXIT_SUCCESS);
}

signed main() 
{
    #ifdef ONLINE_JUDGE
    ios_base::sync_with_stdio(0);cin.tie(0);
    #else
    //freopen("Input.txt","r",stdin);
    #endif
    solve();
}

// copyright 2018, Gaurav Kandoria, All right reserved
// code can be used by anyone.
template<class T>
class matrix{
private:
    ll x; ll y;
    T** a;   
public:
    matrix() {
        x = 0; y = 0;
    }
    matrix(ll x1, ll y1) {
        if(x1<=0 || y1<=0) return;
        x = x1; y = y1;
        a = new T*[x];
        for(ll i=0;i<x; i++) {
            a[i] = new T[y]; 
        }
    }
    T* operator[] (ll x) {
          return *(a+x);
    } 
    void print(ll x1=-1, ll y1=-1) {
        if(x1==-1 && y1==-1) {
            x1 = x; y1 = y;
        }
        for(ll i=0; i<x1; i++) {
            for(ll j=0; j<y1; j++) 
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    void takeinput(ll x1=-1, ll y1=-1) {
        if(x1==-1 && y1==-1) {
            x1 = x; y1 = y;
        }
        for(ll i=0; i<x1; i++) 
            for(ll j=0; j<y1; j++) cin >> a[i][j];
    }
};