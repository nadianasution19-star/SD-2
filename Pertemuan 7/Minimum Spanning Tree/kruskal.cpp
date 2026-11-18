#include <bits/stdc++.h>
using namespace std;

class DSU { // penanda DSU, nanti dia bkal cata 2 hal yaitu bagian siapa parent dn sberapa tinggi rank nya
    vector<int> parent, rank; 
public: 
    DSU(int n) { // setiap vertex dianggap sbg individu mandiri, blm punya parent
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i) { //  menentukan vertex i masuk ke dalam parent yg mana
        return (parent[i] == i) ? i : (parent[i] = find(parent[i]));
    }

    void unite(int x, int y) { // fungsi unite untuk memasangkan edge antara vertex x sama y
        int s1 = find(x), s2 = find(y); // cari tahu siapa parent tertinggi antara s1 dan s2
        if (s1 != s2) { // logika union by rank, parent rank kecil dibandingkan yg besar, bakal masuk ke s2
            if (rank[s1] < rank[s2])
                parent[s1] = s2;
            else if (rank[s1] > rank[s2])
                parent[s2] = s1;
            else {
                parent[s2] = s1; // s1 bakal terjadi penambahan 
                rank[s1]++;
            }
        }
    }
};

bool comparator(vector<int> &a, vector<int> &b) { // sebagai pengurutan
    return a[2] < b[2]; // ngurutin edge, diurutkan dari paling terkecil
}

int kruskalsMST(int V, vector<vector<int>> &edges) {
    // Step 1: Sort all edges based on weight
    sort(edges.begin(), edges.end(), comparator);

    DSU dsu(V); // panggil dsu utk catet vertex mana aj yg ada di jaringan kita
    int cost = 0, count = 0; // seberapa edges yang udh terhubung = count

    cout << "Edges included in the MST:\n";

    // Step 2: Iterate through edges and pick the smallest valid ones
    for (auto &e : edges) {
        int u = e[0], v = e[1], w = e[2]; // titik awal = u, titik tujuan = v, bobot = w

        if (dsu.find(u) != dsu.find(v)) { // buat nentuin apakah parent dari vertex satu dgn lain berbeda
            dsu.unite(u, v);
            cost += w;
            cout << u << " - " << v << " (weight " << w << ")\n";
            if (++count == V - 1) break; // Stop when MST is complete
        }
    }

    cout << "Total weight of MST = " << cost << endl;
    return cost;
}

int main() {
    int V = 9; 

    // Each edge is represented as {source, destination, weight}
    vector<vector<int>> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}
    };

    // Run Kruskal's algorithm
    kruskalsMST(V, edges);
    return 0;
}