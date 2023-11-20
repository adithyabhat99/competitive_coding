// https://leetcode.ca/2022-03-17-2184-Number-of-Ways-to-Build-Sturdy-Brick-Wall/
import java.util.*;
public class Main
{
    List<List<Integer>> possible;
    List<Integer> temp;
    final int MOD = (int) 1e9 + 7;
    int width;
    int height;
    int[] bricks;
    
	public static void main(String[] args) {
		Main m = new Main();
		int height = 2;
		int width = 3;
		int[] bricks = {1,2};
		System.out.println(m.numberOfWays(height, width, bricks));
	}
	
	public int numberOfWays(int height, int width, int[] bricks) {
	    this.height = height;
	    this.width = width;
	    this.bricks = bricks;
	    this.temp = new ArrayList<>();
	    this.possible = new ArrayList<>();
	    
	    dfs(0);
	    int n = possible.size(); 
	    List<Integer>[] g = new List[n];
	    
	    Arrays.setAll(g, k -> new ArrayList<>());
	    
	    for(int i = 0; i < n; i++) {
	        for(int j = i + 1; j < n; j++) {
	            if(check(possible.get(i), possible.get(j))) {
	                g[i].add(j);
	                g[j].add(i);
	            }
	        }
	    }
	    
	    int[][] dp = new int[height][n];
	    for(int i = 0; i < width; i++) {
	        dp[0][i] = 1;
	    }
	    for(int i = 1; i < height; i++) {
	        for(int j = 0; j < n; j++) {
	            for(int k: g[j]) {
	                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
	            }
	        }
	    }
	    
	    int ans = 0;
	    
	    for(int i = 0; i < n; i++) {
	        ans = (ans + dp[height - 1][i]) % MOD;
	    }
	    return ans;
	}
	
	public boolean check(List<Integer> a, List<Integer> b) {
	    int s1 = a.get(0);
        int s2 = b.get(0);
        int i = 1, j = 1;
        while (i < a.size() && j < b.size()) {
            if (s1 == s2) {
                return false;
            }
            if (s1 < s2) {
                s1 += a.get(i++);
            } else {
                s2 += b.get(j++);
            }
        }
        return true;
	}
	
	public void dfs(int i) {
	    if(i > width) return;
	    if(i == width) {
	        possible.add(new ArrayList<>(temp));
	        return;
	    }
	    for(int j = 0; j < bricks.length; j++) {
	        temp.add(bricks[j]);
	        dfs(i + bricks[j]);
	        temp.remove(temp.size() - 1);
	    }
	}
}
