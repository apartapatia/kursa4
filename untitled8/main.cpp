#include "menu.h"

using namespace std;

int main(int argc, char* argv[])
{   string file, file2, file3, file4;
    file = argv[1];
    file2 = argv[2];
    file3 = argv[3];
    file4 = argv[4];
    MST test(file);
    int variant;
    do {
        print_menu();
        variant = get_variant(6); // получаем номер выбранного пункта меню
        switch (variant) {
            case 1:
                cout << "Prim's algorithm" << '\n';
                int start;
                cout << "Enter the start point" << '\n' << ">";
                cin >> start;
                test.prim(start);
                break;
            case 2:
                cout << "Number of edges" << '\n' << ">" << test.getEdges() << '\n';
                break;
            case 3:
                cout << "Number of vertices" << '\n' << ">" << test.getVerts() << '\n';
                break;
            case 4:
                cout << "The graph is output to a file " << argv[2] << '\n';
                test.printGraph(argv[2]);
                break;
            case 5:
                cout << "The graph is drawn to a file " << argv[3] << " " << argv[4] << '\n';
                test.draw_graph(argv[3],argv[4]);
                break;
        }
        if (variant != 6)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 6);
    system("pause");
    return 0;
}
