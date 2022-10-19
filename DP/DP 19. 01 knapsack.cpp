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
#define finds(v,s) find((v).begin(),(v).end(),(s))
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
    int n = (int)(log2(val));
    return bitset<64>(val).to_string().substr(64 - n- 1);
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
ll ret(ll n,vp_ll &v1,ll acap,mp_ll &m1){
    if(n<0){
        return 0;
    }
    if(m1[{n,acap}]!=0){
        return m1[{n,acap}];
    }
    ll incl=0;
    if(v1[n].first<=acap) {
        incl=v1[n].second+ret(n-1,v1,acap-v1[n].first,m1);
    }
    ll nincl=0+ret(n-1,v1,acap,m1);
    return m1[{n,acap}]=max(incl,nincl);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    v_ll wt(n);
    forn(0,n,i){
        cin>>wt[i];
    }
    v_ll cap(n);
    forn(0,n,i){
        cin>>cap[i];
    }
    ll acap;
    cin>>acap;
    vp_ll v1(n);
    forn(0,n,i){
        v1[i].first=wt[i];
        v1[i].second=cap[i];
    }
    mp_ll m1;
    cout<<ret(n-1,v1,acap,m1);
}