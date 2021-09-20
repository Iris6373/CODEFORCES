# Problem Statement

## []()


## My solution :  (Accepted)

    Since the operation, "decrease the number on the clock by 1" affects only the one's digit, we can do the following :
        Swap the current digit with one's digit and perform the decrease operation.
    
    Thus, the answer becomes (no of digits besides one's digit with value > 0) + (sum of values at each digit).
  
        
   ### Code : (.cpp)  
      
        



    Time Complexity  : O(t*n)
                       t test cases
                       n for scanning and traversing each string

    Space Complexity : O(1)  
                       Since no extra space other than input array is used.
   
  
  
