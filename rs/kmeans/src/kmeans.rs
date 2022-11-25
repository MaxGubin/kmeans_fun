use ndarray::(Array1, Array2, ArrayBase, Data, Ix2);
use std::vec::Vec;


pub struct KMeansParams {
    num_iteations: i32 = 5;
}


pub fn KMeans<A> (points_to_cluster: &ArrayBase<A, Ix2>, seeds: &ArrayBase<A, Ix2>, param: &KMeansParams) -> ArrayBase<A, Ix2> : 
 where A: Data<Elem = f64> {
    let (n_samplers, dimensionality_points) = points_to_cluster.dim();
    let (n_clusters,dimensionality_seeds) = seeds.dim();
    assert!(dimensionality_points == dimensionality_seeds,"Dimensionality of points and seeds are different");
    assert!(n_samplers > n_clusters, "The future of clustes must be more than points");
    for () {
        let mut counters = vec![0; n_clusters];
        for 
    }
}