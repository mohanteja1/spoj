// PROBLEM: Bulk
// AIM : find the volume of the bulk item fromed by unit cubes 
// CONSTRAINTS:
/* TEST CASES:  INPUT   SOLUTION
        1            -->
        2           -->

2      <-- no of test cases
12     <-- no of faces in bulk
4  10 10 10  10 10 20  10 20 20  10 20 10  <--Description of each face with 3d coordinates
4  20 10 10  20 10 20  20 20 20  20 20 10
4  10 10 10  10 10 20  20 10 20  20 10 10
4  10 20 10  10 20 20  20 20 20  20 20 10
4  10 10 10  10 20 10  20 20 10  20 10 10
5  10 10 20  10 20 20  20 20 20  20 15 20  20 10 20
4  14 14 14  14 14 16  14 16 16  14 16 14
4  16 14 14  16 14 16  16 16 16  16 16 14
4  14 14 14  14 14 16  16 14 16  16 14 14
4  14 16 14  14 16 16  16 16 16  16 16 14
4  14 14 14  14 16 14  16 16 14  16 14 14
4  14 14 16  14 16 16  16 16 16  16 14 16


 */



/* ALGORITHM1:
              1. sort all the  xy-planes according to height
              2. eject the projections of each plane on its below plane if overlaped
              3. set conditions for negative volumes 
     

         p4
      .________.
      |______  |
         p3  | |
             | |                   ^ Zaxis
         p2  | |                   |  
      .______| |                   | 
      |________|                   |  xy plane is ground 
        p1:  base plane            .-------------> 
   */

//COMPLEXITY:              MEMORY:

//BY MOHANTEJA
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
using namespace std;

#define DEBUG if(0)
#define PAUSE system("pause")
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define UB(s, e, x) upper_bound(s, e, x)
#define LB(s, e, x) lower_bound(s, e, x)
#define REV(s, e) reverse(s, e);
#define SZ(c) c.size()
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define i64 long long
#define ff first
#define ss second
#define i64 long long
#define FS "%lld"

template< class T > T sq(T &x) { return x * x; }
template< class T > T abs(T &n) { return (n < 0 ? -n : n); }
template< class T > T max(T &a, T &b) { return (!(a < b) ? a : b); }
template< class T > T min(T &a, T &b) { return (a < b ? a : b); }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > T mod(T &a, T &b) { return (a < b ? a : a % b); }
template< class T > bool inside(T &a, T &b, T &c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }


const int INF = 1000000001;
const double EPS = 1e-10;
const int MAX = 100001;

using namespace std;

class Point{
   public:
    int x,y,z;
    //constructor
   Point(int X,int Y,int Z) : x(X) , y(Y) , z(Z) {} 

   void printCoordinates(){
       printf("%d,%d,%d ",x,y,z);
   }

};

class ZPlane{
   public: 
   int height;
   vector<Point *> Vertices; 
   ZPlane(int xyPlaneDistance,vector<Point *> vertices)
     : height(xyPlaneDistance){
         updateVertices(vertices);
     }

   void updateVertices(vector<Point *>vertices){
       for(int i=0;i<vertices.size();i++)
           Vertices.push_back(vertices.at(i));
    
   }
   
   void printPlane(){
       printf("printing Plane");
       printf("z height:%d\n",height);
       for(int i = 0;i<Vertices.size();i++)
         Vertices.at(i)->printCoordinates();
       printf("\n");

   }


};


void getSurfaceArea(int *cooridinatesOfFace){
    // returns the surface are of a plane 
  
return ;
}

void overLappingArea(int *plane1coordinates,int *plane2cooridantes){

}


int main()
{

	// your code here
	int testcases;
	int noOfFaces,noOfCoordinates;
    char inputNum[10];
    vector<ZPlane *> xy_planes;
    vector<Point *> vertices; 

	cin >> testcases;
	while (testcases > 0)
	{
		cin >> noOfFaces;
        //find all the z planes if(Z==same in all points)
        bool isXYplane;
        for(int i = 0; i< noOfFaces;i++){
           isXYplane = true;
           cin >> noOfCoordinates;
           //create a list of coordinates
           int x,y,z,lastZ;
           Point *point;
           for(int j = 0; j<noOfCoordinates; j++){
               cin >>x;
               cin >>y;
               cin >>z;
               point = new Point(x,y,z);
               vertices.push_back(point);
               //point->printCoordinates();
               // printf("\n");
               if(j!=0){
                   if(lastZ!=z) {
                       isXYplane = false;
                       printf("deleting coordinates of non xyplanes");
                       for(int k= 0;k<vertices.size();k++){
                           vertices.at(i)->printCoordinates();
                       }
                       vertices.clear();
                       break;
                   }
               }
               lastZ =z ;
           }
           if(isXYplane){

               printf("found xy plane");
            //create a zplane object and append it to the list of planes
               xy_planes.push_back(new ZPlane(vertices.at(0)->z,vertices));
               xy_planes.back()->printPlane();
               vertices.clear();
           }
        }
    
    //  printf("printing z planes ") ;
    //  for(int i = 0;i<xy_planes.size();i++)
     //    xy_planes.at(i)->printPlane();
      
      xy_planes.clear();

		testcases--;
		cout << "\n";
	}
      
      


	return 0;
}