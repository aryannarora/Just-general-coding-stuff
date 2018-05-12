#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void sieve(ll n) {
    bool prime[n+1];
    memset(prime, true, n+1);

    for (ll p = 2; p*p <= n ; p++) {
        if (prime[p] == true) {
            for (ll i = p*2; i<=n; i+=p) {
                prime[i] = false;
            }
        }
    }

    for (ll i=2; i<=n; i++) if (prime[i]) cout<<i<<" ";
}

int main() {
    ll n;
    cin>>n;
    sieve(n);

}