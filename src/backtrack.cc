/**
 * @file backtrack.cc
 *
 */

#include "backtrack.h"

Backtrack::Backtrack() {}
Backtrack::~Backtrack() {}

namespace{
void Embedding(const Graph &data, const DAG &queryDAG,
                const CandidateSet &cs, std::vector<Vertex> &M) {
    return;
}
}

void Backtrack::PrintAllMatches(const Graph &data, const Graph &query,
                                const CandidateSet &cs) {
    std::cout << "t " << query.GetNumVertices() << "\n";

    DAG queryDAG(data, query, cs);

    std::vector<Vertex> M(query.GetNumVertices(), -1);
    Embedding(data, queryDAG, cs, M);

}