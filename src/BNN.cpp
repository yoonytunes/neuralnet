#include "BNN.h"

BNN::BNN () {}

void BNN::set_num_in () {

    unsigned num_in;

    cout << "Number of input units: " << endl;
    cin >> num_in;
    cout << endl;

    num_in_ = num_in + 1;       // add bias unit
}

void BNN::set_num_out() {
    
    unsigned num_out;

    cout << "Number of output units: " << endl;
    cin >> num_out;
    cout << endl;

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

void BNN::initialize () {

    set_num_in ();
    set_num_out ();
    set_num_layers ();
    set_layers ();

}