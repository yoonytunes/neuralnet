#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::string;
using std::vector;

class Matrix {

    public:

        Matrix ();
        Matrix (unsigned rows, unsigned cols);
        Matrix (vector<vector<float>> matrix);

        unsigned get_rows ();
        unsigned get_cols ();

        void transpose ();
        void print_mat ();
        bool load_mat (string filename);

        void set_bias ();

        Matrix operator+ (Matrix const &other);
        Matrix operator- (Matrix const &other);
        Matrix operator* (Matrix const &other);
    
    private:

        unsigned rows_;
        unsigned cols_;
        vector<vector<float>> matrix_;
    
};