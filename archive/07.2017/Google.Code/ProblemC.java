/*
	rkerimov@std.qu.edu.az
*/
import java.lang.System.*;

public class Answer {   
    
	public static int[] GetFraction(double input){
		double tolerance = 0.0001, p1 = 1, q1 = 0, p2 = 0, q2 = 1;
		double b = input;
		do {
			double a = Math.floor(b);
			double aux = p1;
			p1 = a*p1+p2; 
			p2 = aux;
			aux = q1; 
			q1 = a*q1+q2; 
			q2 = aux;
			b = 1/(b-a);
		} 
		while(Math.abs(input-p1/q1) > input*tolerance);
		return new int[] {(int)p1, (int)q1};
	}
	
	public static int lcm(int a, int b){
        return (a * b) / gcd(a, b);
    }
	
	public static int gcd(int a, int b) { 
		int c;
		while(a != 0) {
			c = a;
			a = b % a;
			b = c;
		}
		return b;
    }
    public static void getFactor(float[][] A, float[][] temp, int p, int q, int n) {
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
    public static float determinant(float[][] A, int n) {
        float D = 0;
        if(n == 1) return A[0][0];
        float[][] temp = new float[n][n];
        int sign = 1;
        for(int f = 0; f < n; ++f) {
            getFactor(A, temp, 0, f, n);
            D += sign * A[0][f] * determinant(temp, n - 1);
            sign = -sign;
        }
        return D;
    }
    
	public static void adjoint(float A[][], float adj[][], int len) {
		if (len == 1) {
			adj[0][0] = 1;
			return;
		}
	 
		int sign = 1;
		float temp[][] = new float[len][len];
	 
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				getFactor(A, temp, i, j, len);
	 
				sign = ((i+j)%2==0)? 1: -1;
	 
				adj[j][i] = (sign)*(determinant(temp, len-1));
			}
		}
	}
    
    public static void inverse(float[][] A, float[][] inverse, int len) {
        float det = determinant(A, len);
        
		float[][] adj = new float[len][len];
        adjoint(A, adj, len);
        for(int i = 0; i < len; ++i) {
            for(int j = 0; j < len; ++j) {
                inverse[i][j] = adj[i][j] / det;
            }
        }
    }
    
    public static void multiplication(float[][] F, float[][] R, float[][] res, int n, int m) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
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
		int[][] md = new int[N][N];
		int[] xd = new int[N];
		for(int j = 0; j < N; ++j) {
			xd[x[j]] = j;
		}
		
        for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				md[i][j] = m[xd[i]][xd[j]];
			}
        }
		
		for(int i = 0; i < N; ++i) {
			for(int j = 0; j < N; ++j) {
				m[i][j] = md[i][j];
			}
		}
		
		
        int n = N - line; int mn = line;
		
		if(n == 0) {
		    int[] ret = new int[N + 1];
		    ret[0] = 1;
		    ret[N] = 1;
		    return ret;
		}
		
        float[][] Q = new float[n][n];
		
		for(int i = line; i < line + n; ++i) {
			float sum = 0;
            for(int j = line; j < line + n; ++j) {
				Q[i-line][j-line] = m[i][j];
			}
			for(int j = 0; j < N; ++j) sum += m[i][j];
			for(int j = line; j < line + n; ++j) Q[i-line][j-line] /= sum;
		 }
		
        for(int i = line; i < line + n; ++i) {
            for(int j = line; j < line + n; ++j) {
                if(i == j) Q[i-line][j-line] = 1 - Q[i-line][j-line];
				else Q[i-line][j-line] = -Q[i-line][j-line];
			}
        }
        float[][] R = new float[n][mn];
        float[][] res = new float[n][mn + 2];
        float[][] inv = new float[n][n];
	
        for(int i = line; i < line + n; ++i) {
            float sum = 0;
			for(int j = 0; j < line; ++j) {
                R[i-line][j] = m[i][j];
            }
			for(int j = 0; j < N; ++j) sum += m[i][j];
			for(int j = 0; j < line; ++j) R[i-line][j] /= sum;
        }
        inverse(Q, inv, n);
        multiplication(inv, R, res, n, mn);
		int[] t = GetFraction(res[0][0]);
		int global_lcm = t[1];
		System.out.println(res[0][0]);
		for(int i = 1; i < mn; ++i) {
			t = GetFraction(res[0][i]);
			int gcd_ = gcd(global_lcm, t[1]);
			System.out.println(res[0][i]);
			global_lcm *= t[1];
			global_lcm /= gcd_;
		}
		int ret[] = new int[line + 1];
		for(int i = 0; i < mn; ++i) {
		    t = GetFraction(res[0][i]);
		    ret[i] = global_lcm / t[1] * t[0];
		}
		ret[mn] = global_lcm;
        return ret;
    } 
    
    public static void main(String[] args) { 
		//some tests
		int[][] m = new int[][] { { 28 ,26 ,20 ,4 ,24}, { 0 ,0 ,0 ,0 ,0}, { 0 ,0 ,0 ,0 ,0}, { 23 ,16 ,7 ,19 ,8}, { 11 ,10 ,8 ,16 ,20}};
		int[] t = answer(m);
		for(int i = 0; i < t.length; ++i) {
			System.out.println(t[i]);
		}
    } 
}