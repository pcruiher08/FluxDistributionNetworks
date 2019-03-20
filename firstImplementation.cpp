
//uso de librerias
#include <math.h>
#include <iostream>
#include <fstream>
//declaracion de macros
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define PI 3.1415926535897
using namespace std;
ofstream fout("file.txt");

//declaracion de las variables
double density, viscosity, rugosity, volumetricFlux, internalTubeDiameter, reynolds, velocity;
int cuenta = 0;

//funcion igualada a 0 para obtener el factor de friccion con biseccion
double frictionFactor(double f){
   return -2.0*log10((rugosity/internalTubeDiameter)/(3.7) + 2.51/(reynolds*sqrt(f))) - 1/sqrt(f);
}

double darcy(){
   return 1.325/( log( (1/4.6E5)/(3.7 * 997.9503) + 5.74/(pow(reynolds,0.9)) ) * log( (1/4.6E5)/(3.7 * 997.9503) + 5.74/(pow(reynolds,0.9)) ) );
}

//funcion de biseccion como vimos en clase, algoritmo simple y optimizado en tiempo y memoria
void bisection(double a, double b, double error){
   if (frictionFactor(a) * frictionFactor(b) >= 0) {  //parameters missing,.... function must be expressed somehow else
       cout << "non existant with this bounds";
       fout<< "non existant with this bounds";
       return;
   }
    double c = a;
   while ((b-a) >= error) {
       c = (a+b)/2;
       if(cuenta == 0)cout<<endl;
       cout<<" iteration #"<< cuenta++<<" of c: "<<c<<endl;
       fout<<" iteration #"<< cuenta<<" of c: "<<c<<endl;
       if (frictionFactor(c) == 0.0) break;
       else if (frictionFactor(c)*frictionFactor(a) < 0)
           b = c;
       else
           a = c;
   }
   cout << " friction factor = " << c;
   fout << " friction factor = " << c;
}


int main(){
sync;//se llama al macro sync para leer datos en menor tiempo que la entrada comun, se busca optimizar el tiempo de ejecución del código
cout<<"enter density kg(m^-3)"<<endl;
cin>>density;
cout<<"enter tube diameter m"<<endl;
cin>>internalTubeDiameter;
cout<<"enter dynamic viscosity poise"<<endl;
cin>>viscosity;
cout<<"enter rugosity m"<<endl;
cin>>rugosity;
cout<<"enter volumetric flux m^3s^-1"<<endl;
cin>>volumetricFlux;

//se calcula la velocidad con base en el area y el flujo
velocity = volumetricFlux/(PI*internalTubeDiameter*internalTubeDiameter/4);

//se calcula el numero de reynolds
reynolds = internalTubeDiameter*velocity*density/viscosity;

int fluxType; //0 para turbulento, 1 para laminar, 2 para transicion

//se decide que tipo de flujo es
if(reynolds>4000){
   fluxType = 0;
}else if(reynolds<2100){
   fluxType = 1;
}else{
   fluxType = 2;
}

cout<<"Reynolds number is = "<<reynolds<<endl;

fout<<"Reynolds number is = "<<reynolds<<endl;
//se decide como calcular el factor de friccion dependiendo del tipo de flujo
if(fluxType == 1){
   cout<<"Reynolds number represents a laminar fluid which friction factor is = " << 64/reynolds<<endl;
   fout<<"Reynolds number represents a laminar fluid which friction factor is = " << 64/reynolds; fout<<endl;
      cout<<"friction factor using darcy: "<<darcy()<<endl;
         fout<<"friction factor using darcy: "<<darcy()<<endl;
}else if(fluxType == 2){
   cout<<"Reynolds number of this fluid represents a transition flux which friction factor can't be calculated"<<endl;
   fout<<"Reynolds number of this fluid represents a transition flux which friction factor can't be calculated"; fout<<endl;
}else if(fluxType == 0){
   cout<<"Reynolds factor represents a turbulent flux, the friction factor of this flux is "; cout<<endl;
   cout<<"friction factor using darcy: "<<darcy()<<endl;
   fout<<"Reynolds factor represents a turbulent flux, the friction factor of this flux is "; fout<<endl;
   fout<<"friction factor using darcy: "<<darcy()<<endl;
   bisection(0.008,0.1,0.001);//se llama a la biseccion con los limites 0.008 y 1, se busca una presicion de 0.001
   cout<<endl;
   fout<<endl;
}
return 0;
}

/*
Ejemplo 1
enter density
62.3
enter tube diameter
1.5
enter dynamic viscosity
0.000839
enter rugosity
0.0005
enter volumetric flux
15

Reynolds number is = 945445
Reynolds factor represents a turbulent flux, the friction factor of this flux is
0 iteration of c: 0.504
1 iteration of c: 0.256
2 iteration of c: 0.132
3 iteration of c: 0.07
4 iteration of c: 0.039
5 iteration of c: 0.0235
6 iteration of c: 0.01575
7 iteration of c: 0.019625
8 iteration of c: 0.0176875
9 iteration of c: 0.0167188
friction factor = 0.0167188
---------------------------------
Ejemplo 2
enter density
62
enter tube diameter
0.17225
enter dynamic viscosity
0.000671
enter rugosity
0.00015
enter volumetric flux
0.16312
Reynolds number is = 111411
Reynolds factor represents a turbulent flux, the friction factor of this flux is
0 iteration of c: 0.504
1 iteration of c: 0.256
2 iteration of c: 0.132
3 iteration of c: 0.07
4 iteration of c: 0.039
5 iteration of c: 0.0235
6 iteration of c: 0.01575
7 iteration of c: 0.019625
8 iteration of c: 0.0215625
9 iteration of c: 0.0205938
friction factor = 0.0205938
*/
