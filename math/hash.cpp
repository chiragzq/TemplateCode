#include <bits/stdc++.h>
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

struct Hash {
	static const ll m1 = 1000000007, m2 = 1610612741;
	static const ll p1 = 509, p2 = 739;
	static ll pow1[1000000], pow2[1000000];
	static int _precomp;

	ll h1 = 0, h2 = 0;

	Hash() {
		precomp();
	}

	void append(char c) {
		h1 = (h1 * p1 + c) % m1;
		h2 = (h2 * p2 + c) % m2;
	}

	bool operator==(Hash& other) {
		return h1 == other.h1 && h2 == other.h2;
	}

	static void prefixHashes(const char* str, Hash* hashes, int len) {
		precomp();
		hashes[0] = {};
		for(int i = 0;i < len;i ++) {
			hashes[i + 1] = hashes[i];
			hashes[i + 1].append(str[i]);
		}
	}

	static Hash substr(Hash* prefix, int l, int r) {
		if(r - l <= 0) return {};
		Hash ret = prefix[r - 1];
		ret.h1 -= (prefix[l - 1].h1 * pow1[r - l]) % m1;
		ret.h2 -= (prefix[l - 1].h2 * pow2[r - l]) % m2;
		ret.h1 = (ret.h1 + m1) % m1;
		ret.h2 = (ret.h2 + m2) % m2;
		return ret;
	}
	
	static void precomp() {
		if(_precomp) return;
		_precomp = true;
		pow1[0] = pow2[0] = 1;
		for(int i = 1;i < 1000000;i ++) {
			pow1[i] = (pow1[i - 1] * p1) % m1;
			pow2[i] = (pow2[i - 1] * p2) % m2;
		}
	}

};

int Hash::_precomp = false;
ll Hash::pow1[1000000], Hash::pow2[1000000];

typedef struct Hash Hash;