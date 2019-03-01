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
#define PI 3.1415926535897
#define vi vector<int>
using namespace std;


double density, viscosity, rugosity, volumetricFlux, internalTubeDiameter, reynolds, velocity;
int cuenta = 0;
ll fastPow(ll a,ll b){
    ll ret = 1;
    while(b>0){
        if(b&1) ret = (ret*a);
        a=(a*a);
        b>>=1;
    }
    return ret;
}

double frictionFactor(double f){ 
    return 2.0*log((rugosity/internalTubeDiameter)/(3.7) + 2.51/(reynolds*sqrt(f))) + 1/sqrt(f);
} 


void bisection(double a, double b, double error){ 
    if (frictionFactor(a) * frictionFactor(b) >= 0) {  //parameters missing,.... function must be expressed somehow else
        cout << "no se puede"; 
        return; 
    } 
  
    double c = a; 
    while ((b-a) >= error) { 
        c = (a+b)/2; 
        if(cuenta == 0)cout<<endl;
        cout<< cuenta++ <<" iteration of c: "<<c<<endl;
        if (frictionFactor(c) == 0.0) break; 
        else if (frictionFactor(c)*frictionFactor(a) < 0) 
            b = c; 
        else
            a = c; 
    } 
    cout << "friction factor = " << c; 
}


int main(){
sync;
//double charSpeed, internalTubeDiameter, kinematicSpeed; 
cout<<"enter density "<<endl;
cin>>density;
cout<<"enter tube diameter "<<endl;
cin>>internalTubeDiameter;
cout<<"enter dynamic viscosity "<<endl;
cin>>viscosity;
cout<<"enter rugosity "<<endl;
cin>>rugosity;
cout<<"enter volumetric flux "<<endl;
cin>>volumetricFlux;

velocity = volumetricFlux/(PI*internalTubeDiameter*internalTubeDiameter/4);

reynolds = internalTubeDiameter*velocity*density/viscosity;

int fluxType; //0 for turbulent, 1 for laminar, 2 for transition

if(reynolds>4000){
    fluxType = 0;
}else if(reynolds<2100){
    fluxType = 1;
}else{
    fluxType = 2;
}

cout<<"Reynolds number is = "<<reynolds<<endl;
//cout<<"flux type number: "<<fluxType<<endl;

if(fluxType == 1){
    cout<<"Reynolds number represents a lamitar fluid which friction factor is= " << 64/reynolds<<endl;
}else if(fluxType == 2){
    cout<<"Reynolds number of this fluid represents a transition flux which friction factor can't be calculated"<<endl;
}else if(fluxType == 0){
    cout<<"Reynolds factor represents a turbulent flux, the friction factor of this flux is ";
    bisection(0.0008,1,0.01);
    cout<<endl;
}
return 0;
}

/*
62.3
1.5
0.000839
0.0004
15


62.3
1.5
0.000839
0.0005
15
 */