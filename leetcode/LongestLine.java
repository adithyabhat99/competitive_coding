// https://leetcode.ca/all/562.html
import java.util.*;
public class Main
{
    public static class Node {
        public int left;
        public int top;
        public int topLeft;
        public int topRight;
        
        public Node() {
            left = 0;
            top = 0;
            topLeft  = 0;
            topRight = 0;
        }
        public Node(int l, int t, int tl, int tr) {
            this.left = l;
            this.top = t;
            this.topLeft = tl;
            this.topRight = tr;
        }
        public int getMax() {
            return Integer.max(topRight, Integer.max(left, Integer.max(top, topLeft)));
        }
    }
    
	public static void main(String[] args) {
	    int[][] input = {{0,1,1,1},
                         {0,1,1,0},
                         {0,1,0,1},
	                     {1,0,0,0}};
		System.out.println(longestLine(input, 4, 4));
	}
	
	public static int longestLine(int[][] graph, int n, int m) {
	    Node[][] dp = new Node[n][m];
	    int max = 0;
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            if(graph[i][j] != 0) {
	                 dp[i][j] = new Node(1, 1, 1, 1);
	                 if(j - 1 >= 0) {
	                     dp[i][j].left += dp[i][j - 1].left;
	                 }
	                 if(i - 1 >= 0) {
	                     dp[i][j].top += dp[i -1][j].top;
	                 }
	                 if(i - 1 >= 0 && j - 1 >= 0) {
	                     dp[i][j].topLeft += dp[i - 1][j - 1].topLeft;
	                 }
	                 if(i - 1 >= 0 && j + 1 < m) {
	                     dp[i][j].topRight += dp[i - 1][j + 1].topRight;
	                 }
	            } else {
	                dp[i][j] = new Node();
	            }
	            max = Integer.max(max, dp[i][j].getMax());
	        }
	    }
	    return max;
	}
}
