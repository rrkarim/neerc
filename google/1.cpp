package com.google.challenges; 

public class Answer {   
    public static int gcd(int n, int m) { 
	int c;
	while(a != 0) {
		c = a;
		a = b % a;
		b = c;
	}
	return b;
    }
    public static void getFactor(int[][] A, int[][] temp, int p, int q, int n) {
        int i = 0, j = 0;
        for(int row = 0; row < n; ++row) {
            for(int col = 0; col < n; ++col) {
                if(row != p && col != q) {
                    temp[i][j++] = A[row][col];
                    if(j == n - 1) {
                        j = 0; i += 1;
                    }
                }
            }   
        }
    }
    public static int determinant(int[][] A, int n) {
        int D = 0;
        if(n == 1) return A[0][0];
        int[][] temp = new int[n][n];
        int sign = 1;
        for(int f = 0; f < n; ++f) {
            getFactor(A, temp, 0, f, n);
            D += sign * A[0][f] * determinant(temp, n - 1);
            sign = -sign;
        }
        return D;
    }
    
    public static void adjoint(int[][] A, int[][] adj, int len) {
        if(len == 1) {
            adj[0][0] = 1;
            return;
        }
        int sign = 1, temp[][] = new int[len][len];
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
                getFactor(A, temp, i, j, len);
                sign = ( (i+j) % 2 == 0) ? 1 : -1;
                adj[i][j] = sign * determinant(temp, len - 1);
            }
        }
    }
    
    public static void inverse(int[][] A, int[][] inverse, int[][] inverse_den, int len) {
        int det = determinant(A, len);
        int[][] adj = new int[len][len];
        adjoint(A, adj, len);
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
		int gcd_ = gcd(adj[i][j], det);
                inverse[i][j] = adj[i][j] / gcd_;
                inverse_den[i][j] = det / gcd_;
            }
        }
    }
    
    public static void multiplication(float[][] F, int[][] R, float[][] res, int n, int m) {
        for(int i = 0; i < n; ++i) {
            for(in j = 0; j < m; ++j) {
                float s = 0;
                for(int z = 0; z < n; ++z) {
                    s += F[i][z] * R[z][j];
                }
                res[i][j] = s;
            }
        }
        return;
    }
    
    public static int[] answer(int[][] m) { 
        
        int N = m[0].length;
        //int[][] adj = new int[N][N];                       
        //adjoint(m, adj);
        //inverse(m, inv);
        
        int[] x = new int[N];
        for(int i = 0; i < N; ++i) x[i] = -1;
        int index = 0, line = -1;
        for(int i = 0; i < N; ++i) {
            int c = 0;
            for(int j = 0; j < N; ++j) {
                if(m[i][j] > 0) c += 1;
            }
            if(c == 0) {
                x[i] = index++;
            }
        }
        line = index;
        for(int i = 0; i < N; ++i) {
            if(x[i] == -1) {
                x[i] = index++;
            }
        }
        
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
                //swap(m[i][j], m[x[i]][x[j]]);
                int temp = m[i][j];
                m[i][j] = m[x[i]][x[j]];
                m[x[i]][x[j]] = temp;
            }
        }
        int n = N - line, m = line;
        int[][] Q = new int[n][n];
        for(int i = line; i < line + n; ++i) {
            for(int j = line; j < line + n; ++j) {
                Q[i][j] = m[i][j];
                if(i == j) Q[i][j] = 1 - Q[i][j];
            }
        }
        
        int[][] R = new int[n][m];
        float[][] res = new float[n][m + 2];
        int[][] inv = new int[n][n], inv_den = new int[n][n];
        for(int i = line; i < line + n; ++i) {
            for(int j = 0; j < line; ++j) {
                R[i][j] = m[i][j];
            }
        }
        
        inverse(Q, inv, inv_den, n);
        multiplication(inv, R, res, n, m);
        
        return Q[0];
    } 
}