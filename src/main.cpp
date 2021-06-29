#include "BNN.h"

int main () {

    BNN bnn;
    bnn.build_network();

    bnn.fwd_prop();
    bnn.bck_prop();

    // bnn.print_layers();
    bnn.print_weights();
    bnn.print_inputs ();
    // bnn.print_z ();
    bnn.print_outputs();
    bnn.print_expected();
    bnn.print_error ();


}