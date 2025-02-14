#include "simple_matrix.hpp"
   
        
SimpleMatrix::SimpleMatrix(std::size_t num_rows, std::size_t num_cols)  
{   
    if(num_rows <= 0 || num_cols <= 0)
    {
        throw Invalid{};
    }
    this->data_.resize(num_rows);
    for(int i = 0; i < num_rows; i++)
    {
        this->data_[i].resize(num_cols, 0);
    }   
}

SimpleMatrix::SimpleMatrix(std::size_t nrows, std::size_t ncols, double init)
{
    if(nrows <= 0 || ncols <= 0)
    {
        throw Invalid{};
    }
    data_.resize(nrows);
    for(int i = 0; i < nrows; i++)
    {
        data_[i].resize(ncols, init);
    }
}

// initializer matrix
SimpleMatrix::SimpleMatrix(std::initializer_list<std::initializer_list<double>> matrix_second)
{
    
    int n_rows = matrix_second.size();
    int n_cols = (*matrix_second.begin()).size();

    if(n_rows <= 0 || n_cols <= 0)
    {
        throw Invalid{};
    }
    data_.resize(n_rows);

    for(int i = 0; i < n_rows; i++)
    {
        data_[i].resize(n_cols, 0);
    }

    int x = 0;
    int y = 0;

    for(auto i = matrix_second.begin(); i != matrix_second.end(); i++)
    {
        auto col = *i;
        for(auto j = col.begin(); j != col.end(); j++)
        {
            if(y == data_[0].size())
            {
                throw Invalid{};
            }   
            data_[x][y]= *j;
            y++;
        }
        
        x++;
        if(y < data_[0].size())
        {
            throw Invalid{};
        }
        y = 0;
    }

}

// copy constructor
SimpleMatrix::SimpleMatrix(const SimpleMatrix& other_mat)
{
    int n_rows = other_mat.nrows();
    int n_cols = other_mat.ncols();

    if((n_rows <= 0) || (n_cols <= 0))
    {
        throw Invalid{};
    } 

    data_.resize(n_rows);

    for(int i = 0; i < n_rows; i++)
    {
        data_[i].resize(n_cols, 0);
    }

    for(int i = 0; i < n_rows ; i++)
    {
        for(int j =0; j< n_cols; j++)
        {
            data_[i][j] = other_mat.data_[i][j];
        }
    }

}
// move constructor
SimpleMatrix::SimpleMatrix(SimpleMatrix&& other_mat) 
{
    if((other_mat.nrows() <= 0) || (other_mat.ncols() <= 0))
    {
        throw Invalid{};
    } 
    this -> data_ = std::move(other_mat.data_);
}

//copy assignment
SimpleMatrix& SimpleMatrix::operator=(const SimpleMatrix& other_mat)
{
    if((other_mat.nrows() <= 0) || (other_mat.ncols() <= 0))
    {
        throw Invalid{};
    } 
    this -> data_ = other_mat.data_;
    return *this;

}

// move assignment
SimpleMatrix& SimpleMatrix::operator=(SimpleMatrix&& other_mat)
{
    if((other_mat.nrows() <= 0) || (other_mat.ncols() <= 0))
    {
        throw Invalid{};
    } 
    this -> data_ = std::move(other_mat.data_);
    return *this;
}

// member function for number of rows
std::size_t SimpleMatrix::nrows() const 
{
    return data_.size();
}

// member function for number of columns
std::size_t SimpleMatrix::ncols() const
{
    return data_[0].size();
}

//Operator(i,j) to access and modify the matrix elements
double& SimpleMatrix::operator()(std::size_t i, std::size_t j)
{
    if((i >= this->nrows()) || (j >= this->ncols()))
    {
        throw Invalid{};
    }
    return data_[i][j]; 
}
double SimpleMatrix::operator()(std::size_t i, std::size_t j) const
{
    if((i >= this->nrows()) || (j >= this->ncols()))
    {
        throw Invalid{};
    }
    return data_[i][j];
}

//set Matrix
void SimpleMatrix::set_matrix(std::vector<std::vector<double>> data)
{
    if((data.size() != this->nrows()) || (data[0].size() != this->ncols()))
    {
        throw Invalid{};
    }

    this->data_.resize(data.size());
    for(int i = 0; i < data.size(); i++)
    {
        this->data_[i].resize(data[0].size(), 0);
    }

    for(int i = 0; i < data.size(); i++)
    {
        for(int j= 0; j < data[0].size(); j++)
        {
            this-> data_[i][j] = data[i][j];
        }
    }
}

