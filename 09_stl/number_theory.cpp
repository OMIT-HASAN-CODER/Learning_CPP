#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// -------------------- 1. GCD & LCM --------------------
ll gcd(ll a, ll b){ return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b){ return a / gcd(a,b) * b; }

// Extended GCD: solves ax + by = gcd(a,b)
ll ext_gcd(ll a,ll b,ll &x,ll &y){
    if(b==0){ x=1;y=0;return a;}
    ll x1,y1;
    ll g=ext_gcd(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}

// -------------------- 2. Prime Numbers --------------------
vector<int> sieve(int n){
    vector<int> prime(n+1,1);
    prime[0]=prime[1]=0;
    for(int i=2;i*i<=n;i++)
        if(prime[i])
            for(int j=i*i;j<=n;j+=i)
                prime[j]=0;
    return prime;
}

// Miller-Rabin for large primes
ll modmul(ll a, ll b, ll m){ return (__int128)a*b%m; }
ll modpow(ll a, ll e, ll m){
    ll r=1; while(e){ if(e&1) r=modmul(r,a,m); a=modmul(a,a,m); e>>=1; } return r;
}
bool isPrime(ll n){
    if(n<2) return false;
    for(ll p:{2,3,5,7,11,13,17,19,23,29,31,37}) if(n%p==0) return n==p;
    ll d=n-1,s=0; while(d%2==0){ d/=2; s++; }
    for(ll a:{2,325,9375,28178,450775,9780504,1795265022}){
        if(a%n==0) continue;
        ll x=modpow(a,d,n);
        if(x==1 || x==n-1) continue;
        bool comp=true;
        for(int r=0;r<s;r++){ x=modmul(x,x,n); if(x==n-1){ comp=false; break; } }
        if(comp) return false;
    }
    return true;
}

// -------------------- 3. Prime Factorization --------------------
vector<ll> factorize(ll n){
    vector<ll> f;
    for(ll i=2;i*i<=n;i++)
        while(n%i==0){ f.push_back(i); n/=i; }
    if(n>1) f.push_back(n);
    return f;
}

// -------------------- 4. Modular Arithmetic --------------------
ll modinv(ll a,ll mod){ return modpow(a, mod-2, mod); } // prime mod

// -------------------- 5. Combinatorics --------------------
const int N=2e5+5;
const ll MOD=1e9+7;
ll fact[N], invfact[N];
void init_fact(){
    fact[0]=invfact[0]=1;
    for(int i=1;i<N;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[N-1]=modinv(fact[N-1], MOD);
    for(int i=N-2;i>=1;i--) invfact[i]=invfact[i+1]*(i+1)%MOD;
}
ll nCr(ll n,ll r){
    if(r<0||r>n) return 0;
    return fact[n]*invfact[r]%MOD*invfact[n-r]%MOD;
}

// -------------------- 6. Euler's Totient --------------------
ll phi(ll n){
    ll res=n;
    for(ll i=2;i*i<=n;i++)
        if(n%i==0){
            while(n%i==0) n/=i;
            res-=res/i;
        }
    if(n>1) res-=res/n;
    return res;
}

// -------------------- 7. Chinese Remainder Theorem --------------------
ll crt(ll a1,ll m1,ll a2,ll m2){
    ll x,y;
    ll g=ext_gcd(m1,m2,x,y);
    if((a2-a1)%g!=0) return -1; // no solution
    ll lcm=m1/g*m2;
    ll res=a1 + (a2-a1)/g*x%(m2/g)*m1;
    return (res%lcm+lcm)%lcm;
}

// -------------------- 8. Fibonacci / Linear Recurrences --------------------
using Matrix = vector<vector<ll>>;
Matrix mul(Matrix A, Matrix B, ll mod){
    int n=A.size();
    Matrix C(n, vector<ll>(n,0));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                C[i][j]=(C[i][j]+A[i][k]*B[k][j]%mod)%mod;
    return C;
}
Matrix matpow(Matrix A, ll e, ll mod){
    int n=A.size();
    Matrix R(n, vector<ll>(n,0));
    for(int i=0;i<n;i++) R[i][i]=1;
    while(e){ if(e&1) R=mul(R,A,mod); A=mul(A,A,mod); e>>=1; }
    return R;
}
ll fib(ll n, ll mod){
    if(n==0) return 0;
    Matrix F={{1,1},{1,0}};
    return matpow(F,n-1,mod)[0][0];
}

// -------------------- 9. Divisor Enumeration --------------------
vector<ll> divisors(ll n){
    vector<ll> divs;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            divs.push_back(i);
            if(i!=n/i) divs.push_back(n/i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}

// -------------------- MAIN FUNCTION --------------------
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init_fact(); // For nCr

    cout<<"--- GCD & LCM ---\n";
    ll a,b; cin>>a>>b;
    cout<<"GCD: "<<gcd(a,b)<<", LCM: "<<lcm(a,b)<<"\n";

    cout<<"--- Prime Check ---\n";
    ll n; cin>>n;
    cout<<n<<" is "<<(isPrime(n)?"Prime":"Not Prime")<<"\n";

    cout<<"--- Factorization ---\n";
    vector<ll> f=factorize(n);
    for(auto x:f) cout<<x<<" ";
    cout<<"\n";

    cout<<"--- Modular Exponentiation ---\n";
    ll x,e,mod; cin>>x>>e>>mod;
    cout<<x<<"^"<<e<<" mod "<<mod<<" = "<<modpow(x,e,mod)<<"\n";

    cout<<"--- Combinations ---\n";
    ll N,R; cin>>N>>R;
    cout<<"C("<<N<<","<<R<<") mod "<<MOD<<" = "<<nCr(N,R)<<"\n";

    cout<<"--- Euler's Totient ---\n";
    cout<<"phi("<<n<<") = "<<phi(n)<<"\n";

    cout<<"--- Fibonacci ---\n";
    ll k; cin>>k;
    cout<<"fib("<<k<<") mod "<<MOD<<" = "<<fib(k,MOD)<<"\n";

    cout<<"--- Divisors ---\n";
    vector<ll> d=divisors(n);
    for(auto x:d) cout<<x<<" ";
    cout<<"\n";

    cout<<"--- Chinese Remainder Theorem ---\n";
    ll a1,m1,a2,m2; cin>>a1>>m1>>a2>>m2;
    cout<<"CRT solution: "<<crt(a1,m1,a2,m2)<<"\n";

    return 0;
}