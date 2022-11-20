
#include "spaces.h"

namespace vector_search
{
  SpaceVector L2Space::Distances(const Eigen::MatrixXf& points, const SpaceVector& query)
  {
    // Do some checks.
    const auto differences = points.rowwise() - query.transpose();
    return differences.rowwise().squaredNorm();
  }

  SpaceVector CosineSpace::Distances(const Eigen::MatrixXf& points, const SpaceVector& query)
  {
    return points * query;
  }
}  // namespace vector_search