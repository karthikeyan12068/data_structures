#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
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
#define mp make_pair
#define fi first
#define se second
#define INF 2e18
#define sorts(v) sort((v).begin(),(v).end())
#define rev(v) reverse((v).begin(),(v).end())
#define count2(v,s) count((v).begin(),(v).end(),(s))
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(min(a,b),min(c,d))
#define max4(a,b,c,d)   max(max(a,b),max(c,d))
#define max5(a,b,c,d,e) max(max3(a,b,c),max(d,e))
#define min5(a,b,c,d,e) min(min3(a,b,c),min(d,e))
#define forn(a,b,c) for(ll (c)=(a);(c)<(b);(c)++)
#define forr(a,b,c) for(ll (c)=(a);(i)>=(b);(c)--)
#define rep1(s) for(auto &it:(s))
#define rep2(a,b,c) for(ll i=(a);i<(b);i+=(c))
ll binets_formula(ll n) {
    double sqrt5 = sqrt(5);
    ll F_n = (pow((1 + sqrt5), n) - pow((1 - sqrt5), n)) / (pow(2, n) * sqrt5);
    return F_n;
}
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second < b.second);
}
string to_binary(ll val)
{
    return (std::bitset<30>(val).to_string());
}
ll to_decimal(const string& s)
{
    return (std::bitset<30>(s).to_ulong());
}
double log_a_to_base_b(double a, double b)
{
    return log(a) / log(b);
}
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
ll ceil(ll x, ll y) {
    ll ans = x % y == 0 ? x / y : x / y + 1;
    return ans;
}
ll repdp(ll n,ll m,vector<v_ll>dp){
    if(n==0 || m==0){
        dp[n][m]=1;
        return dp[n][m];
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    return dp[n][m]= repdp(n-1,m,dp)+ repdp(n,m-1,dp);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<v_ll>dp(n);
    forn(0,n,i){
        forn(0,m,j){
            dp[i].push_back(-1);
        }
    }
    dp[0][0]=1;
    cout<<repdp(n-1,m-1,dp);

}
