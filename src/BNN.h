#pragma once

#include "Matrix.h"
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::string;

float sigmoid (float z);   // sigmoid function

class BNN {


    public: 

        BNN ();

        void build_network();

        void fwd_prop ();
        void bck_prop ();

        void set_num_in ();      // sets inputs
        void set_num_out();     // sets outputs
        void set_num_layers ();      // sets num hidden
        void set_layers ();
        void set_weights ();
        void set_inputs ();
        void set_z ();

        void print_layers ();   // print number of units per layer vector
        void print_weights ();  // print weights matrices
        void print_inputs ();   // print inputs to each layer
        void print_z ();        // print inputs to sigmoid 
        void print_outputs ();  // print outputs
        void print_expected ();
        void print_error ();
        
        void calculate_error ();


        unsigned unroll (unsigned i, unsigned j, unsigned cols);
        Matrix matmul (Matrix a, Matrix b);     // multiply two matrices


    private:

        vector<Matrix> weights_;      // inner vector contains matrix objects
        Matrix outputs_;        // outputs to neural network
        Matrix expected_;       // matrix of expected outputs
        vector<Matrix> inputs_;    // column matrices for inputs per layer
        vector<unsigned> layers_;            // keeps track of number of units per layer
        Matrix error_;              // error of output vs actual
        unsigned num_in_;                // number of inputs (with bias unit)
        unsigned num_out_;               // number of outputs (with bias unit)
        unsigned num_hidden_;           // number of hiddenlayers in architecture
        vector<Matrix> z_;          // vector containing pre-sigmoid output matrix for each layer
        string dset_;
        string filename_;


        

};