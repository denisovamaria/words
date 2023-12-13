#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
struct Word {
    string start;
    string end;
};

void dfs(int v, vector<Word> &nodes, vector<bool> &search, int n,int &m) {
    m++;
    search[v] = true;
    for (int i = 0; i < n; i++) {
        if (!search[i] && nodes[i].start == nodes[v].end) {
            dfs(i, nodes, search, n,m);
        }
    }
}


int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n = 0;
    int m = 0;
    in >> n;
    vector<string> words(n);
    vector<Word> nodes(n);
    for (int i = 0; i < n; i++) {
        in >> words[i];
        nodes[i].start = words[i].front();
        nodes[i].end = words[i].back();
    }
    in.close();
    for (int i = 0; i < n; i++) {
        m = 0;
        vector<bool> search(n, false);
        dfs(i, nodes, search, n,m);
        if(m == n){
            out<<"Yes";
            return 0;
        }
    }
    out<<"No";
    out.close();
}
