use ndarray::{Array1, Array2, ArrayBase, Data, Ix2, Ix1};
use std::vec::Vec;
mod kmeans {

pub struct KMeansParams {
    num_iteations: i32,
}

impl Default for KMeansParams {
    fn default()->Self {
        KMeansParams{num_iteations: 5}
    }
}

pub fn KMeans<A> (points_to_cluster: &ArrayBase<A, Ix2>, seeds: &ArrayBase<A, Ix2>, param: &KMeansParams) -> ArrayBase<A, Ix2> 
 where A: Data<Elem = f64> {
    let (n_samplers, dimensionality_points) = points_to_cluster.dim();
    let (n_clusters,dimensionality_seeds) = seeds.dim();
    assert!(dimensionality_points == dimensionality_seeds,"Dimensionality of points and seeds are different");
    assert!(n_samplers > n_clusters, "The future of clustes must be more than points");
    let mut result = seeds;
    for n_iter in 0..param.num_iteations {
        let mut counters = vec![0; n_clusters];
        for row in points_to_cluster.row() {
            println!("{:1.4}", row);
        }
    }
    result
}
} // 

#[cfg(test)]
mod test {
    use ndarray::Array;
    use ndarray_rand::RandomExt;
    use ndarray_rand::rand::SeedableRng;
    use ndarray_rand::rand_distr::Uniform;
    use rand_isaac::isaac64::Isaac64Rng;
    #test
    fn test_kmeans() {
        const DIM:i32 = 16; // The dimansionality of our space.
        let mut rng = Isaac64Rng::seed_from_u64(42);
        // Generate random matrixes.
        let points = Array::random_using((100, DIM), Uniform::new(0., 1.), &mut rng);
        let seeds = Array::random_using((5, DIM), Uniform::new(0., 1.), &mut rng);

        let mut params:KMeansParams = Default::default();

        let cluster_centers = kmeans::KMeans<f64>(points, seeds, params);
        assert_eq!(seeds.dim() == cluster_centers.dim(), "Output centers must match seeds dimensions");
        println!("{:1.4}", cluster_centers);

    }

}