/**
 * @file dag.cc
 *
 */

#include "dag.h"

DAG::DAG(const Graph &data, const Graph &query, const CandidateSet &cs) {
    // Select root
    Vertex root = 0;
    for(size_t i = 1; i < query.GetNumVertices(); i++)
        if(cs.GetCandidateSize(i) * query.GetDegree(root)
            < query.GetDegree(i) * cs.GetCandidateSize(root))
            root = i;

    // BFS
    std::queue<Vertex> queue;
    std::vector<size_t> check(query.GetNumVertices(), 0); // 0 : not pushed
                                                          // 1 : pushed but not poped
    queue.push(root);                                     // 2 : poped
    check[root] = 1;
    while(!queue.empty()) {
        Vertex v = queue.front();
        queue.pop();
        check[v] = 2;
        for(size_t i = query.GetNeighborStartOffset(v);
            i < query.GetNeighborEndOffset(v); i++) {
            Vertex u = query.GetNeighbor(i);
            if(check[u] < 2) {
                adj_list_[v].push_back(u);
                if(check[u] == 0) {
                    queue.push(u);
                    check[u] = 1;
                }
            }
        }
    }
}