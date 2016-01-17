#include<bits/stdc++.h>
using namespace std;
int N;
double calcdist(double x1,double y1, double x2,double y2)
{
    return pow(pow(x2-x1,2)+pow(y2-y1,2),0.5);
}
double calcang(double dist1,double dist2, double dist3){
    return acos((dist1*dist1 + dist2*dist2 - dist3*dist3)/(2*dist2*dist1)) * 180.0/3.14159265;
}
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>N;
    double x1,y1,x2,y2,x3,y3;
    for (int i=0;i<N;i++){
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        double dist1 = calcdist(x1,y1,x2,y2);
        double dist2 = calcdist(x2,y2,x3,y3);
        double dist3 = calcdist(x3,y3,x1,y1);
        double ang1 = calcang(dist1,dist2,dist3);
        double ang2 = calcang(dist3,dist1,dist2);
        double ang3 = calcang(dist3,dist2,dist1);
        cout<<"Case #"<<i+1<<": ";
        if (dist1 >= dist2+dist3 || dist2 >=dist1+dist3 || dist3 >= dist1+dist2){
            cout<<"not a triangle"<<endl;
            continue;
        }
        if (dist1==dist2==dist3){
            cout<<"equilateral ";
        }
        else if (dist1==dist2 || dist2==dist3 || dist1==dist3){
            cout<<"isoceles ";
        }
        else{
            cout<<"scalene ";
        }
        if (int(ang1)==90.0 || int(ang2)==90.0 || int(ang3)==90.0){
            cout<<"right";
        }
        else if (ang1>90 || ang2>90 || ang3>90){
            cout<<"obtuse";
        }
        else{
            cout<<"acute";
        }
        cout<<" triangle"<<endl;
    }
    return 0;
}


