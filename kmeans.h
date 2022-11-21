#ifndef KMEANS_H
#define KMEANS_H
#include <algorithm>
#include <iostream>
#include "spaces.h"

namespace kmeans {

struct KMeansParams {
    int num_iterations = 1; /// The number of iterations for KMeans.
};

template<typename DistanceSpace>
int FindClosest(const vector_search::SpaceMatrix& space_matrix, const vector_search::SpaceVector& v) {
    const auto distances = DistanceSpace::Distances(space_matrix, v);
    int min_index = -1;
    distances.minCoeff(&min_index);
    return min_index;
}

template<typename DistanceSpace>
vector_search::SpaceMatrix KMeans(const vector_search::SpaceMatrix& vectors_to_cluster, const vector_search::SpaceMatrix& seeds, KMeansParams params) {
    vector_search::SpaceMatrix result =  seeds;
    for (int i = 0; i<params.num_iterations; ++i) {
        std::vector<int> counters(result.rows());
        vector_search::SpaceMatrix candidates(result.rows(), result.cols()); 
        for(auto row: vectors_to_cluster.rowwise()) {
            const auto index= FindClosest<DistanceSpace>(candidates, row);
            ++counters[index];
            candidates.row(index) += row;
        }
        size_t counter_index = 0;
        for (auto candidate: candidates.rowwise()) {
            const int counter = counters[counter_index];
            if (counter> 0)  {
                candidate /= counter;
            } else {
                //  Keep the seed.
                candidate = result.row(counter_index);
            }
            ++counter_index;
        }
        result.swap(candidates);
    }
    return result;
}
}
#endif