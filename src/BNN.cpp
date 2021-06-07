#include "BNN.h"
#include <unistd.h>
#include <cmath>
#include <assert.h>

BNN::BNN () {}

void BNN::fwd_prop () {

    assert (weights_.size() == inputs_.size());

    for (unsigned i = 0; i < weights_.size(); i++) {

        z_[i] = weights_[i] * inputs_[i];

        if (i == weights_.size() - 1) {

            outputs_ = z_[i].to_sigmoid();
        }

        else {

            inputs_[i+1] = z_[i].to_sigmoid();
        }
    }
}

void BNN::bck_prop () {

    calculate_error();
}

void BNN::calculate_error () {

    error_ = expected_ - outputs_;

}

void BNN::set_num_in () {

    cout << "Dataset to use: " << endl;
    string dset, filename;
    cin >> dset;

    dset_ = dset;
    
    cout << endl;

    filename = "../data/dataset" + dset + ".txt";
    filename_ = filename;

    cout << "Accessing data from " << filename;

    for (unsigned i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        sleep(1);
    }


    Matrix m;
    m.load_mat(filename_);

    unsigned num_in = m.get_rows();

    cout << "Number of input units: " << num_in << endl;
   

    if (num_in < 1) {
        cout << "Must be at least 1 input, enter again: " << endl;
        set_num_in ();
    }

    num_in_ = num_in;       // add bias unit
}

void BNN::set_num_out() {

    string filename;

    filename = "../data/expected" + dset_ + ".txt";

    expected_.load_mat(filename);

    num_out_ = expected_.get_rows();

    cout << "Accessing data from " << filename;

    for (unsigned i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        sleep(1);
    }
    
    cout << endl;
    
    cout << "Number of output units: " << num_out_ << endl;

    cout << endl;

    if (num_out_ < 1) {
        cout << "Must be at least 1 output, enter again: " << endl;
        set_num_out ();
    }
}


void BNN::set_num_layers () {
    
    unsigned num_hidden;

    cout << "Number of hidden layers: " << endl;
    cin >> num_hidden;
    cout << endl;

    num_hidden_ = num_hidden;
}

void BNN::set_layers () {

    layers_.resize(num_hidden_ + 2, 0);
    layers_[0] = num_in_;
    layers_[layers_.size() - 1] = num_out_;

    for (unsigned i = 1; i < layers_.size() - 1; i++) {

        unsigned n;

        cout << "Number of units for hidden layer " << i << ": " << endl;
        cin >> n;
        n += 1;

        layers_[i] = n;
    }
}

void BNN::set_weights () {

    unsigned weights_dim = num_hidden_ + 1;
    weights_.resize(weights_dim);

    for (unsigned i = 0; i < weights_.size(); i++) {

        unsigned r = layers_[i+1];
        unsigned c = layers_[i];

        vector<vector<float>> temp;

        temp.resize(r);
        for (unsigned j = 0; j < r; j++) {
            temp[j].resize(c, 0);
        }

        for (unsigned m = 0; m < r; m++) {
            for (unsigned n = 0; n < c; n++) {

                if (m == 0)
                    temp[m][n] = 0;
                
                else 
                    temp[m][n] = ((rand() % 200) - 100) / 100.0;
            }
        }

        weights_[i] = Matrix (temp);

    }

}

void BNN::set_inputs () {


    Matrix m;
    m.load_mat (filename_);      // initial inputs will have bias unit for now

    inputs_.resize (num_hidden_ + 1);
    inputs_[0] = m;

    for (unsigned j = 1; j < inputs_.size(); j++) {

        inputs_[j] = Matrix(layers_[j], 1);
        inputs_[j].set_bias();
    }

}

void BNN::set_z () {

    cout << "Initializing sigmoid input matrices";

    for (unsigned i = 0; i < 3; i++) {

        cout << ".";
        cout.flush();
        sleep(1);
    }

    cout << endl;

    z_.resize (num_hidden_ + 1, Matrix (1,1));

    cout << endl;
}


void BNN::build_network () {

    set_num_in ();
    set_num_out ();
    set_num_layers ();
    set_layers ();
    set_weights ();
    set_inputs ();
    set_z ();


    cout << "Building Neural Network";
    cout.flush();
    sleep (1);

    for (unsigned i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        sleep (1);
    }
    
    cout << endl;
    cout << "Build finished." << endl;
    cout.flush();
    sleep (1);
    cout << endl;



}

void BNN::print_layers () {

    cout << "Units per layer (including bias unit): " << endl;

    for (unsigned i = 0; i < layers_.size(); i++) {
        
        if (i == 0)
            cout << "[In]: " << layers_[i] << endl;

        else if (i == layers_.size() - 1) 
            cout << "[Out]: " << layers_[i] << endl;

        else
            cout << "[" << i << "]: " << layers_[i] << endl;

    }

    cout << endl;
}

void BNN::print_weights () {

    cout << "Weights Matrices: " << endl;

    for (unsigned i = 0; i < weights_.size(); i++) {

        cout << "[" << i << "]: ";
        weights_[i].print_mat();
        cout << endl;
    }
}

void BNN::print_inputs () {

    cout << "Inputs Matrices: " << endl;

    for (unsigned i = 0; i < inputs_.size(); i++) {

        cout << "[" << i << "]: ";
        inputs_[i].print_mat();
        cout << endl;
    }
}

void BNN::print_z () {

    cout << "Input Matrices to sigmoid: " << endl;

    for (unsigned i = 0; i < z_.size(); i++) {

        cout << "[" << i << "]: ";
        z_[i].print_mat();
        cout << endl;
    }

}

void BNN::print_outputs () {

    
    cout << "Output Matrix: " << endl;
    cout << "[0]: ";
    outputs_.print_mat();
    cout << endl;

}

void BNN::print_expected () {

    cout << "Expected Matrix: " << endl;
    cout << "[0]: ";
    expected_.print_mat();
    cout << endl;

}

void BNN::print_error () {

    cout << "Error Matrix: " << endl;
    cout << "[0]: ";
    error_.print_mat();
    cout << endl;
    
}