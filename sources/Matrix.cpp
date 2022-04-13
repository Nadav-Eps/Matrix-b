#include "Matrix.hpp"
#include <iostream>
using namespace std;
const int tmp =100;

namespace zich
{

Matrix& Matrix::operator+() { 
    return *this; 
    }


Matrix& Matrix::operator-() { 
    return (*this*=-1); 
    }  

Matrix Matrix::operator +(const Matrix &nm){
    if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"vec size doenst match the rows and cols"};
    }
    Matrix mati(this->row,this->col);
    for (size_t i = 0; i < mati.row; i++)
    {
        for (size_t j = 0; j < mati.col; j++)
        {
            mati.mat[i][j]=this->mat[i][j]+nm.mat[i][j];
        }
        
    }
    return mati;

}


Matrix Matrix::operator*(const Matrix &nm) { 
    if(this->col!=nm.row){
        throw std::invalid_argument{"cant multiplie those matrix"};
    }

    Matrix mati(this->row,nm.col);
    for (size_t i = 0; i < mati.row; i++)
    {
        for (size_t j = 0; j < mati.col; j++)
        {
            mati.mat[i][j]=0;
            for (size_t p = 0; p < nm.row; p++)
            {
                mati.mat[i][j]+= nm.mat[p][j]*this->mat[i][p];
            }
            
        }
        
    }
    return mati;
 }


Matrix Matrix::operator*(const double num) { 
    Matrix mati(this->row,this->col);
    for (size_t i = 0; i < mati.row ; i++)
    {
        for (size_t j = 0; j < mati.col; j++)
        {
            mati.mat[i][j]= this->mat[i][j]*num;
        }
        
    }
    return mati;
 }


Matrix &Matrix::operator +=(const Matrix &nm){
    if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"vec size doenst match the rows and colss"};
    }
    for (size_t i = 0; i < nm.row; i++)
    {
        for (size_t j = 0; j < nm.col; j++)
        {
            this->mat[i][j]+=nm.mat[i][j];
        }
        
    }
    
    return *this;
}


Matrix &Matrix::operator +=(const double num){
    for (size_t i = 0; i < this->row; i++)
    {
        for (size_t j = 0; j < this->col; j++)
        {
            this->mat[i][j]+=num;
        }
        
    }
    
    return *this;
}


Matrix &Matrix::operator *=(const Matrix &nm){
    if(this->col!=nm.row){
        throw std::invalid_argument{"cant multiplie those matrix"};
    }
    
    Matrix mati(this->row,nm.col);
    for (size_t i = 0; i < mati.row; i++)
    {
        for (size_t j = 0; j < mati.col; j++)
        {
            mati.mat[i][j]=0;
            for (size_t p = 0; p < nm.row; p++)
            {
                mati.mat[i][j]+= nm.mat[p][j]*this->mat[i][p];
            }
            
        }
        
    }
    *this=mati;
    return *this;
}


Matrix& Matrix::operator*=(const double num) { 
     for (size_t i = 0; i < this->row; i++)
    {
        for (size_t j = 0; j < this->col; j++)
        {
            this->mat[i][j]*=num;
        }
        
    }
    
    return *this;
    }


Matrix Matrix::operator -(const Matrix &nm){
    if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"  this matsize doenst match the rows and cols"};
    }
    Matrix mati(this->row,this->col);
    for (size_t i = 0; i < mati.row; i++)
    {
        for (size_t j = 0; j < mati.col; j++)
        {
            mati.mat[i][j]=this->mat[i][j]-nm.mat[i][j];
        }
        
    }
    return mati;
}


Matrix &Matrix::operator -=(const Matrix &nm){
      if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"mat size doenst match the rows and cols"};
    }
    for (size_t i = 0; i < nm.row; i++)
    {
        for (size_t j = 0; j < nm.col; j++)
        {
            this->mat[i][j]-=nm.mat[i][j];
        }
        
    }
    
    return *this;
}


Matrix &Matrix::operator -=(const double num){
     for (size_t i = 0; i < this->row; i++)
    {
        for (size_t j = 0; j < this->col; j++)
        {
            this->mat[i][j]-=num;
        }
        
    }
    
    return *this;
}


Matrix Matrix::operator --(int n){
   Matrix tmp = *this;
    *this-=1;
    return tmp;
}


Matrix Matrix::operator ++(int n){
    Matrix tmp = *this;
    *this+=1;
    return tmp;
}


Matrix Matrix::operator --(){
    return (*this-=1);
}


Matrix Matrix::operator ++(){
   return (*this+=1);
}


bool Matrix::operator ==(const Matrix &nm) const {
     if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"mat size doenst match the rows and colsss"};
    }
    bool flag =true;
    for (size_t i = 0; i < nm.row; i++)
    {
        for (size_t j = 0; j < nm.col; j++)
        {
            if(nm.mat[i][j]!=this->mat[i][j]){
                flag=false;
            }
        }
        
    }
     return flag; }


bool Matrix::operator !=(const Matrix &nm) const {
     if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"cant compare with dif rows and cols"};
    }
    
    for (size_t i = 0; i < nm.row; i++)
    {
        for (size_t j = 0; j < nm.col; j++)
        {
            if(nm.mat[i][j]!=this->mat[i][j]){
                return true;
            }
        }
        
    }
     return false;
      }
     


bool Matrix::operator >(const Matrix &nm) const{
    if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"cant compare with dif rows and cols"};
    }
    int sum_t = 0;
    for (size_t i = 0; i < this->row ; i++)
    {
        for (size_t j = 0; j < this->col ; j++)
        {
            sum_t+= this->mat[i][j];
        }
        
    }
    int sum_s=0;
    for (size_t i = 0; i < nm.row ; i++)
    {
        for (size_t j = 0; j < nm.col ; j++)
        {
            sum_s+= nm.mat[i][j];
        }
        
    }
                return (sum_t>sum_s);
        }


bool Matrix::operator <(const Matrix &nm) const{
                if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"cant compare with dif rows and cols"};
    }
    int sum_t = 0;
    for (size_t i = 0; i < this->row ; i++)
    {
        for (size_t j = 0; j < this->col ; j++)
        {
            sum_t+= this->mat[i][j];
        }
        
    }
    int sum_s=0;
    for (size_t i = 0; i < nm.row ; i++)
    {
        for (size_t j = 0; j < nm.col ; j++)
        {
            sum_s+= nm.mat[i][j];
        }
        
    }
    
                return (sum_t<sum_s);
        }


bool Matrix::operator <=(const Matrix &nm) const{
                if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"cant compare with dif rows and cols"};
    }
    
    int sum_t = 0;
    for (size_t i = 0; i < this->row ; i++)
    {
        for (size_t j = 0; j < this->col ; j++)
        {
            sum_t+= this->mat[i][j];
        }
        
    }
    int sum_s=0;
    for (size_t i = 0; i < nm.row ; i++)
    {
        for (size_t j = 0; j < nm.col ; j++)
        {
            sum_s+= nm.mat[i][j];
        }
        
    }
    
                return (sum_t<=sum_s);
        }


bool Matrix::operator >=(const Matrix &nm) const{
              if(nm.col!=this->col||nm.row!=this->row){
        throw std::invalid_argument{"cant compare with dif rows and cols"};
    }
    int sum_t = 0;
    for (size_t i = 0; i < this->row ; i++)
    {
        for (size_t j = 0; j < this->col ; j++)
        {
            sum_t+= this->mat[i][j];
        }
        
    }
    int sum_s=0;
    for (size_t i = 0; i < nm.row ; i++)
    {
        for (size_t j = 0; j < nm.col ; j++)
        {
            sum_s+= nm.mat[i][j];
        }
        
    }
                return (sum_t>=sum_s);
        }


std::ostream &operator <<(std::ostream &out, const Matrix &nm){
                for (size_t i = 0; i < nm.row; i++)
                {
                    out<<"[";
                    for (size_t j = 0; j < nm.col; j++)
                    {
                        if(j!=nm.col-1){
                        out<<nm.mat[i][j]<<" ";
                        }
                        else{
                            out<<nm.mat[i][j];
                        }
                    }
                    if(i!=nm.row-1){
                    out<<"]"<<endl;
                    }
                    else{
                        out<<"]";
                    }
                }
                return out;
        }


std::istream &operator >>(std::istream &in, Matrix &nm){
                std::string data;
                std::getline(in,data);
                int r=0;
                int c =0;
                int num = 0;
                vector <double> ans;
                if(data[0]!='['||data[data.length()-1]!=']'){
                    throw std::invalid_argument("invalid input");
                }
                for (size_t i = 0; i < data.length(); i++)
                {
                    if(data[i]==']'&&i!=data.length()-1&&data[i+1]!=','){
                        throw std::invalid_argument("inv1!!");
                    }
                    if((data[i]==',')&&(data[i+1]!=' ')){
                        throw std::invalid_argument("invalid input!!@!");
                    }
                    if(isdigit(data[i])!=0){
                        num++;
                    }
                    if(data[i]==','){
                        r++;
                    }
                }
                r++;
                if(num%r!=0){
                    throw std::invalid_argument("invalid input!!$$$!");
                }
                c+=num/r;
                string s;
                string s1;
                int count=0;
                std::vector<double> result;
        for (size_t i = 0, j = 0; i < data.length(); j = ++i) {
            while (!(isdigit(data[i]) == 0)) {
                ++i;
            }
            if (i != j) {
                result.push_back(std::stod(data.substr(j, i - j)));
            }
        }
        nm = Matrix(result, r, c);
        return in;
        }


Matrix operator*(double num, Matrix const &nm){
    Matrix tmp = Matrix(nm);    
    tmp*=num;
    return tmp;
}

}