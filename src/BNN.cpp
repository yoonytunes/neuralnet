#include "BNN.h"
#include <unistd.h>

BNN::BNN () {}

void BNN::set_num_in () {

    unsigned num_in;

    cout << "Number of input units: " << endl;
    cin >> num_in;
    cout << endl;

    if (num_in < 1) {
        cout << "Must be at least 1 input, enter again: " << endl;
        set_num_in ();
    }

    num_in_ = num_in + 1;       // add bias unit
}

void BNN::set_num_out() {
    
    unsigned num_out;

    cout << "Number of output units: " << endl;
    cin >> num_out;
    cout << endl;

    if (num_out < 1) {
        cout << "Must be at least 1 output, enter again: " << endl;
        set_num_out ();
    }

    num_out_ = num_out + 1;     // add bias unit
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
        cout << endl;

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
                    temp[m][n] = (rand() % 60) - 30;
            }
        }

        weights_[i] = Matrix (temp);

    }

}

void BNN::set_inputs () {

    cout << "Dataset to use: " << endl;
    string dset, filename;
    cin >> dset;

    cout << endl;

    filename = "../data/dataset" + dset + ".txt";

    cout << "Accessing data from " << filename;

    for (unsigned i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        sleep(1);
    }

    cout << endl;

    Matrix m;
    m.load_mat (filename);      // initial inputs will have bias unit for now

    cout << endl;

    inputs_.resize (layers_.size()-1);
    inputs_[0] = m;

    for (unsigned j = 1; j < inputs_.size(); j++) {

        inputs_[j] = Matrix(layers_[j], 1);
        inputs_[j].set_bias();
    }

}

void BNN::build_network () {

    set_num_in ();
    set_num_out ();
    set_num_layers ();
    set_layers ();
    set_weights ();
    set_inputs ();

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

        weights_[i].print_mat();
        cout << endl;
    }
}

void BNN::print_inputs () {

    cout << "Inputs Matrices: " << endl;

    for (unsigned i = 0; i < inputs_.size(); i++) {

        inputs_[i].print_mat();
        cout << endl;
    }
}