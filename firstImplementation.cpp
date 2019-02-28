#include <algorithm>
#include <math.h>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#define ll long long
#define ull unsigned long long
#define FOR(m,s,n,u) for(int m=s; m<n; m+=u)
#define ROF(m,s,n,u) for(int m=n; m>=s; m-=u)
#define FORb(m,s,n,u,k) for(int m=s; m<n&&k; m+=u)
#define pb push_back
#define mod 1000000007
#define MOD(x) ((x%mod)+mod)%mod
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define vi vector<int>
using namespace std;
double rugosity, tubeDiameter, reynolds;
double frictionFactor(double f){ 
    return -2*log(rugosity/(3.7*tubeDiameter) + 2.51/(reynolds*sqrt(f))) - 1/f;
} 


void bisection(double a, double b, double error){ 
    if (frictionFactor(a) * frictionFactor(b) >= 0) {  //parameters missing,.... function must be expressed somehow else
        cout << "no se puede"; 
        return; 
    } 
  
    double c = a; 
    while ((b-a) >= error) { 
        c = (a+b)/2; 
        cout<<"actual value of c: "<<c<<endl;
        if (!frictionFactor(c)) break; 
        else if (frictionFactor(c)*frictionFactor(a) < 0) 
            b = c; 
        else
            a = c; 
    } 
    cout << "friction factor = " << c; 
}


int main(){
sync;
double charSpeed, tubeDiameter, kinematicSpeed; 
cout<<"enter characteristic speed "<<endl;
cin>>charSpeed;
cout<<"enter tube diameter "<<endl;
cin>>tubeDiameter;
cout<<"enter kinematic speed "<<endl;
cin>>kinematicSpeed;

reynolds = charSpeed*tubeDiameter/kinematicSpeed;

int fluxType; //0 for turbulent, 1 for laminar, 2 for transition

if(reynolds>4000){
    fluxType = 0;
}else if(reynolds<2100){
    fluxType = 1;
}else{
    fluxType = 2;
}

if(fluxType == 1){
    cout<<"friction factor = " << 64/reynolds<<endl;
}else if(fluxType == 2){
    cout<<"friction factor is can't be calculated"<<endl;
}else{
    cout<<"flux is turbulent, please inputa value for rugosity ";
    cin>>rugosity;
    cout<<"friction factor = ";
    bisection(-1000,1000,0.0);
}
 

return 0;
}