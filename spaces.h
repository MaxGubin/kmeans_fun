#ifndef SPACES_H
#define SPACES_H
// Spaces for index vectors.
// Usually it is much more efficient to query distances to a set of vectors that are usually represented as a matrix.
#include <algorithm>
#include <utility>
#include <vector>

#include "eigen3/Eigen/Dense"
namespace vector_search {
using SpaceVector = Eigen::VectorXf;
using SpaceMatrix = Eigen::MatrixXf;
class L2Space {
    public:
    // Returns a vector of distances 
    static SpaceVector Distances(const SpaceMatrix& points, const SpaceVector& query);
};

class CosineSpace {
    public:
    // Returns a vector of distances 
    static SpaceVector Distances(const SpaceMatrix& points, const SpaceVector& query);
};
}
#endif