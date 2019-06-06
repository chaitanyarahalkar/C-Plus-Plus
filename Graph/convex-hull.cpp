#include <iostream>
#include <vector>

using std::cout;
using std::vector;

struct Point{

	int x,y;
};

// To find orientation of ordered triplet (p, q, r). 
// The function returns following values 
// 0 --> p, q and r are colinear 
// 1 --> Clockwise 
// 2 --> Counterclockwise

int orientation(Point p,Point q,Point r){

	int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x)*(r.y - q.y);

	if(val == 0) // colinear 
		return 0;

	return (val > 0) ? 1 : 2; // clock or counterclock wise 

}
vector<Point> convex_hull(Point points[],int n){


	vector<Point> v;
	if(n < 3){

		v.push_back((Point){0,0});
		return v;
	}

	int l = 0;

	for(int i = 1; i < n; i++)
		if(points[i].x < points[l].x)
			l = i;

	int p = l,q;
  /* Start from leftmost point, keep moving counterclockwise 
    until reach the start point again. */
    
	do{

		v.push_back(points[p]);

		q = (p+1) % n;

    /* If i is more counterclockwise than current q, then 
     update q */

		for(int i = 0; i < n; i++)
			if(orientation(points[p],points[i],points[q]) == 2)
				q = i;
		
    
    /* q is the most counterclockwise with respect to p 
       Set p as q for next iteration, so that q is added to 
       result 'hull' */
		p = q;

	}while(p != l);

	return v;

}
int main(void){


	 Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},{3, 0}, {0, 0}, {3, 3}}; 

     int n = sizeof(points)/sizeof(points[0]);

     vector<Point> p = convex_hull(points,n);

     cout << "Convex hull for the set of points is\n";

     for(int i = 0; i < p.size(); i++)
     	cout << p[i].x << "," << p[i].y << "\n";

	return 0;
}
