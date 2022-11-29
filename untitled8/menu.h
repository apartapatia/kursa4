#include "MST.h"

void print_menu() {
    system("cls");  // очищаем экран
    cout << "What do you want to do?\n";
    cout << "1. Use Prim's algorithm\n";
    cout << "2. Output the number of edges\n";
    cout << "3. Output the number of verts\n";
    cout << "4. Print the graph to a file\n";
    cout << "5. Draw a graph to a file\n";
    cout << "6. Exit\n";
    cout << ">";
}
int get_variant(int count) {
    int variant;
    string s;
    getline(cin, s);
    while (sscanf(s.c_str(), "%d", &variant) != 1 || variant < 1 || variant > count) {
        cout << "Incorrect input. Try again: ";
        getline(cin, s);
    }
    return variant;
}