//CONVEX HULL

/*

Given a set of points in the plane. the convex hull of the set is the smallest convex polygon that contains all the points of it.
Find out the convex hull for the given set of points.
Input Format
Integer N(Number Of points)
Array of X coordinates
Array of Y coordinates
Output Format
X coordinate and Y coordinate of all the points seperated by space. Order doesn't matter.
Sample Testcase
Input
7
2 1 6 5 3 7 9
2 5 1 5 7 6 4
Output
1 5
2 2
6 1
9 4
7 6
3 7

*/


#include <bits/stdc++.h> 
using namespace std; 
  
struct Point 
{ 
    int x, y; 
}; 
  
int orientation(Point p, Point q, Point r) 
{ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0; 
    return (val > 0)? 1: 2; 
} 
void convexHull(Point points[], int n) 
{ 
    if (n < 3) return;  
    vector<Point> hull; 
  
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].x < points[l].x) 
            l = i; 
  
    int p = l, q; 
    do
    {  
        hull.push_back(points[p]); 
        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           if (orientation(points[p], points[i], points[q]) == 2) 
               q = i; 
        }  
        p = q; 
  
    } while (p != l);  
  
     
    for (int i = 0; i < hull.size(); i++) 
        cout << hull[i].x <<" "<< hull[i].y <<"\n"; 
} 
  
 
int main() 
{ 
    int n;
    cin>>n;
    Point points[n];
    for(int i=0;i<n;i++)
        cin>> points[i].x;
    for(int i=0;i<n;i++)
        cin>> points[i].y;
    convexHull(points, n); 
    return 0; 
} 
