#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;

float sigmoid (float z);   // sigmoid function
float sigmoid_prime (float z);  // sigmoid derivative function

class Matrix {

    public:

        Matrix ();
        Matrix (unsigned rows, unsigned cols);
        Matrix (vector<vector<float> > matrix);

        unsigned get_rows ();
        unsigned get_cols ();

        Matrix transpose ();
        void print_mat ();
        bool load_mat (string filename);

        void set_bias ();

        Matrix to_sigmoid ();
        Matrix to_sigmoid_prime ();
        Matrix elemwise_mult (Matrix const &other);

        Matrix operator+ (Matrix const &other);
        Matrix operator- (Matrix const &other);
        Matrix operator* (Matrix const &other);
        
    
    private:

        unsigned rows_;
        unsigned cols_;
        vector<vector<float> > matrix_;
    
};
