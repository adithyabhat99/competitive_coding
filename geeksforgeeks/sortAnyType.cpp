/*
You need to sort elements of an array where the array can be of following data-types:

Integer
String
floating number
This is a functional problem so partial code is locked already do invest time in understanding that and complete the program by implementing the following functions:

sortArray() 
printArray()
 

Input:

The first line of the input consists of the number of test cases.

each test case consists of 2 lines:

Having 2 space separated integer n and q, where n is the number of elements and q represents query number
               if q = 1, means elements of the array are of integer type

                  q = 2, means elements of the array are of string type

                  q = 3, means elements of array are of floating digit type  

Second line contains the elements  the array
Output:

For each test, case output should be the sorted elements of the array(space separated) 

Constraints:

1 <= test case <= 50

1 <= n <= 100

q = {1, 2, 3}


Example:


Input:

3
3 3
34.23 -4.35 3.4

4 1
123 -2311 837 0 

5 2
focus on challenges in implementing

Output:

-4.35 3.4 34.23 
-2311 0 123 837 
challenges focus implementing in on 
 */

template <class T>
void sortArray(T a[], int n)
{ 
	//Add your code here.
	int i,j;
	T c;
	for(i=1;i<n;i++){
	    c=a[i];
	    for(j=i-1;j>=0 && a[j]>c;j--)
	        a[j+1]=a[j];
	    a[j+1]=c;
	}
}
template <class T>
void printArray(T a[], int n)
{
	//Add your code here.
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}