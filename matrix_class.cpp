#include<bits/stdc++.h>

using namespace std;

#define fst first
#define snd second

class Matrix{

private:
  pair<int,int> size;
  vector< vector<int> > a;

public:
  void make_space( pair<int,int> size_ ){
    size = size_;
    a.resize( size.fst , vector<int>(size.snd,0) );
  }

  Matrix () {}                          // pusty konstruktor
  Matrix ( pair<int,int> size_ ){       // konstruktor tworzacy macierz o określonym wymiarze
    make_space(size_);
  }
  Matrix( vector< vector<int> > a_  ){  // konstruktor tworzący macierz o ustalonych wyrazach
                                        // przyjmuje wektor zawierający kolejne wiersze macierzy
    make_space( {a_.size(),a_[0].size()} );
    for( int i=0; i<size.fst; i++ ){
      copy(a_[i].begin(),a_[i].end(),a[i].begin());
    }
  }
  Matrix( const Matrix& other ){       // konstruktor tworzący kopie macierzy

    make_space(other.size);
    for( int i=0; i<size.fst; i++ )
      copy(other.a[i].begin(),other.a[i].end(),a[i].begin());
  }

  void print( ){

    for( int i=0; i<size.fst; i++ ){
      for( int j=0; j<size.snd; j++ ){
        cout<<a[i][j]<<' ';
      }
      cout<<'\n';
    }
  }

  Matrix operator*( const int& t ){
    Matrix M = (*this);
    for( int i=0; i<size.fst; i++ )
      for( int j=0; j<size.snd; j++ )
        M.a[i][j]*=t;
    return M;
  }

  Matrix operator+( const Matrix&  A ){
    Matrix M = (*this);
    for( int i=0; i<size.fst; i++ )
      for( int j=0; j<size.snd; j++ )
        M.a[i][j]+=A.a[i][j];
    return M;
  }

  Matrix operator-( /*const*/ Matrix& A ){
    return (*this) + ( A * (-1) );
  }

  Matrix operator*(const Matrix& A ){
    int n = size.fst, m = size.snd, k = A.size.snd;
    Matrix M({n,k});

    for( int i=0; i<n; i++ )
      for( int j=0; j<k; j++ )
        for( int h=0; h<m; h++ )
          M.a[i][j]+=a[i][h]*A.a[h][j];

    return M;
  }

  friend ostream& operator<<( ostream& out, const Matrix& M ){
    for( int i=0; i<M.size.fst; i++ ){
      for( int j=0; j<M.size.snd; j++ )
        out<<M.a[i][j]<<' ';
      out<<'\n';
    }
    return out;
  }

  ~Matrix() {}
};

int main( )
{
  Matrix A({{1,2,4},{4,5,7},{7,8,0},{4,6,2},{1,6,2}});
  A.print();

  cout<<"\n\n";

  Matrix A_prim({4,5});
  A_prim.print();

  cout<<"\n\n";

  Matrix B(A);
  B.print();

  cout<<"\n\n";

  cout<<"mnozenie przez skalar :\n";
  Matrix C = B*5;
  C.print();

  cout<<"\n\n";

  cout<<"dodawanie :\n";
  Matrix D = C - B;
  D.print();

  cout<<"\n\n";

  cout<<"mnozenie :\n";
  Matrix E = Matrix({{1,2},{3,4}}) * Matrix({{0,2},{1,1}});
  cout<<E<<'\n';
}
