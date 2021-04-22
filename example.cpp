#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<bool> vis;
vector<int> head, nxt, to;

void add(int u, int v)
{
    nxt.push_back(head[u]);
    head[u] = (int)to.size();
    to.push_back(v);
}

bool find_edge(int u, int v)
{
    for (int i = head[u]; ~i; i = nxt[i]) {  // ~i 表示 i != -1
        if (to[i] == v) {
            return true;
        }
    }
    return false;
}

void dfs(int u)
{
    if (vis[u]) {
        cout << endl;
        return;
    }
    vis[u] = true;
    for (int i = head[u]; ~i; i = nxt[i]) {
        cout << u << "->";
        dfs(to[i]);
    }
    cout << "finish " << u << endl;
}

int main()
{
    n = 6;

    vis.resize(n + 1, false);
    head.resize(n + 1, -1);

    add(1, 2);
    add(1, 3);
    add(3, 4);
    add(3, 1);
    add(4, 6);
    add(6, 5);
    add(6, 3);

    //cout << find_edge(3, 4) << endl;
    dfs(1);

    return 0;
}
