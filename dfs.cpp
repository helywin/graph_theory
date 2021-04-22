//
// Created by jiang on 2021/4/22.
//

#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

struct edge
{
    int next = 0;
    int to = 0;
    int w = 1;
};

int n;
std::vector<edge> edges;
std::vector<int> head;
std::vector<bool> visit;

void init(int num)
{
    n = num;
    edges.resize(num + 1);
    head.resize(num + 1, -1);
    visit.resize(num + 1, false);
}

void add(int u, int v, int value = 1)
{
    edge e;
    e.next = head[u];
    head[u] = (int) edges.size();
    e.to = v;
    e.w = value;
    edges.push_back(e);
}

void dfs(int u)
{
    assert(u < n);
    cout << u;
    if (!visit[u]) {
        visit[u] = true;
        auto i = head[u];
        while (i > 0) {
            cout << "(";
            dfs(edges[i].to);
            i = edges[i].next;
        }
        cout << ")";
    } else {
        cout << "!";
    }
}



void dfs1(int u)
{
    assert(u < n);
    auto i = head[u];
    while (i > 0) {
        if (!visit[edges[i].to]) {
            cout << u;
            cout << "(";
            i = edges[i].next;
            dfs(edges[i].to);
            cout << ")";
        } else {
            cout << u;
            cout << "!";
            break;
        }
    }
    visit[u] = true;
}

int main()
{
    init(10);
    add(1, 2);
    add(1, 3);
    add(3, 4);
    add(3, 1);
    add(4, 6);
    add(6, 5);
    add(6, 3);
    add(7, 8);
    add(4, 5);
    add(2, 7);

    dfs(3);
    cout << endl;
    fill(visit.begin(), visit.end(), false);
    dfs1(3);
}