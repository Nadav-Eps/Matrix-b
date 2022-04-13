#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

namespace zich {
   class Matrix{
      private :
        vector<vector<double>> mat;
        int row;
        int col;


   

      public :
   Matrix(std::vector<double> vec,int r,int c) 
   {
       if(vec.size()!=c*r) {throw std::invalid_argument{"vec size doenst match the rows and cols"};}
       row=r;
       col=c;
       size_t n;
       for (size_t i = 0; i < r; i++)
       {
          vector<double> myVector;
           for (size_t j = 0; j < c; j++)
           {
               n= (size_t)((size_t)((size_t)(c-1)*i)+i+j);
               myVector.push_back(vec.at(n));
           }
           mat.push_back(myVector);
       }
   }  
     Matrix(int r, int c){
        row=r;
        col=c;
      mat.resize((size_t)r);
      for (size_t i = 0; i < r; i++)
      {
         mat[i].resize((size_t)c);
      }
   }   

   Matrix(const Matrix &nm){
      mat.resize((size_t)nm.row);
      row=nm.row;
      col=nm.col;
      for (size_t i = 0; i < nm.row; i++)
      {
         mat[i].resize((size_t)nm.col);
         for (size_t j = 0; j < nm.col; j++)
         {
            mat[i][j]=nm.mat[i][j];
         }  
      }
      }

   Matrix& operator+();
   Matrix& operator-();
   Matrix operator*(const Matrix &nm);
   Matrix operator*(const double num);

//Binary operators
   Matrix operator+(const Matrix &nm);
   Matrix &operator+=(const Matrix &nm);
   Matrix &operator+=(const double num);
   Matrix &operator*=(const Matrix &nm);
   Matrix &operator*=(const double num);
   Matrix operator-(const Matrix &nm);
   Matrix &operator-=(const Matrix &nm);
   Matrix &operator-=(const double num);

//Operators that increments the object they work on
   Matrix operator --();
   Matrix operator --(int);
   Matrix operator ++();
   Matrix operator ++(int);

   //Cmoparation operators
   bool operator ==(const Matrix& nm)const;
   bool operator !=(const Matrix& nm)const;
   bool operator >(const Matrix& nm)const;
   bool operator <(const Matrix& nm)const;
   bool operator <=(const Matrix& nm)const;
   bool operator >=(const Matrix& nm)const;

   
   friend ostream& operator <<(ostream& out, const Matrix& nm);
   friend istream& operator >>(istream& in, Matrix& nm);
   friend Matrix operator*(double num, Matrix const &nm);
  
   
   };
}