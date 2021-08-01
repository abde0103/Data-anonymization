#include "ConfusionMatrix.hpp"
#include <iostream>

using namespace std;

ConfusionMatrix::ConfusionMatrix() {
    // TODO Exercise 2.1
    // Populate 2x2 matrix with 0s
    for(int i =0; i< 5; i++){
        for(int j =0 ; j < 5; j++){
            m_confusion_matrix [i][j]=0;
        }
    }

}

ConfusionMatrix::~ConfusionMatrix() {
    // Attribute m_confusion_matrix is deleted automatically
}

void ConfusionMatrix::AddPrediction(int true_label, int predicted_label) {
    // TODO Exercise 2.1
    m_confusion_matrix[true_label-1][predicted_label-1]++;
}

void ConfusionMatrix::PrintEvaluation() const{
    // Prints the confusion matrix
    cout <<"\t\tPredicted\n";
    cout <<"\t\t1\t2\t3\t4\t5\n";
    cout <<"Actual\t1\t"
        <<m_confusion_matrix[0][0] <<"\t"
        <<m_confusion_matrix[0][1] <<"\t"
        <<m_confusion_matrix[0][2] <<"\t"
        <<m_confusion_matrix[0][3] <<"\t"
        <<m_confusion_matrix[0][4]<<endl;
    cout <<"Actual\t2\t"
        <<m_confusion_matrix[1][0] <<"\t"
        <<m_confusion_matrix[1][1] <<"\t"
        <<m_confusion_matrix[1][2] <<"\t"
        <<m_confusion_matrix[1][3] <<"\t"
        <<m_confusion_matrix[1][4]<<endl;
    cout <<"Actual\t3\t"
        <<m_confusion_matrix[2][0] <<"\t"
        <<m_confusion_matrix[2][1] <<"\t"
        <<m_confusion_matrix[2][2] <<"\t"
        <<m_confusion_matrix[2][3] <<"\t"
        <<m_confusion_matrix[2][4]<<endl;
    cout <<"Actual\t4\t"
        <<m_confusion_matrix[3][0] <<"\t"
        <<m_confusion_matrix[3][1] <<"\t"
        <<m_confusion_matrix[3][2] <<"\t"
        <<m_confusion_matrix[3][3] <<"\t"
        <<m_confusion_matrix[3][4]<<endl;
    cout <<"Actual\t5\t"
        <<m_confusion_matrix[4][0] <<"\t"
        <<m_confusion_matrix[4][1] <<"\t"
        <<m_confusion_matrix[4][2] <<"\t"
        <<m_confusion_matrix[4][3] <<"\t"
        <<m_confusion_matrix[4][4]<<endl;
    // Prints the estimators
    cout <<"Error rate class 1\t\t"
        <<error_rate() <<endl;
    cout <<"False alarm rate class 1\t"
        <<false_alarm_rate() <<endl;
    cout <<"Detection rate class 1\t\t"
        <<detection_rate() <<endl;
    cout <<"F-score class 1\t\t\t"
        <<f_score() <<endl;
    cout <<"Precision class 1\t\t"
        <<precision() <<endl;
}

int ConfusionMatrix::GetTP() const {
    return m_confusion_matrix[1][1];
}

int ConfusionMatrix::GetTN() const {
   return m_confusion_matrix[1][1]+m_confusion_matrix[2][2]+m_confusion_matrix[3][3]+m_confusion_matrix[4][4];
}

int ConfusionMatrix::GetFP() const {
    return m_confusion_matrix[1][0]+m_confusion_matrix[2][0]+m_confusion_matrix[3][0]+m_confusion_matrix[4][0];
}

int ConfusionMatrix::GetFN() const {
   return  m_confusion_matrix[0][1]+m_confusion_matrix[0][2]+m_confusion_matrix[0][3]+m_confusion_matrix[0][4];
}

double ConfusionMatrix::f_score() const {
    // TODO Exercise 2.1
    return 2*precision()*detection_rate()/(precision()+detection_rate());
}

double ConfusionMatrix::precision() const {
    // TODO Exercise 2.1
    return GetTP()/(double)(GetTP()+GetFP());
}

double ConfusionMatrix::error_rate() const {
    // TODO Exercise 2.1
    return (GetFP()+GetFN())/(double)(GetFP()+GetFN()+GetTP()+GetTN());
    
}

double ConfusionMatrix::detection_rate() const {
    // TODO Exercise 2.1
    return GetTP()/(double)(GetTP()+GetFN());
}

double ConfusionMatrix::false_alarm_rate() const {
    // TODO Exercise 2.1
    return GetFP()/(double)(GetFP()+GetTN());
}
