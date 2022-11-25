#include <gtest/gtest.h>
#include <iostream>
#include "kmeans.h"

namespace
{
    TEST(KmeansTest, BasicAssertions)
    {
        const int vector_size = 16;
        const auto dataset = vector_search::SpaceMatrix::Random(100, vector_size);
        const auto seeds = vector_search::SpaceMatrix::Random(5, vector_size);

        struct KMeansParams
        {
            int num_iterations = 5; /// The number of iterations for KMeans.
            // A callback function for evaluation.
            void evaluatePath(const vector_search::SpaceMatrix &vectors_to_cluster, const vector_search::SpaceMatrix &seeds)
            {
                float total_distance = 0.0f;
                for (auto row : vectors_to_cluster.rowwise())
                {
                    total_distance += vector_search::L2Space::Distances(seeds, row).minCoeff();
                }
                std::cout << "Total distance: " << total_distance << std::endl;
            }
        };
        KMeansParams params;
        const auto clusters = kmeans::KMeans<vector_search::L2Space>(dataset, seeds, params);
        for (auto result_seed : clusters.rowwise())
        {
            std::cout << result_seed << std::endl;
        }
        ASSERT_NE(seeds, clusters);
    }
}