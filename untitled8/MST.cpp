#include "MST.h"

using namespace std;

MST::MST(const string &inFile) {
    int weight;
    string line;
    //ifstream input(R"(Z:\Labs\untitled8\test.txt)");
    ifstream input;
    input.open(inFile);
    if(!input)
    {
        cout << "Failed to get file!";
        exit(-1);
    }
    else
    {
        while (getline(input, line))
            numVerts++;
        input.clear();
        input.seekg(0, ios::beg);
        allocate_mem(numVerts);
        for (int i = 0; i < numVerts; i++)
        {
            graph[i].push_back(0);
            graph2[i].push_back(0);
        }
        for (int i = 0; i < numVerts; i++) {
            for (int j = 0; j < numVerts; j++)
            {
                input >> weight;
                graph[i][j] = weight;
                graph2[i][j] = weight;
            }
        }
        input.close();
    }
}

void MST::allocate_mem(int n) {
    graph = vector<vector<int>> (n);
    graph2 = vector<vector<int>> (n);
    selected = vector<bool> (n);
}
MST::~MST() {
    graph.clear();
    graph2.clear();
    selected.clear();
}

void MST::prim(int startVert) {
    int x, y, min;
    for (int i = 0; i < getVerts(); i++) {
        for (int j = 0; j < getVerts(); j++)
        {
            selected[i] = false;
            graph2[i][j] = 0;
        }
    }
    selected[startVert] = true;
    for (int e = 0; e < getEdges(); e++)
    {
        x = 0; y = 0; min = INF;
        for (int i = 0; i < getVerts(); i++)
        {
            for (int j = 0; (j < getVerts()) && selected[i]; j++)
            {
                if (!selected[j] && graph[i][j] && min > graph[i][j])
                {
                    min = graph[i][j];
                    x = i; y = j;
                }
            }
        }
        graph2[x][y] = graph[x][y];
        graph2[y][x] = graph[x][y];
        cout << x << "-" << y << '\n';
        selected[y] = true;
    }
}

int MST::getVerts() const {
    return numVerts;
}

int MST::getEdges() const {
    return numVerts - 1;
}

void MST::printGraph(const string &outFile) {
    //ofstream output(R"(Z:\Labs\untitled8\out.txt)");
    ofstream output;
    output.open(outFile);
    for (int i = 0; i < numVerts; i++) {
        for (int j = 0; j < numVerts; j++)
        {
            output << graph2[i][j] << ' ';
        }
        output << '\n';
    }
    output.close();
}

void MST::draw_graph(const string& FileName1, const string& FileName2) {
    ofstream output;
    output.open(FileName1);
    //ofstream output(R"(Z:\Labs\untitled8\d.dot)");
    output << "graph ER { ";
    for (int i = 0; i < numVerts-1; i++) {
        for (int j = i; j < numVerts; j++)
        {
            if (graph[i][j] != 0) {
                output << "\" " << i << " \" -- \" " << j << " \" " << "[label = " << graph[i][j] << "]; ";
            }
        }
    }
    output << "}";
    output.close();


    ofstream output2;
    output2.open(FileName2);
    //ofstream output2(R"(Z:\Labs\untitled8\d1.dot)");
    output2 << "graph ER { ";
    for (int i = 0; i < numVerts-1; i++) {
        for (int j = i; j < numVerts; j++)
            if (graph2[i][j] != 0) {
                output2 << "\" " << i << " \" -- \" " << j << " \" " << "[label = " << graph2[i][j] << "]; ";
            }
    }
    output2 << "}";
    output2.close();
}
