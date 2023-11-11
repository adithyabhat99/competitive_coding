// https://leetcode.ca/2017-09-02-642-Design-Search-Autocomplete-System/
import java.util.*;
public class AutocompleteSystem
{
    public static class Pair {
        public String s;
        public int count;
        public Pair(String s, int count) {
            this.s = s;
            this.count = count;
        }
    }

    public static class Node {
        public Map<String, Integer> countMap;
        public Map<Character, Node> nextMap;
        
        public Node() {
            countMap = new HashMap<>();
            nextMap = new HashMap<>();
        }
    }
    public String temp;   
    public Node head;
    public Node curr;
    public AutocompleteSystem(String[] sentences, int[] times) {
        temp = "";
        head = new Node();
        for(int i = 0; i < sentences.length; i++) {
            insertWord(sentences[i], times[i]);
        }
    }
    
    public List<String> input(char c) {
        List<String> ans = new ArrayList<>();
        if(c == '#') {
            insertWord(temp, 1);
            temp = "";
            curr = null;
        } else {
            if(curr == null) curr = head;
            temp += c;
            curr.nextMap.putIfAbsent(c, new Node());
            curr = curr.nextMap.get(c);
            ans.addAll(topKWords(curr, 3));
        }
        return ans;
    }
    
    private List<String> topKWords(Node node, int k) {
        List<String> result = new ArrayList<>();
        if (node.countMap.isEmpty()) {
            return result;
        }
        PriorityQueue<Pair> queue = new PriorityQueue<>((a, b) -> a.count == b.count ? b.s.compareTo(a.s) : a.count - b.count);
        for (Map.Entry<String, Integer> entry : node.countMap.entrySet()) {
            if (queue.size() < 3 || entry.getValue() >= queue.peek().count) {
                queue.offer(new Pair(entry.getKey(), entry.getValue()));
            }
            if (queue.size() > 3) queue.poll();
        }

        while (!queue.isEmpty()) {
            result.add(0, queue.poll().s);
        }

        return result;
    }
    
    private void insertWord(String word, int rep) {
        Node curr = head;
        for(char c: word.toCharArray()) {
            curr.nextMap.putIfAbsent(c, new Node());
            curr.countMap.put(word, curr.countMap.getOrDefault(word, 0) + rep);
            curr = curr.nextMap.get(c);
        }
    }
    
	public static void main(String[] args) {
		System.out.println("Hello World");
	}
}
