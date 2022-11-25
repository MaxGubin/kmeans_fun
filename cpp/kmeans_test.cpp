#include <gtest/gtest.h>
#include "kmeans.h"

namespace {
TEST(KmeansTest, BasicAssertions) {
    const int vector_size = 16;
    const auto dataset = vector_search::SpaceMatrix::Random(100, vector_size);
    const auto seeds = vector_search::SpaceMatrix::Random(5, vector_size);
    kmeans::KMeansParams params;
    const auto clusters = kmeans::KMeans<vector_search::L2Space>(dataset, seeds, params);
    for (auto result_seed: clusters.rowwise()) {
        std::cout << result_seed << std::endl;
    }
    ASSERT_NE(seeds, clusters);
}
}