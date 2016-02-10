/*
***************************************************************************************************************

							Author : Yash Sadhwani

**************************************************************************************************************
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define mod 1000000007


#define MAXN 100010
#define SQRT 330
#define ls (node<<1)
#define rs ((node<<1)+1)
#define ii pair<int,int>
#define F first
#define S second

int pw2[5];

vi submasks[MAXN];

int just_before[20];

bool possible[20][MAXN];

bool check(int x){
	if((x & (x - 1)) == 0) return true;
	return false;
}

inline void pre(void){
	pw2[0] = 1; pw2[1] = 2; pw2[2] = 4; pw2[3] = 8; pw2[4] = 16;
	int max_mask = pow(3, 16);
	for(int mask = 0; mask < max_mask; mask++){
		int mask1 = 0, mask2 = 0, c1 = 0, c2 = 0, temp = mask;
		for(int i = 0; i < 16; i++){
			if(temp % 3 == 1) mask1 |= (1 << i), c1++;
			if(temp % 3 == 2) mask2 |= (1 << i), c2++;
			temp /= 3;
		}
		if(check(c1) and c1 == c2) submasks[mask1 | mask2].pb(mask1);
	}
	for(int i = 1; i <= 16; i++){
		if(check(i)) just_before[i] = i;
		else just_before[i] = just_before[i - 1];
	}
}


int G[20][20];

int N, K;



void brute(void){
	int rank[10], minans[10], maxans[10], perm[10];
	for(int i = 0; i < N; i++){
		minans[i] = N + 1; maxans[i] = -1;
		perm[i] = i;
	}
	do{
		queue<int> q;
		for(int i = 0; i < N; i++) q.push(perm[i]);
		int e = 0;
		/*for(int i = 0; i < N; i++) cout << perm[i] << " ";
		cout << endl;*/
		while(q.size() > 1){
			int a = q.front();
			q.pop();
			int b = q.front();
			q.pop();
			if(G[a][b]){
				q.push(a);
				rank[b] = just_before[N - e - 1] + 1;
			}else{
				q.push(b);
				rank[a] = just_before[N - e - 1] + 1;
			}
			e++;
		}
		rank[q.front()] = 1;
		/*for(int i = 0; i < N; i++) cout << rank[i] << " ";
		cout << endl;
		cout << endl;*/
		q.pop();
		for(int i = 0; i < N; i++){
			minans[i] = min(minans[i], rank[i]);
			maxans[i] = max(maxans[i], rank[i]);
		}
	}while(std::next_permutation(perm, perm + N));
	for(int i = 0; i < N; i++) cout << minans[i] << " " << maxans[i] << endl;
}

inline void ReadInput(void){
	si(N);
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			si(G[i][j]);
		}
	}
}

inline void solve(int t){
	printf("Case #%d: \n", t);
	cerr<<"SAD\t"<<t<<endl;
	if(N < 16){
		brute();
		return;
	}
	int minans[20], maxans[20];
	for(int i = 0; i < 16; i++) minans[i] = 0, maxans[i] = 16;
	int max_mask = (1 << N);
	for(int mask = 1; mask < max_mask; mask++){
		int cnt = __builtin_popcount(mask);
		for(int w = 0; w < 16; w++){
			if(!((1 << w) & mask)) continue;
			if(cnt == 1){
				possible[w][mask] = true;
				break;
			}
			bool flag = false;
			possible[w][mask] = false;
			for(int s = 0; s < submasks[mask].size(); s++){
				int sm = submasks[mask][s];
				if(!(sm & (1 << w))) continue;
				if(!possible[w][sm]) continue;
				int p = mask - sm;
				for(int k = 0; k < 16; k++){
					if(((1 << k) & p) and G[w][k]){
						possible[w][mask] = true;
						flag = true;
						break;
					}
				}
				if(flag) break;
			}
		}
	}
	for(int mask = 0; mask < max_mask; mask++){
		for(int i = 0; i < 16; i++){
			if(mask & (1 << i)){
				if(!possible[i][mask]) maxans[i] = min(maxans[i], __builtin_popcount(mask) / 2);
				else minans[i] = max(minans[i], __builtin_popcount(mask));
			}
		}
	}
	int maps[20];
	maps[1] = 9; maps[2] = 5; maps[4] = 3; maps[8] = 2; maps[16] = 1;
	for(int i = 0; i < 16; i++){
		cout << maps[minans[i]] << " " << maps[maxans[i]] << endl;
	}
}

inline void Refresh(void){

}

int main()
{
	//ios_base::sync_with_stdio(false);
	cerr<<"MY NAME is\n";
	pre();
	int t; si(t);
	for(int i = 1; i <= t; i++){
		ReadInput();
		solve(i);
	}
    return 0;
}

// U COME AT THE KING, BETTER NOT MISS !!!
