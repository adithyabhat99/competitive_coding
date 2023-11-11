// https://leetcode.ca/all/439.html

import java.util.*;
public class Main
{
	public static void main(String[] args) {
		String expression = "F?2:3";
		
		Stack<Character> stack1 = new Stack<>();
		Stack<Character> stack2 = new Stack<>();
		
		for (int i = 0; i < expression.length(); i++)
            stack1.push(expression.charAt(i));
            
        while(stack1.size() > 1) {
            char c1 = stack1.pop();
            char c2 = stack1.pop();
            
            if(c2 == ':') {
                stack2.push(c1);
            } else {
                char conditionChar = stack1.pop();
                boolean condition = conditionChar == 'T';
                char next = condition ? c1 : stack2.peek();
                stack2.pop();
                stack1.push(next);
            }
        }
        System.out.println(stack1.pop());
	}
	
}
