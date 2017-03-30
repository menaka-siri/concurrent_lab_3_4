CS4532 Concurrent Programming   --- Take Home Lab 3 and 4

Group Members:
Dinindu Nissanka        120434D
Menaka Lahiru Sirisena	120628C


Github repo: https://github.com/menaka-siri/concurrent_lab_3_4

Step 1: Go to the project folder location in system terminal and type following shell commands

Step 1: Compile the .cpp files 

1. $g++ sequential.cpp -std=c++11 -o sequential 
2. $g++ openMP_parallel_multiplication.cpp -std=c++11 -o parallel
3. $g++ transpose.cpp -std=c++11 -o simd
4. $g++ -msse3 simd_matrix_multiplication.cpp -std=c++11 -o simd


Step 2: Execute the compiled files. When the programs run, they ask for the 'number of program iterations' and 'size of the matices'; enter appropriate values for those two parameters.
 
1. ./sequential
2. ./parallel
3. ./transpose
4. ./simd