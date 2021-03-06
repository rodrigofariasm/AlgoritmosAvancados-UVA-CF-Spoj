// Rodrigo Farias de Macêdo
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

map<int, int> visited;
map<int, vector<int> > G;

void visita(int s){
	int aux;
	queue<int> Q;
	Q.push(s);
	visited[s] = 0;
	while(!Q.empty()){
		aux = Q.front();
		Q.pop();
		REP(i, G[aux].size()){
		    if(!visited.count(G[aux][i])){
                visited[G[aux][i]]=visited[aux]+1;
                Q.push(G[aux][i]);
		    }
		}
    }
}

int main() {
	int n, a, b, s, t, cases = 1;

	while(scanf("%d", &n) && n){
		G.clear();
		visited.clear();
		REP(i, n){
			cin >> a >> b;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		while(scanf("%d %d", &s, &t) && s!=0 && t!=0){
			visited.clear();
			visita(s);
			int result = 0;
			EACH(it, visited){
                if((*it).second>t)++result;
			}
			result += G.size() - visited.size();
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",cases,result,s,t);
			cases++;
		}

	}
	return 0;
}
