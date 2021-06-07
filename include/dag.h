/**
 * @file dag.h
 *
 */

#ifndef DAG_H_
#define DAG_H_

#include "candidate_set.h"
#include "common.h"
#include "graph.h"

class DAG {
public:
    DAG(const Graph &data, const Graph &query, const CandidateSet &cs);
private:
    Vertex root;
    std::vector<std::vector<Vertex>> adj_list_;
};

#endif // DAG_H_