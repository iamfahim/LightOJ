//Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define PI             acos(-1.0)
#define IOS            ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf            1LL<<62  // this is minus inf
#define ms(a,b)         memset(a, b, sizeof(a))
#define check          cout<<"I am in here BRO!"<<endl;
const int MOD = (int)1e9+7;
struct matrix {
  int v[5][5];
  int row, col; // number of row and column
};
int mod = 10007;

// multiplies two matrices and returns the result
matrix multiply(matrix a, matrix b) {
  assert(a.col == b.row);
  matrix r;
  r.row = a.row;
  r.col = b.col;
  for (int i = 0; i < r.row; i++) {
    for (int j = 0; j < r.col; j++) {
      int sum = 0;
      for (int k = 0; k < a.col;  k++) {
        sum += a.v[i][k] * b.v[k][j];
        sum %= mod;
      }
      r.v[i][j] = sum;
    }
  }
  return r;
}

// returns mat^p
matrix power(matrix mat, int p) {
  assert(p >= 1);
  if (p == 1) return mat;
  if (p % 2 == 1)
    return multiply(mat, power(mat, p - 1));
  matrix ret = power(mat, p / 2);
  ret = multiply(ret, ret);
  return ret;
}
int  main()
{
    IOS
   //freopen("input.txt","r",stdin);
   // freopen("output.txt","wt",stdout);
    int tcase;
    int Case=0;
    int a, b, c,n;
    cin >> tcase;
     while (tcase--) {
    // input routine
    cin >>n>>a>>b>>c;

    // preparing the matrix
    matrix mat;
    mat.row = mat.col = 4;
    mat.v[0][0] =0; mat.v[0][1] =1;mat.v[0][2]=0;mat.v[0][3]=0;
    mat.v[1][0] =0; mat.v[1][1] =0;mat.v[1][2]=1;mat.v[1][3]=0;
    mat.v[2][0] =b; mat.v[2][1] =0;mat.v[2][2]=a;mat.v[2][3]=1;
    mat.v[3][0] =0; mat.v[3][1] =0;mat.v[3][2]=0;mat.v[3][3]=1;
    if (n < 3) {
      printf("Case %d: 0\n",++Case);
    } else {
      mat = power(mat, n -2);
      int ans = c*(mat.v[2][3]);
      ans %= mod;
      printf("Case %d: %d\n",++Case,ans);
    }
  }
    return 0;
}
