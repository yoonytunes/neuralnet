#include "BNN.h"
#include "Matrix.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::string;

void print_mat (vector<vector<float>> matrix) {

    for (unsigned i = 0; i < 3; i++) {
        for (unsigned j = 0; j < 2; j++) {

            cout << matrix[i][j] << " ";

        }

        cout << endl;
    }
}

bool load_mat (string file_in, vector<vector<float>> &matrix) {

    std::ifstream in;
    in.open (file_in);

    if (!in) {

        std::cerr << "Cannot open File: " << file_in << endl;
        return false;
    }

    string line;
    unsigned row, col;


    getline (in, line);

    if (line.size() > 0) {

        row = stoi (line.substr (0, line.find (' ')));
        line = line.substr (line.find (' ') + 1, line.size());
        col = stoi (line.substr (0, line.find(' ')));
        line = line.substr (line.find (' ') + 1, line.size());
    }

    cout << "Rows: " << row << endl;
    cout << "Columns: " << col << endl;

    matrix.resize (row);

    for (unsigned i = 0; i < row; i++) {
        matrix[i].resize(col, 0);
    } 

    cout << "Matrix Size: " << matrix.size() * matrix[0].size() << endl;

    unsigned idx = 0;

    while (getline (in, line)) {

        for (unsigned i = 0; i < col; i++) {
            
            float elem = stof (line.substr (0, line.find(' ')));
            matrix[idx][i] = elem;
            line = line.substr (line.find(' ') + 1, line.size());
            
        }

        idx++;

    }

    return true;
}

int main () {

    // vector<vector<float>> matA, matB;

    // load_mat ("../test_data/matA.txt", matA);   
    // load_mat ("../test_data/matB.txt", matB);
    
    // cout << endl;

    Matrix a, b, c;

    a.load_mat ("../test_data/matA.txt");
    cout << endl;
    a.print_mat();
    cout << endl;

    b.load_mat ("../test_data/matB.txt");
    cout << endl;
    b.print_mat();
    cout << endl;

    a.transpose();
    a.print_mat();

    cout << endl;

    c = a * b;
    c.print_mat();

    cout << endl;
    
    cout << "sigmoid(-3): " << sigmoid(-3) << endl;
    cout << "sigmoid(0): " << sigmoid(0) << endl;
    cout << "sigmoid(2): " << sigmoid(2) << endl;
    cout << "sigmoid(1.24): " << sigmoid (1.24) << endl;

    cout << endl;

}