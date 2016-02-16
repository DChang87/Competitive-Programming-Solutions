/*find largest circle that encompasses all points*/
#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    double x[n],y[n];
    double a,b,c,d,s,ans;
    for (int i=0;i<n;i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
    ans =0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            for (int k=j+1;k<n;k++)
            {
                a = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                b = sqrt((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]));
                c = sqrt((x[k]-x[i])*(x[k]-x[i])+(y[k]-y[i])*(y[k]-y[i]));
                s = (a+b+c)/2;
                d = 0;
                if ((s==0) or (a*a+b*b-c*c<0) or (c*c+b*b-a*a<0) or (a*a+c*c-b*b<0))
                {
                    if (a>d)
                    {
                        d = a;
                    }
                    if (b>d)
                    {
                        d = b;
                    }
                    if (c>d)
                    {
                        d = c;
                    }
                }
                else
                {
                    d = 2*(a*b*c)/(4*sqrt(s*(s-a)*(s-b)*(s-c)));
                }
                if (d>ans)
                {
                    ans = d;
                }
            }
        }
    }
    cout<<setprecision(2)<<fixed<<ans;
}
