// https://leetcode.ca/all/1165.html#:~:text=There%20is%20a%20special%20keyboard,index%20of%20the%20desired%20character.
import java.util.*;
public class Main
{
	public static void main(String[] args) {
		System.out.println(getNumOfTaps("pqrstuvwxyzabcdefghijklmno", "leetcode"));
		
	}
	
	public static int getNumOfTaps(String keyboard, String word) {
	    int initialPosition = 0;
	    
	    Map<Character, Integer> map = new HashMap<>();
	    for(int i = 0; i < keyboard.length(); i++) {
	        map.put(keyboard.charAt(i), i);
	    }
	    int moves = 0;
	    int pos = 0;
	    for(int i = 0; i < word.length(); i++) {
	        char c = word.charAt(i);
	        int nextPos = map.get(c);
	        moves += Math.abs(nextPos - pos);
	        pos = nextPos;
	    }
	    
	    return moves;
	}
}
