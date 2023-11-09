// LC HARD: https://leetcode.ca/all/317.html

import java.util.*;

public class Main
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
	    int n = 3;
	    int m = 5;
	    int[][] graph = {{1,0,2,0,1},{0,0,0,0,0},{0,0,1,0,0}};
	    System.out.println(getMinDistance(graph));
	}   
	
	public static int getMinDistance(int[][] graph) {
	    
	    int n = graph.length;
	    int m = graph[0].length;
	    int[] r = {0, 0, -1, 1};
	    int[] l = {-1, 1, 0 , 0};
	    
	    int[][] distance = new int[n][m];
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	            if(graph[i][j] == 0) {
	                boolean[][] vis = new boolean[n][m];
	                Queue<Node> q = new LinkedList<>();
	                q.add(new Node(i, j));
	                vis[i][j] = true;
	                int level = 0;
	                while(!q.isEmpty()) {
	                    int s = q.size();
	                    level++;
	                    for(int x = 0; x < s; x++) {
	                        Node curr = q.poll();
	                        for(int k = 0; k < 4; k++) {
	                            int adjI = curr.i + l[k];
	                            int adjJ = curr.j + r[k];
	                            if(isValid(adjI, adjJ, n, m) && !vis[adjI][adjJ]) {
	                                vis[adjI][adjJ] = true;
	                                if(graph[adjI][adjJ] == 0) {
	                                    q.add(new Node(adjI, adjJ));
	                                 } else if(graph[adjI][adjJ] == 1) {
	                                    distance[i][j] += level;
	                                }
	                            }
	                        }
	                    }
	                }
	            }
	        }
	    }
	    
	    int min = Integer.MAX_VALUE;
	    for(int i = 0; i < n; i++) {
	        for(int j = 0; j < m; j++) {
	           if(distance[i][j] != 0) {
	               min = Integer.min(min, distance[i][j]); 
	           }
	        }
	    }
	    
	    return min;
	}
	
	public static boolean isValid(int i, int j, int n , int m) {
	    return !(i < 0 || j < 0 || i >= n || j >= m);
	}
}
