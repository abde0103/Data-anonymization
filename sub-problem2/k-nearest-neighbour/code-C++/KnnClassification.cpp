
#include "KnnClassification.hpp"
#include <iostream>
#include <ANN/ANN.h>

 
KnnClassification::KnnClassification(int k, Dataset* dataset, int col_class)
: Classification(dataset, col_class) {
    // TODO Exercise 1.1
    m_k = k;
    int dim= dataset->getDim();
    int nPts=dataset->getNbrSamples();
    ANNpointArray dataPts;
    //ANNpoint queryPt;
    //queryPt=annAllocPt(dim);
    dataPts=annAllocPts(nPts,dim-1);
    for(int i= 0; i < nPts; i++){
        for(int j = 0; j < dim; j++){
            if(j<col_class){
                dataPts[i][j]= dataset->getInstance(i)[j];
            }
            else if(j>col_class){
                dataPts[i][j-1] = dataset->getInstance(i)[j];
            }
        }
    }
    m_dataPts=dataPts;
    m_kdTree=new ANNkd_tree(
        dataPts,nPts,dim-1
    );
}

KnnClassification::~KnnClassification() {
    // TODO Exercise 1.1
    annDeallocPts(m_dataPts);
    delete m_kdTree;
}

int KnnClassification::Estimate(const ANNpoint & x, double threshold) {
    // TODO Exercise 1.2
    ANNidxArray nnIdx = new ANNidx[m_k];
    ANNdistArray dists= new ANNdist[m_k];
    m_kdTree->annkSearch(
        x,
        m_k,
        nnIdx,
        dists
    );
    int p=0;
    double* best_clss = new double[m_k]();
    for(int i =0; i <m_k; i++){
        
        p=m_dataset->getInstance(nnIdx[i])[m_col_class];
        best_clss[p-1]++;
    }
    int max=best_clss[0];
    int id_max = 0;
    for(int i = 0; i < m_k; i++){
        if(best_clss[i]>max){
            max =best_clss[i];
            id_max= i;
        }
    }
    return id_max+1;
}

int KnnClassification::getK() {
    return m_k;
}

ANNkd_tree* KnnClassification::getKdTree() {
    return m_kdTree;
}
