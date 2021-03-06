#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <sstream>
#include <cctype>
#include <utility>
#include <bitset>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>

using namespace std;
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
#define NINF -100001
#define vi vector<int>
#define MAXN 100005
#define LOGMAXN 20

int P[MAXN][LOGMAXN], L[MAXN], T[MAXN];
long long W[MAXN];
bool vis[MAXN];
vector<int> E[MAXN], V[MAXN];
void dfs(int n, int p, int l){
	vis[n] = true;
  T[n] = p; L[n] = l;
  for(int i = 0; i < E[n].size(); i++){
		if(!vis[E[n][i]]){
			P[E[n][i]][0] =  n;
			W[E[n][i]] = W[n] + V[n][i];
			dfs(E[n][i], n, l+1);
		}
  }
}

void LCA(int N){
  int i, j;
  //we initialize every element in P with -1
  for (i = 0; i < N; i++){
  	for (j = 0; 1 << j < N; j++)   P[i][j] = -1;
	}
  dfs(0, 0, 0);
  //the first ancestor of every node i is T[i]
  for (i = 0; i < N; i++)  P[i][0] = T[i];

  //bottom up dynamic programing
  for (j = 1; 1 << j < N; j++){
   for (i = 0; i < N; i++)
	 		if (P[i][j - 1] != -1)
			 	P[i][j] = P[P[i][j - 1]][j - 1];
	}

}
int query(int N, int p, int q){
	int tmp, lg, i;

//if p is situated on a higher level than q then we swap them
	if (L[p] < L[q])
			tmp = p, p = q, q = tmp;

//we compute the value of [log(L[p)]
	for (lg = 1; 1 << lg <= L[p]; lg++);
	lg--;

//we find the ancestor of node p situated on the same level
//with q using the values in P
	for (i = lg; i >= 0; i--)
			if (L[p] - (1 << i) >= L[q])
					p = P[p][i];

	if (p == q)
			return p;

//we compute LCA(p, q) using the values in P
	for (i = lg; i >= 0; i--)
			if (P[p][i] != -1 && P[p][i] != P[q][i])
					p = P[p][i], q = P[q][i];
	return T[p];
}

int main(){
	int N, Q, a, b,c, aux;
	scanf("%d", &N);
	while(N>0){
		L[0] =0;
    W[0] = 0;
		REP(i, N){
			 E[i].clear();
			 V[i].clear();
		 }
		memset(vis, false, N);
		FOR(n,1, N-1){
			scanf("%d %d", &a, &b);
			E[n].push_back(a);
			E[a].push_back(n);
			V[n].push_back(b);
			V[a].push_back(b);
		}
		LCA(N);
/*    PR0(T, N);
		REP(i, N){
			REP(j, 3){
				printf("%d ", P[i][j]);
			}
			printf("\n");
		}
*/
		scanf("%d", &Q);
		REP(q, Q){
			scanf("%d %d", &a, &c);
			aux = query(N, a, c);
			printf("%lld", W[a] + W[c] - 2*W[aux]);
			if(q+1 !=Q) printf(" " );
		}
		printf("\n");
		scanf("%d", &N);
	}
}
