#include "Matrix.h"

using std::cout;
using std::endl;

Matrix::Matrix () {

}

Matrix::Matrix (unsigned rows, unsigned cols) {
    rows_ = rows;
    cols_ = cols;

    matrix_.resize (rows_);

    for (unsigned i = 0; i < rows_; i++) {
        matrix_[i].resize(cols_, 0);
    }
}

Matrix::Matrix (vector<vector<float>> matrix) {

    matrix_ = matrix;

    rows_ = matrix.size();
    cols_ = matrix[0].size();
}



unsigned Matrix::get_rows () {

    return rows_;
}

unsigned Matrix::get_cols () {

    return cols_;
}

void Matrix::transpose () {

    vector<vector<float>> temp_mat;
    unsigned temp;

    temp_mat = matrix_;     // copy old matrix

    temp = rows_;       // switch rows and columns
    rows_ = cols_;
    cols_ = temp;

    matrix_.resize (rows_);

    for (unsigned i = 0; i < rows_; i++) {
        matrix_[i].resize(cols_, 0);
    }

    for (unsigned i = 0; i < rows_; i++) {      // copy old matrix into new
        for (unsigned j = 0; j < cols_; j++) {

            matrix_[i][j] = temp_mat[j][i];
        }
    }
 
}

void Matrix::print_mat () {

    for (unsigned i = 0; i < rows_; i++) {
        for (unsigned j = 0; j < cols_; j++) {

            cout << matrix_[i][j] << " ";

        }

        cout << endl;
    }
}

bool Matrix::load_mat (string filename) {

    std::ifstream in;
    in.open (filename);

    if (!in) {

        std::cerr << "Cannot open File: " << filename << endl;
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

    matrix_.resize (row);

    for (unsigned i = 0; i < row; i++) {
        matrix_[i].resize(col, 0);
    } 

    cout << "Matrix Size: " << matrix_.size() * matrix_[0].size() << endl;

    unsigned idx = 0;

    while (getline (in, line)) {

        for (unsigned i = 0; i < col; i++) {
            
            float elem = stof (line.substr (0, line.find(' ')));
            matrix_[idx][i] = elem;
            line = line.substr (line.find(' ') + 1, line.size());
            
        }

        idx++;

    }

    rows_ = row;
    cols_ = col;

    return true;
}

Matrix Matrix::operator+ (Matrix const &other) {

    Matrix result (this->rows_, this->cols_);
    result.matrix_.resize (this->rows_);

    for (unsigned i = 0; i < this->rows_; i++) {
        result.matrix_[i].resize (this->cols_, 0);
    }

    if (this->rows_ != other.rows_ || this->cols_ != other.cols_) {

        cout << "Invalid dimensions: " << endl;
        cout << "Got " << other.cols_ << " x " << other.rows_ << endl;
        cout << "Expected " << this->cols_ << " x " << this->cols_ << endl;

        return result;
    
    }

    for (unsigned i = 0; i < this->rows_; i++) {

        for (unsigned j = 0; j < this->cols_; j++) {

            result.matrix_[i][j] += this->matrix_[i][j] + other.matrix_[i][j];

        }
    }

    return result;
}