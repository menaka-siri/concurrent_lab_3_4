
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <omp.h>
#include <chrono>
#include "support_functions.h"

using namespace std;
using namespace std::chrono;


void matrix_multiplication_parallel(double **matrix_1, double **matrix_2, double **result, int size);
void print_matrix(double **matrix, int size);
double **create_matrix(int size);
void initialize_matrix(double **matrix,int size);
void destroy_matrix(double **matrix, int size); 

int main(int argc, char *argv[]) {
	
    srand ( time(NULL) );
    int n = 0;
    int program_iterations = 20; //number of program iterations
    cout<<"Enter number of executions:";
    cin>>program_iterations;
    cout<<"Enter size of the matrix:";
    cin>>n;

    double **matrix_A = create_matrix(n);
    double **matrix_B = create_matrix(n);

    vector<double> executionTimeVector;

    //performing the test operations
    for (int i = 0; i < program_iterations ; i++) {
        initialize_matrix(matrix_A, n);
        initialize_matrix(matrix_B, n);

        double **result = create_matrix(n);

        high_resolution_clock::time_point t1 = high_resolution_clock::now();
        matrix_multiplication_parallel(matrix_A, matrix_B, result, n);
        high_resolution_clock::time_point t2 = high_resolution_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        cout << "Iteration "<< i << "  Parallel execution took " << time_span.count() << " seconds." << endl;
        //print_matrix(matrix_A, n);
        //print_matrix(matrix_B, n);
        //print_matrix(result, n);

        executionTimeVector.push_back(time_span.count());


//        destroy_matrix(matrix_A, n);
//        destroy_matrix(matrix_B, n);
//        destroy_matrix(result, n);
    }

    StatisticCalc scal;
    double executionTimeArray[program_iterations];
    copy(executionTimeVector.begin(), executionTimeVector.end(), executionTimeArray);

    scal.setValues(executionTimeArray, program_iterations);

    cout<< "\n\n";
    cout << "Program iterations:\t" << program_iterations << endl;
    // cout << "Thread count:\t\t" << thread_count << endl;
    cout << "Initial values:\t\t" << n << endl;
    cout << "Total time elapsed:\t" << scal.calculateSum() << "s" << endl;
    cout << "Average:\t\t" << scal.calculateMean() << "s" << endl;
    cout << "Standard Deviation:\t" << scal.getStandardDeviation() << "s" << endl;

    double required_accuracy = 5.0;
    double z = 1.960 ; //z value confidence_level of 95%
    int sample_count= (100 * 1.960 * scal.getStandardDeviation())/(required_accuracy* scal.calculateMean());

    cout << "Required no. of samples:\t" << sample_count << endl;

    return 0;

    return 0;
}

void matrix_multiplication_parallel(double **matrix_A, double **matrix_B, double **result, int size) {
    {
    #pragma omp parallel for
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
	    result[row][col] = 0.0;
            for (int k = 0; k < size; k++) {
                result[row][col] = result[row][col] + matrix_A[row][k] * matrix_B[k][col];
            }
        }
    }
    }
}

void print_matrix(double **matrix, int size) {
    cout << endl;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; ++col) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
}

double **create_matrix(int size) {

    double **matrix;

    matrix = new double *[size];

    for (int i = 0; i < size; i++) {
        matrix[i] = new double[size];
    }

    return matrix;
}

void initialize_matrix(double **matrix,int size) {

    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; ++col) {
            matrix[row][col] = (((double) rand() / RAND_MAX) * 100) + 1;
        }
    }

}


void destroy_matrix(double **matrix, int size) {

    for (int i = 0; i < size; i++) {
        delete[] matrix[i];
    }
}
