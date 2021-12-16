# Problem Statement

## [B. GCD Problem](https://codeforces.com/contest/1617/problem/B)


## My solution :  (Accepted)

    According to Goldbach's Conjecture, a no > 2 can be expressed as a sum of 2 prime numbers.
    Thus, we assign c = 1 and split n-1 into 2 prime nos.
    For that, we run a loop from 2 to sqrt(n-1) and find a pair (i,n-i) whose gcd is 1.
    Then we print a b c.
  
        
   ### Code : (.cpp)  
      
         



    Time Complexity  : O(t*sqrt(n)*log(n/2))
                       t test cases
                       Since for each test case at worst, we may have to iterate through sqrt(n) pairs.

    Space Complexity : O(1)  
                       Since no extra space is used.
   
  
  
