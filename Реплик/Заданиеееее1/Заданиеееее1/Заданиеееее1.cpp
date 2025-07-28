#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& Stack, const vector<vector<int>>& graph) {
    visited[v] = true;

    for (int i = 0; i < graph.size(); ++i) {
        if (graph[v][i] == 1 && !visited[i]) {
            topologicalSortUtil(i, visited, Stack, graph);
        }
    }

    Stack.push(v);
}

void topologicalSort(const vector<vector<int>>& graph) {
    stack<int> Stack;
    int V = graph.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, Stack, graph);
        }
    }

    cout << "Топологический порядок вершин: ";
    while (!Stack.empty()) {
        cout << Stack.top() + 1 << " ";  
        Stack.pop();
    }
    cout << endl;
}

int main() {
    setlocale(0, "rus");
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Не удалось открыть файл input.txt" << endl;
        return 1;
    }

    int N;
    input >> N;

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            input >> graph[i][j];
        }
    }
    input.close();

    topologicalSort(graph);

    return 0;
}