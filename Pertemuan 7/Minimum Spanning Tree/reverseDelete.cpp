#include<bits/stdc++.h>
using namespace std;

typedef  pair<int, int> iPair; // menyimpan sambungan angka

class Graph{
    int V;   // utk nyimpan jumlah total dari vertex
    list<int> *adj; // utk adjacency
    vector< pair<int, iPair> > edges; // saling berkesinambungan utk buat adjacency
    void DFS(int v, bool visited[]); // utk menelusuri/mengunjungi

public:
    Graph(int V);   // Constructor, sbg fungsi pertama utk buat graf nya pertama kali

    void addEdge(int u, int v, int w); // u sm v utk vertex, w utk bobot

    bool isConnected(); // buat mastiin kehubung atau ga

    void reverseDeleteMST();
};

Graph::Graph(int V){ // ngebentuk sebanyak apa vertex kita
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v, int w){ // kalo u terhubung sama vertex v, kita bakal punya edge dan w sebagai bobot
    adj[u].push_back(v); 
    adj[v].push_back(u); 
    edges.push_back({w, {u, v}});
}

void Graph::DFS(int v, bool visited[]){ // menelusuri
    visited[v] = true; // ditandai sbg true biar ga dikunjungi bolak balik

    list<int>::iterator i; // kan udh dikunjungi, 
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}


bool Graph::isConnected(){ // 
    bool visited[V];
    memset(visited, false, sizeof(visited)); // lagi ngeset yang blm termasuk

    DFS(0, visited); // bergerak dari titik 0

    for (int i=1; i<V; i++) 
        if (visited[i] == false) // lagi gagal didatangi oleh DFS
            return false;

    return true; // berhasil semuanya dikunjungi
}

// ------ Main Part of Reverse Delete -----
void Graph::reverseDeleteMST(){
    sort(edges.begin(), edges.end()); // mengurutkan dgn cost yang paling murah/terendah

    int mst_wt = 0;  // Initialize weight of MST

    cout << "Edges in MST\n";

    for (int i=edges.size()-1; i>=0; i--){ // buat nampilin
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        adj[u].remove(v); // bakal apus yg besar
        adj[v].remove(u);

        if (isConnected() == false){ // bakal ngecek aman atau ga kalo diapus, memastikan biar gaada yg terpotong
            adj[u].push_back(v);
            adj[v].push_back(u);

            cout << "(" << u << ", " << v << ") \n";
            mst_wt += edges[i].first;
        }
    }

    cout << "Total weight of MST is " << mst_wt;
}

int main(){
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.reverseDeleteMST();
    return 0;
}

// MST (Minimum Spanning Tree) : menghubungkan vertex yang ada di graf kita dgn bobot terkecil dan tdk terjadi siklus
// Spanning Tree : terhubug tapi ga membentuk siklus, cmn mnegubungkan aja
// Kalo pake MST dia yang paling minimum
// 3 algoritma MST :
// 1. Reverse Delete : mulai dri graf penuh terus hapus edge berurutan paling besar, jgn sampe terputus
// 2. Kruskal : kebalikan dari reverse delete, mulai dari graf kosong, tambhkan edge mulai dri yg terkecil
// 3. Prim : kalo kruskal itu milih edge, kalo prim numbuhin satu per satu, kalo ad dua yang terhubung pilih edge terkecil
