#include <bits/stdc++.h>
#include "PriorityQueue.cpp"

using namespace std;

const int maxn = 1000;

struct edge {
	int start, end, weight;
};

int m, n; // m: so luong dinh / n: so luong canh
vector<pair<int, int>> adjacent[maxn]; //canh ke = [{trongSo, dinh}, ...]
bool used[maxn]; // used[i] == true => i thuoc V(MST)
int parent[maxn]; //  ???
int d[maxn];       //  Luu trong so nho nhat cua tat ca cac canh noi voi dinh i

void nhap() {
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x,y,w;
		cin >> x >> y >> w;
		adjacent[x].push_back({y, w});
		adjacent[y].push_back({x, w});
	}
	memset(used, false, sizeof(used));
  	for (int i=1;i<=n; i++) d[i] = INT_MAX;
}
void prim(int u) {
	PriorityQueue<pair<int, int>, vector<pair<int, int>>> Q;
	vector<edge> MST; // cay khung nho nhat
	int MSTdistance = 0; // chieu dai cay khung
	Q.push({0, u});
	while (!Q.empty()) {
		pair<int, int> top = Q.top();
		Q.pop();
		int weight = top.first;
		int vertex = top.second;

		if (used[vertex]) continue;
		MSTdistance += weight;
		used[vertex] = true;
		if (u != vertex) {
			MST.push_back({vertex, parent[vertex], weight});
		}
		// Duyet tat ca cac dinh ke
		for (auto it: adjacent[vertex]) {
			int nWeight = it.second;
			int nVertex = it.first;
			if (!used[nVertex] && nWeight < d[nVertex]) {
				Q.push({nWeight, nVertex});
				d[nVertex] = nWeight;
				parent[nVertex] = vertex;
			}
		}
	}
	cout << "Chieu dai cay khung nho nhat: "<< MSTdistance << endl;
	for (edge it: MST) {
		cout << it.start << " " << it.end << " " << it.weight << endl;
	}

}

int main() {
	nhap();
	prim(4);
	return 0;
}