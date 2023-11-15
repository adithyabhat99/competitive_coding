// https://leetcode.ca/all/1197.html
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
    public static final int[][] moves = {
        {-2,1},
        {-2,-1},
        {-1,2},
        {-1,-2},
        {1,2},
        {1,-2},
        {2,1},
        {2,-1}
    };
	public static void main(String[] args) {
		System.out.println(maxMoves(5, 5));
	}
	
	public static int maxMoves(int x, int y) {
	    Set<String> vis = new HashSet<>();
	    Queue<Node> q = new LinkedList<>();
	    vis.add(0 + "+" + 0);
	    q.add(new Node(0, 0));
	    
	    int level = 0;
	    while(!q.isEmpty()) {
	        int n = q.size();
	        while(n-- > 0) {
	            Node curr = q.poll();
	            if(curr.i == x && curr.j == y) {
	                return level;
	            }
	            for(int i = 0; i < moves.length; i++) {
	                int adjI = curr.i + moves[i][0];
	                int adjJ = curr.j + moves[i][1];
	                
	                if(!vis.contains(adjI + "+" + adjJ)) {
	                    vis.add(adjI + "+" + adjJ);
	                    q.add(new Node(adjI, adjJ));
	                }
	            }
	        }
	        level++;
	    }
	    return level;
	}
}
