#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 0x3f3f3f3f

int nxt[100001];

ll anslen;

void findNext(string p) {
	nxt[0] = -1;
	int i = 0;
	int j = -1;
	while (i < p.size()) {
		while (j!=-1 && p[i]!=p[j]) j = nxt[j];
		nxt[++i] = ++j;
	}
}

void kmp(string s, string p) {
	int i = 0;
	int j = 0;
	while (i < s.size()) {
		if (s[i] == p[j]) {
			i++;
			j++;
		}
		else if(j!=0){
			j = nxt[j];
		}
		else {
			i++;
		}
	}
	anslen = j;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string in;
	while (cin >> in) {
		string inverse = "";
		for (int i = in.size() - 1; i >= 0; i--) {
			inverse.push_back(in[i]);
		}
		anslen = 1;
		
		findNext(inverse);
		kmp(in, inverse);
		string ans = in + inverse.substr(anslen,inverse.size()-anslen);
		cout << ans << endl;
	}
	return 0;
}
