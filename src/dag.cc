/**
 * @file dag.cc
 *
 */

#include "dag.h"

using namespace std;

DAG::DAG(const Graph &data, const Graph &query, const CandidateSet &cs) {
    successor_.resize(query.GetNumVertices());
    predecessor_.resize(query.GetNumVertices());
    num_remaining_predecessor_. resize(query.GetNumVertices(), 0);
    matching_order_.resize(query.GetNumVertices(), -1);

    // Select root
    root_ = 0;
    for(size_t i = 1; i < query.GetNumVertices(); i++)
        if(cs.GetCandidateSize(i) * query.GetDegree(root_)
            < query.GetDegree(i) * cs.GetCandidateSize(root_))
            root_ = i;

    // BFS
    priority_queue<Vertex, vector<Vertex>, less<Vertex>> pq;
    vector<size_t> check(query.GetNumVertices(), 0); // 0 : not pushed
                                                     // 1 : pushed but not poped
    pq.push(root_);                                  // 2 : poped
    check[root_] = 1;
    for(size_t i = 0; !pq.empty(); i++) {
        Vertex v = pq.top();
        pq.pop();
        matching_order_[i] = v;
        check[v] = 2;
        for(size_t j = query.GetNeighborStartOffset(v);
            j < query.GetNeighborEndOffset(v); j++) {
            Vertex u = query.GetNeighbor(j);
            if(check[u] < 2) {
                successor_[v].push_back(u);
                predecessor_[u].push_back(v);
                num_remaining_predecessor_[u]++;
                if(check[u] == 0) {
                    pq.push(u);
                    check[u] = 1;
                }
            }
        }
    }
}

DAG::~DAG() {}