// https://leetcode.ca/2022-02-19-2158-Amount-of-New-Area-Painted-Each-Day/
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		int[][] paint = {{1,4},{5,8},{4,7}};
		int[] ans = getMaxPaintings(paint);
		
		for(int i = 0; i < ans.length; i++) {
		    System.out.printf("%d ", ans[i]);
		}
	}
	
	public static int[] getMaxPaintings(int[][] paint) {
	   TreeSet<Integer> unpainted = new TreeSet<>();
        int[] ans = new int[paint.length];
        for (int i = 0; i <= 50000; i++) {
            unpainted.add(i);
        }
        for (int i = 0; i < paint.length; i++) {
            int left = paint[i][0], right = paint[i][1];
            // Repeatedly delete the first element >= left until it becomes >= right
            // This clears values in [left, right) from the TreeSet
            while (true) {
                int next = unpainted.ceiling(left);
                if (next >= right)
                    break;
                unpainted.remove(next);
                ans[i]++;
            }
        }
        return ans;
	}
}
