// https://leetcode.ca/all/1101.html
public class Main
{
    public static class DisjointSet {
        public int n;
        public int[] parent;
        public int[] size;
        
        public DisjointSet(int n) {
            this.n = n;
            parent = new int[n];
            size = new int[n];
            
            for(int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        public int getParent(int i) {
            if(parent[i] == i) return i;
            parent[i] = getParent(parent[i]);
            return parent[i];
        }
        
        public int unionBySizeAndReturnSize(int i, int j) {
            int pi = getParent(i);
            int pj = getParent(j);
            
            if(pi == pj) {
                return size[pi];
            }
            
            if(size[pi] > size[pj]) {
                parent[pj] = pi;
                size[pi] += size[pj];
                return size[pi];
            } else {
                parent[pi] = pj;
                size[pj] += size[pi];
                return size[pj];
            }
        }
    }
  public static int getTimeWhenAllAreFriends(int n, int[][] logs) {
	    DisjointSet dj = new DisjointSet(n);
	    for(int i = 0; i < logs.length; i++) {
	        int size = dj.unionBySizeAndReturnSize(logs[i][1], logs[i][2]);
	        if(size == n) return logs[i][0];
	    }
	    
	    return -1;
	}
    
	public static void main(String[] args) {
		
		int[][] logs = {{20190101,0,1},{20190104,3,4},{20190107,2,3},{20190211,1,5},{20190224,2,4},{20190301,0,3},{20190312,1,2},{20190322,4,5}};
		int n = 6;
		
		System.out.println(getTimeWhenAllAreFriends(n, logs));
	}

}
