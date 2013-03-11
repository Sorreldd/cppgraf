#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxN = 1000;

string s;
bool flag = false, use[maxN];
int u, v, n;

void golist() {
    vector < int > g[maxN];
    for(int i = 0; i < maxN; i++)
        g[i].clear();
}

void gomatrix() {
    int a[maxN][maxN];
    for(int i = 0; i < maxN; i++)
        for(int j = 0; j < maxN; j++)
            a[i][j] = 0;
    while(cin >> s) {
        if(s == "done") break;
        if(s == "addedge") {
            cin >> u >> v;
            if(use[u] && use[v]) {
                a[u][v] = a[v][u] = 1;
                cout << "Ребро добавлено\n";
            } else cout << "Ребро не добавлено, одна из вершин не существует\n";
        }
        if(s == "remedge") {
            cin >> u >> v;
            a[u][v] = a[v][u] = 0;
            cout << "Ребро удалено или не существовало\n";
        }
        if(s == "addvert") {
            for(int i = 0; i < maxN; i++)
                if(!use[i]) {
                    n++;
                    use[i] = true;
                    cout << "Вершина добавлена под номером " << i << '\n';
                    break;
                }
        }
        if(s == "remvert") {
            cin >> u;
            for(int i = 0; i < maxN; i++)
                a[i][u] = a[u][i] = 0;
            if(use[u]) {
                n--;
                use[u] = false;
                cout << "Вершина и все смежные ей ребра удалены\n";
            } else {
                cout << "Вершина не существовала\n";
            }
        }
        if(s == "info") {
            cout << "Количество вершин: " << n << '\n';
            for(int i = 0; i < maxN; i++) {
                if(use[i]) {
                    cout << i << ": ";
                    for(int j = 0; j < maxN; j++) {
                        if(a[i][j]) cout << j << ' ';
                    }
                    cout << '\n';
                }
            }
        }
    }
}


int main() {
    cout << "Вершины нумеруются с 0 !\n";
    cout << "Выберите способ хранения\n";
    cout << "matrix - матрица\n";
    cout << "list - список\n";
    cin >> s;
    n = 0;
    if(s == "matrix") {
        flag = true;
    } else if(s == "list") {
        flag = false;
    } else {
        cout << "incorrect type";
        return 0;
    }
    cout << "Запросы могут быть вида:\n";
    cout << "addedge u v - соединить вершины u и v ребром\n";
    cout << "remedge u v - удалить ребро между вершинами u v\n";
    cout << "addvert - добавить вершину в граф, вершина получит первый свободный номер\n";
    cout << "remvert u - удалить из графа вершину u\n";
    cout << "done - закончить ввод запросов\n";
    if(flag == false) {
        golist();
    } else {
        gomatrix();
    }
    return 0;
}