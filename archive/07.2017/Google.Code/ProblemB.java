package com.google.challenges; 
import java.util.*;

public class Answer {   
    public static int sink, s, inf = Integer.MAX_VALUE, d, n;
    public static int[] v, from;
    public static int maxFlow(int[][] m) {
        int res = 0;
        while(true) {
            d = 1;
            int pathCapacity = bfs(m);
            if(d == 0) break;
            res += pathCapacity;
        }
        return res;
    }
    public static int bfs(int[][] m) {
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        v = new int[n + 1];
        from = new int[n + 1];
        Arrays.fill(v, 0);
        Arrays.fill(from, -1);
        v[s] = 1;
        outerloop:
        while(!q.isEmpty()) {
            int where = q.poll();
            for(int i = 0; i < n; ++i) {
                int next = i;
                if(v[next] == 0 && m[where][next] > 0) {
                    q.add(next);
                    v[next] = 1;
                    from[next] = where;
                    if(next == sink) {
                        break outerloop; 
                    }
                }
            }
        }
        int where = sink, pathCap = inf;
        while(from[where] > -1) {
            int prev = from[where];
            pathCap = Math.min(pathCap, m[prev][where]);
            where = prev;
        }
        where = sink;
        while(from[where] > -1) {
            int prev = from[where];
            m[prev][where] -= pathCap;
            m[where][prev] += pathCap;
            where = prev;
        }
        if(pathCap == inf) {
            d = 0;
            return 0;
        }
        return pathCap;
    }
    public static int answer(int[] entrances, int[] exits, int[][] path) { 
        n = path[0].length;
        int[][] m = new int[n+3][n+3];
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                m[i][j] = path[i][j];
            }
        }
        s = n; sink = n + 1;
        n += 2;
        for(int i : entrances) m[s][i] = inf;
        for(int i : exits) m[i][sink] = inf;
        return maxFlow(m);
    } 
}