#include "MST.h"

using namespace std;

int main(int argc, char* argv[])
{   string file, file2, file3, file4;
    file = argv[1];
    file2 = argv[2];
    file3 = argv[3];
    file4 = argv[4];
    MST test(file);
    cout << "Number of vertices is " << test.getVerts() << '\n';
    cout << "Number of edges is " << test.getEdges() << '\n';
    cout << '\n';
    cout << "Begin MST 1 starting at Vertex 0\n";
    test.prim(0);
    cout << '\n';
    test.printGraph(file2);
    test.draw_graph(file3,file4);
    system("pause");
    return 0;
}
