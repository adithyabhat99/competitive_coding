// https://leetcode.ca/all/562.html
import java.util.*;
public class LongestLine
{
    public static class Node {
        public int left;
        public int top;
        public int topLeft;
        
        public Node() {
            left = 0;
            top = 0;
            topLeft  = 0;
        }
        public Node(int l, int t, int tl) {
            this.left = l;
            this.top = t;
            this.topLeft = tl;
        }
        public int getMax() {
            return Integer.max(left, Integer.max(top, topLeft));
        }
    }
    
	public static void main(String[] args) {
	    int[][] input = {{0,1,1,0},
         {0,1,1,0},
         {0,0,0,1}};
		System.out.println(longestLine(input, 3, 4));
	}
	
	public static int longestLine(int[][] graph, int n, int m) {
	    Node[][] dp = new Node[n][m];
	    int max = 0;
	    for(int i = 0; i < n; i++) {
	        if(graph[i][0] == 1) {
	            dp[i][0] = new Node(1, 1, 1);
	        } else {
	            dp[i][0] = new Node();
	        }
	    }
	    
	    for(int i = 0; i < m; i++) {
	        if(graph[0][i] == 1) {
	            dp[0][i] = new Node(1, 1, 1);
	        } else {
	            dp[0][i] = new Node();
	        }
	    }
	    
	    for(int i = 1; i < n; i++) {
	        for(int j = 1; j < m; j++) {
	            dp[i][j] = new Node();
	            if(graph[i][j] != 0) {
	                 dp[i][j].left = 1 + dp[i][j - 1].left;
	                 dp[i][j].top = 1 + dp[i -1][j].top;
	                 dp[i][j].topLeft = 1 + dp[i - 1][j - 1].topLeft;
	            }
	            max = Integer.max(max, dp[i][j].getMax());
	        }
	    }
	    return max;
	}
}
