# Problem Statement

## [A. Yet Another Two Integers Problem](https://codeforces.com/contest/1409/problem/A)


## My solution :  (Accepted)

    
  
        
   ### Code : (.cpp)  
      
          #include <bits/stdc++.h>
          using namespace std;

          int main()
          {
              ios::sync_with_stdio(0);
              cin.tie(0);
              long long int t;
              cin >> t;
              while (t--)
              {
                  double i,n,a=0,b=0;
                  cin >> a >> b;
                  cout << (int) ceil(abs(a-b)/10) << "\n";

              }
              return 0;
          }



    Time Complexity  : O(t)
                       t test cases
                       Since each takes constant time.

    Space Complexity : O(1)
                       Since no extra space is used.
                       
   
  
  
