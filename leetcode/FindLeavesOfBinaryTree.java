// https://leetcode.ca/all/366.html
import java.util.*;
public class FindLeavesOfBinaryTree
{
    public static class Node {
        public int num;
        public Node left;
        public Node right;
        public Node(int num) {
            this.num = num;
        }
    }
	public static void main(String[] args) {
		Node root = new Node(1);
		
		root.left = new Node(2);
		root.right = new Node(3);
		
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		
		List<List<Integer>> ans = findLeaves(root);
		
		for(List<Integer> row: ans) {
		    for(int i: row) {
		        System.out.printf("%d ", i);
		    }
		    System.out.println(" ");
		}
 	}
	
	public static List<List<Integer>> findLeaves(Node root) {
	    Map<Integer, List<Integer>> mp = new HashMap<>();
	    
	    int maxHeight = findLeavesUtil(root, mp);
	    List<List<Integer>> ans = new ArrayList<>();
	    for(int i = 1; i <= maxHeight; i++) {
	        List<Integer> l = mp.get(i);
	        ans.add(l);
	    }
	    return ans;
	}
	
	public static int findLeavesUtil(Node root, Map<Integer, List<Integer>> mp) {
	    if(root == null) return 0;
	    
	    int maxHeight = Integer.max(findLeavesUtil(root.left, mp), findLeavesUtil(root.right, mp));
	    int currheight = maxHeight + 1;
	    if(!mp.containsKey(currheight)) {
	        mp.put(currheight, new ArrayList<>());
	    }
	    List<Integer> l = mp.get(currheight);
	    l.add(root.num);
	    return currheight;
	}
}
