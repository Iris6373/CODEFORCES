# Problem

## [B. Big Vova](https://codeforces.com/contest/1407/problem/B)


# Solution 

## 1) Starting with largest number - BETTER

       
      
      
   ### Code : (.cpp)
    
          #include <bits/stdc++.h>
          using namespace std;

          int gcd (int a, int b)
          {
              if (a == 0) return b;
              else return gcd(b%a,a);
          }

          int main()
          {
              ios::sync_with_stdio(0);
              cin.tie(0);
            int t,i,a[1000],n=0,s=0,sum=0;
            cin >> t;
            while (t--)
            {
                int n,b=0,i,j,k,c=0,d=0,e=0;
                vector <int> v,a;
                cin >> n;
                for (i=0;i<n;i++)
                {
                    int w;
                    cin >> w;
                    v.push_back(w);
                }
                /*v.push_back(0);
                v.push_back(0);
                n += 2;*/
                sort(v.begin(),v.end(), greater<int>());
                b = 1;
                //for (i=0;i<n;i++) cout << v[i] << " "; cout << "\n";
                for (i=1;i<n;i++)
                {
                    c = 0;
                    b = v[0];
                    //cout << "i = " << i << ":\n";
                    for (j=0;j<i;j++)
                    {
                        b = gcd(b,v[j]);
                    }
                    //cout << "b = " << b << "  ";
                    c = b;
                    c = gcd(c,v[i]);
                    e = i;
                    //cout << "c = " << c << "  " << "e = " << e << "\n";
                    for (j=i+1;j<n;j++)
                    {
                        d = gcd(b,v[j]);
                        if (d > c)
                        {
                            c = d;
                            e = j;
                        }
                        //cout << "d = " << d << "  " << "c = " << c << "  " << "e = " << e << "\n";
                    }
                    int te = v[e];
                    v[e] = v[i];
                    v[i] = te;
                    //for (j=0;j<n;j++) cout << v[j] << " "; cout << "\n\n";
                }
                for (i=0;i<n;i++) cout << v[i] << " ";
                cout << "\n";

            }
            return 0;
          }


 
      Time Complexity  : O(t*N^2*log(N)) 
                         Since we traverse all elements N times and calculating gcd takes log(N) time. 
      Space Complexity : O(1)
                         Since no extra space is used.
