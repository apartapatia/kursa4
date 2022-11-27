#define INF 999999
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class MST {
private:
    vector<vector<int>> graph;
    vector<vector<int>> graph2;
    vector<bool> selected;
    int numVerts = 0;
public:
    void allocate_mem(int n);
    MST(const string& inFile);
    ~MST();
    void prim(int startVert);
    int getVerts() const;
    int getEdges() const;
    void printGraph(const string &outFile);
    void draw_graph(const string& FileName1, const string& FileName2);
};