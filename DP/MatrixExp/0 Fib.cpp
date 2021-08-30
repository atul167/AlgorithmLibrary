/*
| F[x] |  =  | 1 1 | | F[x-1] |
|F[x-1]|  =  | 1 0 |.| F[x-2] |

| F[n] |  =  | 1 1 |^(n-1) | F[1] |
|F[n-1]|  =  | 1 0 |      .| F[0] |

| F[n] |  =  | 1 1 |^(n-1) | 1 |
|F[n-1]|  =  | 1 0 |      .| 0 |
*/


typedef vector<vector<int>> matrix;
const int K = 2;

matrix mul(matrix A, matrix B) {
    matrix C(K, vector<int>(K));
    f(i, K)
        f(j, K)
            f(k, K)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, int p) {
    if (p == 1)
        return A;
    if (p % 2)
        return mul(A, pow(A, p-1));
    matrix X = pow(A, p/2);
    return mul(X, X);
}

// returns the N-th term of Fibonacci sequence
int fib(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;

    // create vector F1
    vector<int> F1 = {
        1,
        0
    };

    // create matrix T
    matrix T = {
        {1, 1},
        {1, 0}
    };

    // raise T to the (N-1)th power
    T = pow(T, N-1);

    // the answer is the first row of T.F1
    int res = 0;
    f(i, K) {
        res = (res + T[0][i] * F1[i]) % MOD;
    }
    return res;
}

void solve() {
    cin >> n;
    cout << fib(n) << endl;
}























typedef vector<vector<int>> matrix;
const int K = 2;

matrix mul(matrix A, matrix B) {
    matrix C(K, vector<int>(K));
    f(i, K)
        f(j, K)
            f(k, K)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(matrix A, int p) {
    // identity matrix
    vector< vector<int> > result(K, vector<int>(K, 0));
    for(int i = 0; i < K; i++) {
        result[i][i] = 1;
    }
    
    while (p > 0) {
        if (p & 1) result = mul(A, result);
        A = mul(A, A);
        p >>= 1;
    }
    return result;
}

// returns the N-th term of Fibonacci sequence
int fib(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;

    // create vector F1
    vector<int> F1 = {
        1,
        0
    };

    // create matrix T
    matrix T = {
        {1, 1},
        {1, 0}
    };

    // raise T to the (N-1)th power
    T = pow(T, N-1);

    // the answer is the first row of T.F1
    int res = 0;
    f(i, K) {
        res = (res + T[0][i] * F1[i]) % MOD;
    }
    return res;
}

void solve() {
    cin >> n;
    cout << fib(n) << endl;
}
























const int MAXN = 1e5+5;
const int N = 1e5+5;
int n, m;

const long long _MOD = static_cast<long long>(MOD) * MOD;

struct Matrix {
    vector< vector<int> > mat;
    int n_rows, n_cols;
 
    Matrix() {}
 
    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()), n_cols(values[0].size()) {}
 
    static Matrix identity_matrix(int n) {
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            values[i][i] = 1;
        }
        return values;
    }
 
    Matrix operator*(const Matrix &other) const {
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                long long tmp = 0;
                for(int k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while(tmp >= _MOD)
                        tmp -= _MOD;
                }
                result[i][j] = tmp % MOD;
            }
 
        return move(Matrix(move(result)));
    }
 
    inline bool is_square() const {
        return n_rows == n_cols;
    }
};
Matrix pw(Matrix a, int p){
    Matrix result = Matrix::identity_matrix(a.n_cols);
    while (p > 0) {
        if (p & 1)
            result = a * result;
        a = a * a;
        p >>= 1;
    }
    return result;
}
 
void solve(){
    cin >> n;
    if(n == 0 || n == 1) {
        cout << n << endl;
        return;
    }
    
    vector<vector<int>> T = {
        {1,1},
        {1,0}
    };
    
    vector<vector<int>> col = 
    {
        {1},
        {0}
    };
    
    int ans = (pw(T,n-1) * col).mat[0][0];
    cout << ans << endl;
}
