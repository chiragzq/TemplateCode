#include <bits/stdc++.h>
#include "util/hash.cpp"
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define endl "\n"
#define INF 10000000
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s1 = "ABABCDABABABCDDD";
	Hash prefix[20];
	Hash::prefixHashes(s1.c_str(), prefix, s1.length());
	cout << Hash::substr(prefix, 2, 4).h1 << " " << Hash::substr(prefix, 10, 13).h1 << endl;
}