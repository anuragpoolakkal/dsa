# Linear Search

Searching algorithm

### Time Complexity
Best Case: O(1)  
Worst Case: O(n)


```java
public class linearSearch
{

  public static void main (String args[])
  {
    int[] numbers = { 34, 322, 23, 34, 45, 67, 879, 89, 7, 88 };
    int target = 89;
    int ans = linearSearch(numbers, target);
    System.out.println(ans);
  }

  static int linearSearch(int[] arr, int target)
  {
    if (arr.length == 0)
      return -1;

    for (int i = 0; i < arr.length; i++)
      {
	if (arr[i] == target)
	  {
	    return i;
	  }
      }
      return -1;
  }

}
```