#pragma once

#include <queue>
#include <vector>

struct Edge {
    long long cost;
    int to;
    Edge(long long cost, int to) : cost(cost), to(to) {};
};

const int SIZE = 500500;

std::vector<long long> dist(SIZE, 1e18);
std::vector<std::vector<Edge>> G(SIZE);

void dijkstra(int s) {
    for (int i = 0; i < SIZE; i++) {
        dist[i] = 1e18;
    }
    dist[s] = 0;
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> pq;
    for (int i = 0; i < (int)G[s].size(); i++) {
        dist[G[s][i].to] = G[s][i].cost;
        pq.push({G[s][i].cost, G[s][i].to});
    }
    while (!pq.empty()) {
        long long cost = pq.top().first;
        int from = pq.top().second;
        pq.pop();
        for (int i = 0; i < (int)G[from].size(); i++) {
            int to = G[from][i].to;
            int cost_edge = G[from][i].cost;
            if (dist[to] < cost + cost_edge) {
                continue;
            }
            dist[to] = cost + cost_edge;
            pq.push({cost + cost_edge, to});
        }
    }
    return;
}
