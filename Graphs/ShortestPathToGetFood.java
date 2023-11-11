// https://leetcode.ca/2021-03-13-1730-Shortest-Path-to-Get-Food/
import java.util.*;
public class ShortestPathToGetFood
{
    public static class Node {
        public int i;
        public int j;
        
        public Node(int i, int j) {
            this.i = i;
            this.j = j;
        }
        
        
    }
	public static void main(String[] args) {
		int[][] graph = {
		    {2, 2, 2, 2, 2, 2, 2, 2},
		    {2, -1, 0, 2, 0, 1, 0, 0},
		    {2, 0, 0, 2, 0, 0, 2, 0},
		    {2, 0, 0, 1, 0, 1, 0, 0},
		    {2, 2, 2, 2, 2, 2, 2, 2}
		};
		Node root = new Node(1, 1);
		
		System.out.println(getShortestPathForFood(graph, root));
	}
	
	public static int getShortestPathForFood(int[][] graph, Node root) {
	    int n = graph.length;
	    int m = graph[0].length;
	    
	    Queue<Node> q = new LinkedList<>();
	    q.add(root);
	    
	    int[] l = {0, 0, 1, -1};
	    int[] r = {1, -1, 0, 0};
	    int count = 0;
	    int minCount = Integer.MAX_VALUE;
	    boolean[][] vis = new boolean[n][m];
	    vis[root.i][root.j] = true;
	    while(!q.isEmpty()) {
	        int x = q.size();
	        while(x-- > 0) {
	            
    	        count++;
	            Node curr = q.poll();
    	        for(int k = 0; k < 4; k++) {
    	            int i = curr.i + l[k];
    	            int j = curr.j + r[k];
    	            
    	            if(isValid(i, j, n ,m) && graph[i][j] == 0 && !vis[i][j]) {
    	                q.add(new Node(i, j));
    	                vis[i][j] = true;
    	            } else if(isValid(i, j, n, m) && graph[i][j] == 1) {
    	                minCount = Integer.min(minCount, count);
    	            }
    	        } 
	        }
	    }
	    
	    return minCount != Integer.MAX_VALUE ? minCount : -1;
	}
	
	public static boolean isValid(int i, int j, int n, int m) {
	    return !(i < 0 || j < 0 || i >= n || j >= m);
	}
}
