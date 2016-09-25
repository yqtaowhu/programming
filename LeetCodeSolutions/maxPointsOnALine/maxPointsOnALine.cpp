// Date   : 2016.09.25
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
*               
**********************************************************************************/

class Solution{
public:
	int maxPoints(vector<Point> &points){
		if (points.size()<=2) return points.size();

		map<int,map<int,int> > map;
		int result=0;

		for (unsigned int i=0;i<points.size();i++){
			map.clear();
			int localmax=0,overlap=0;
			for (unsigned int j=i+1;j<points.size();j++){
				int x=points[j].x-points[i].x;
				int y=points[j].y-points[i].y;
				//check overlap
				if (x==0&&y==0){
					overlap++;
					continue;
				}
				int gcd=generateGCD(x,y);
				if (gcd!=0){
					x/=gcd;
					y/=gcd;
				}
				//find x,then y;
				int curr=++map[x][y];
				localmax=max(curr,localmax);
			}
			result=max(result,localmax+overlap+1);
		}
		return result;
	}
private:
	int generateGCD(int a, int b){
		if (b==0) return a;
		return generateGCD(b,a%b);
	}
};
