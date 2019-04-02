%INICIA INTERFACE GRAFICA
promt = {'Criterio de convergencia: ', 'x1: ','x2: ', 'x3: ','x4: ','x5: ', 'x6: ', 'x7: '};
title = 'Flujos';
dims = [1 50];
definput = {'0','0','0','0','0','0','0','0'};
opts.Interpreter = 'tex';
answer = inputdlg(promt,title,dims,definput,opts);

%valores de entrada en GUI
C = str2double(answer{1});
x1 = str2double(answer{2});
x2 = str2double(answer{3});
x3 = str2double(answer{4});
x4 = str2double(answer{5});
x5 = str2double(answer{6});
x6 = str2double(answer{7});
x7 = str2double(answer{8});

flag = true;

%inicia ciclo while que itera hasta que el error de las ecuaciones sea menor al que se busca
iteracion = 0;
while(flag)
    iteracion = iteracion + 1;
    X=[x1;x2;x3;x4;x5;x6;x7];
    
    %declaracion de matrices
    D = [
    1,-1,-1, 0, 0, 0, 0;
    0, 1, 0,-1,-1, 0, 0;
    0, 0,-1, 0,-1, 1, 0;
    0, 0, 0,-1, 0,-1, 1;

    0,-600*x2,2400*x3,0,-600*x5,0,0;
    0,0,0,-2400*x4,600*x5,2400*x6,0;
    200*x1,600*x2,0,2400*x4,0,0,600*x7;
    
    ];

    F=[
    x1-x2-x3;
    x2-x4-x5;
    x6-x5-x3;
    x7-x4-x6;

    (1200*(x3^2)-300*(x5^2)-300*(x2^2));
    (300*(x5^2)+1200*(x6^2)-1200*(x4^2));
    (300*(x7^2)+100*(x1^2)+300*(x2^2)+1200*(x4^2))-8.03793743;
    
    ];

    X = (X - (inv(D)*F)); %calculo del metodo

    error1 = 100 * abs( 1 - x1 / X(1,1) );
    error2 = 100 * abs( 1 - x2 / X(2,1) );
    error3 = 100 * abs( 1 - x3 / X(3,1) );
    error4 = 100 * abs( 1 - x4 / X(4,1) );
    error5 = 100 * abs( 1 - x5 / X(5,1) );
    error6 = 100 * abs( 1 - x6 / X(6,1) );
    error7 = 100 * abs( 1 - x7 / X(7,1) );

    
    %no se detendra sino hasta que todos los errores sean menores que el
    %criterio de convergencia, asegurando asi que la cantidad de
    %iteraciones sera la indicada.
    if(error1 < C & error2 < C & error3<C & error4<C & error5 < C & error6<C & error7<C)
        flag = false;
    end

    %para evitar iteraciones extras al momento de imporimir, se evita usar
    %un for loop a continuacion, sacrificando memoria por tiempo de
    %ejecucion
    x1 = X(1,1);
    x2 = X(2,1);
    x3 = X(3,1);
    x4 = X(4,1);
    x5 = X(5,1);
    x6 = X(6,1);
    x7 = X(7,1);

    disp ("x1,x2,x3,x4,x5,x6,x7 en m^3 * s^-1 toman los siguientes valores");
    disp (X);
    disp ("iteracion # " + iteracion);
end

disp ("x1,x2,x3,x4,x5,x6,x7 en m^3 * s^-1 terminan con los siguientes valores");
disp (X);
disp("El numero de iteraciones fue: " + iteracion);
disp (iteracion);
