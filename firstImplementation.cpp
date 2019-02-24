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

double frictionFactor(double k, double D, double reynolds, double f){ 
    return -2*log((k/D)/3.71+2.51/(reynolds*sqrt(f)))-1/sqrt(f); 
} 


void bisection(double a, double b, double error){ 
    if (frictionFactor(a) * frictionFactor(b) >= 0) {  //parameters missing,.... function must be expressed somehow else
        cout << "no se puede"; 
        return; 
    } 
  
    double c = a; 
    while ((b-a) >= error) { 
        c = (a+b)/2; 
        if (!frictionFactor(c)) break; 
        else if (frictionFactor(c)*frictionFactor(a) < 0) 
            b = c; 
        else
            a = c; 
    } 
    cout << "K = " << c; 
}


int main(){
sync;
double charSpeed, tubeDiameter, kinematicSpeed; 
cin>>charSpeed>>tubeDiameter>>kinematicSpeed;

double reynolds = charSpeed*tubeDiameter/kinematicSpeed;

int fluxType; //0 for turbulent, 1 for laminar, 2 for transition

if(reynolds>4000){
    fluxType = 0;
}else if(reynolds<2100){
    fluxType = 1;
}else{
    fluxType = 2;
}
 

return 0;
}