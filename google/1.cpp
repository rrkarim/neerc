import java.lang.System.*;

public class Answer {   
    public static int gcd(int a, int b) { 
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
    
    public static void inverse(int[][] A, int[][] A_den, int[][] inverse, int[][] inverse_den, int len) {
        int det = determinant(A, len);
        int[][] adj = new int[len][len];
        adjoint(A, adj, len);
		
		for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
				System.out.print(A[i][j] + " ");
			}
			System.out.println();
		}
		
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
				if(adj[i][j] == 0) {
					inverse[i][j] = adj[i][j];
					inverse_den[i][j] = det;
					continue;
				}
				int gcd_ = gcd(adj[i][j], Math.abs(det) );
                inverse[i][j] = adj[i][j] / gcd_;
                inverse_den[i][j] = det / gcd_;
            }
        }
    }
    
    public static void multiplication(int[][] F, int[][] F_den, int[][] R, int[][] R_den, int[][] res, int[][] res_den, int n, int m) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                int s = 0, s_den = 0;
                for(int z = 0; z < n; ++z) {
					if(z == 0) {
						s = F[i][z] * R[z][j];
						s_den = F_den[i][z] * R_den[i][z];
						int gcd_ = gcd(s, s_den);
						s /= gcd_; s_den /= gcd_;
						continue;
					}
					else {
						int temp = F[i][z] * R[z][j];
						int temp_den = F_den[i][z] * R_den[i][z];
						int gcd_ = gcd(temp, temp_den);
						temp /= gcd_;
						temp_den /= gcd_;
						int lcm_ = temp_den * s_den / gcd(temp_den, s_den);
						int st = s * (lcm_ / s_den) + temp * (lcm_ / temp_den);
						//
						gcd_ = gcd(st, lcm_);
						st /= gcd_; lcm_ /= gcd_;
						s = st; s_den = lcm_; 	    
					}                        
				}
				//System.out.println(i + ", " + j + "[ " + n + ", " + m + "]");
				res[i][j] = s;
				res_den[i][j] = s_den;
            }
        }
        return;
    }
    
    public static void main(String[] args) { 
	int[][] m = new int[][] {{0, 1, 0, 0, 0, 1}, {4, 0, 0, 3, 2, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0}};
        int N = m[0].length;
        
		
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
		//for(int i = 0; i < N; ++i) System.out.println(x[i]);
        
        for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N - i; ++j) {
                //swap(m[i][j], m[x[i]][x[j]]);
                int temp = m[i][j];
                m[i][j] = m[x[i]][x[j]];
                m[x[i]][x[j]] = temp;
            }
        }
		/*
		for(int i = 0; i < N; ++i) {
            for(int j = 0; j < N; ++j) {
				System.out.print(m[i][j] + " ");
			}
			System.out.println();
		}
		*/
        int n = N - line; int mn = line;
		System.out.println(line);
        int[][] Q = new int[n][n], Q_den = new int[n][n];
        for(int i = line; i < line + n; ++i) {
            int sum = 0;
			for(int j = line; j < line + n; ++j) {
                Q[i-line][j-line] = -m[i][j];
			}
			for(int j = 0; j < N; ++j) sum += m[i][j];
			
			for(int j = line; j < line + n; ++j) {
				Q_den[i-line][j-line] = sum;
			}
			for(int j = line; j < line + n; ++j) {
				if(i == j) Q[i-line][j-line] = sum + Q[i-line][j-line];
			}
			for(int j = line; j < line + n; ++j) {
				if(Q[i-line][j-line] != 0 && Q_den[i-line][j-line] != 0) {
					int gcd_ = gcd(Math.abs(Q[i-line][j-line]), Math.abs(Q_den[i-line][j-line]) );
					Q[i-line][j-line] = Q[i-line][j-line] / gcd_;
					Q_den[i-line][j-line] = Q_den[i-line][j-line] / gcd_;
				}
			}
        }
        
        int[][] R = new int[n][mn], R_den = new int[n][mn];
        int[][] res = new int[n][mn + 2], res_den = new int[n][mn+2];
        int[][] inv = new int[n][n], inv_den = new int[n][n];
	
        for(int i = line; i < line + n; ++i) {
			int sum = 0;
            for(int j = 0; j < N; ++j) sum += m[i][j];
			for(int j = 0; j < line; ++j) {
                R[i-line][j] = m[i][j];
            }
			for(int j = 0; j < line; ++j) {
				R_den[i-line][j] = sum;
			}
			for(int j = line; j < line; ++j) {
				if(R[i-line][j] != 0 && R_den[i-line][j] != 0) {
					int gcd_ = gcd(Math.abs(R[i-line][j]), Math.abs(R_den[i-line][j]) );
					R[i-line][j] = R[i-line][j] / gcd_;
					R_den[i-line][j] = R_den[i-line][j] / gcd_;
				}
			}
        }
        inverse(Q, Q_den, inv, inv_den, n);
		multiplication(inv, inv_den, R, R_den, res, res_den, n, mn);
		for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
				System.out.print(Q[i][j] + "/" + Q_den[i][j] + " 	");
			}
			System.out.println();
		}
		
        
		int global_lcm = inv_den[0][1];	
		System.out.println(global_lcm);
    } 
}
