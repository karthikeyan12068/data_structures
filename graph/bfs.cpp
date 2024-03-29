#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> v_i;
typedef vector<long long int> v_ll;
typedef vector<pair<int,int>> vp_i;
typedef vector<pair<long long int,long long int>> vp_ll;
typedef map<int,int> m_i;
typedef map<long long int,long long int> m_ll;
typedef map<pair<int,int>,int> mp_i;
typedef map<pair<long long int,long long int>,long long int> mp_ll;
typedef set<int> s_i;
typedef set<long long int> s_ll;
typedef set<pair<int,int>> sp_i;
typedef set<pair<long long int,long long int>> sp_ll;
typedef priority_queue<ll> maxheap;
typedef priority_queue <ll, vector<ll>, greater<>> minheap;
#define mp make_pair
#define fi first
#define se second
#define INF 2e18
#define sorts(v) sort((v).begin(),(v).end())
#define rev(v) reverse((v).begin(),(v).end())
#define count2(v,s) count((v).begin(),(v).end(),(s))
#define finds(v,s) find((v).begin(),(v).end(),(s))
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define forn(a,b,c) for(ll (c)=(a);(c)<(b);(c)++)
#define forr(a,b,c) for(ll (c)=(a);(i)>=(b);(c)--)
#define rep1(s) for(auto &it:(s))
#define rep2(s) for(auto it=(s).begin();it!=(s).end();it++)
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
void tokenize(string const &str, const char* delim,vector<string> &out)
{
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.push_back(string(token));
        token = strtok(nullptr, delim);
    }
}
vector<ll> str_p(string data){
    v_ll trav;
    ll i;
    stringstream ss(data);
    while (ss >> i) {
        trav.push_back(i);
        ss.ignore(1);
    }
    return trav;
}
ll factorial(ll n)
{
    // single line to find factorial
    return (n==1 || n==0) ? 1: n * factorial(n - 1);
}
string multiline(string s){
    getline(cin, s);
    return s;
}
string str(char c){
    string s;
    stringstream ss;
    ss << c;
    ss >> s;
    return s;
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
string to_binary(ll val)
{
    string binary = bitset<30>(val).to_string();
    return binary;
}
ll to_decimal(const string& s)
{
    return (std::bitset<30>(s).to_ulong());
}
double log_a_to_base_b(double a, double b)
{
    return log(a) / log(b);
}
bool isprime(int x) {if (x == 1) return false; for (int i = 2; i * i <= x; ++i) {if (x % i == 0) return false; } return true; }
ll str_to_in(string s)
{
    stringstream geek(s);
    ll x = 0ll;
    geek >> x;
    return x;
}

ll sum_v(v_ll v1){
    ll sum=0;
    forn(0,v1.size(),i){
        sum+=v1[i];
    }
    return sum;
}
ll binarySearch(v_ll arr,ll k,ll len){
    ll low = 0;
    ll high = len -1;
    ll mid = (high+low)/2;
    ll index = -1;
    while(low <= high){
        mid =( low + high ) / 2;
        if(arr[mid] <= k){
            index = mid;
            low = mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return (index);
}
ll ceil(ll a,ll b){
    ll val = (a / b) + ((a % b) != 0);
    return val;
}
bool checkPalindrome(ll n)
{
    ll reverse = 0;
    ll temp = n;
    while (temp != 0) {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    return (reverse
            == n); // if it is true then it will return 1;
    // else if false it will return 0;
}
ll ret(string &s){
    ll a=0;
    rep1(s){
        a+=it-'0';
    }
    return a;
}
bool ret(vector<vector<int>>&adj,int i,vector<bool>&vis){
    if(vis[i]){
        return false;
    }
    vis[i]=true;
    bool ans=true;
    forn(0,adj[i].size(),j){
        ans&=ret(adj,adj[i][j],vis);
        if(!ans){
            return ans;
        }
    }
    vis[i]=false;
    return ans;
}
int main()
{
    fast();
    int n;
    cin>>n;
    vector<vector<int>>adj={{1,5},{2,3},{},{},{7},{6,8},{7},{4},{}};
    queue<int>q;
    v_ll vis(n,-1);
    q.push(0);
    while(!q.empty()){
        int x=q.size();
        forn(0,x,i){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(vis[it]==-1){
                    q.push(it);
                    vis[it]=1;
                }
            }
            cout<<node<<" ";
        }
    }
}
