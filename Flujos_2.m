%GUI INITIALIZATION
promt = {'Criterio de convergencia: ', 'q1: ','q2: ', 'q3: ','q4: ','q5: ', 'q6: ', 'q7: '};
title = 'Flujos';
dims = [1 50];
definput = {'0','0','0','0','0','0','0','0'};
opts.Interpreter = 'tex';
answer = inputdlg(promt,title,dims,definput,opts);

%INPUT VALUES
C = str2double(answer{1});
x1 = str2double(answer{2});
x2 = str2double(answer{3});
x3 = str2double(answer{4});
x4 = str2double(answer{5});
x5 = str2double(answer{6});
x6 = str2double(answer{7});
x7 = str2double(answer{8});

flag = true

%inicia ciclo while que itera hasta que el error de las ecuaciones sea menor al que se busca
iteracion = 0;
while(flag)
    iteracion = iteracion + 1;
    X=[x1;x2;x3;x4;x5;x6;x7]
    
    D = [
    1,-1,-1, 0, 0, 0, 0;
    0, 1, 0,-1,-1, 0, 0;
    0, 0,-1, 0,-1, 1, 0;
    0, 0, 0,-1, 0,-1, 1;

    0,-600*x2,2400*x3,0,-600*x5,0,0;
    0,0,0,-2400*x4,600*x5,2400*x6,0;
    200*x1,600*x2,0,2400*x4,0,0,600*x7
    
    ]

    F=[
    x1-x2-x3;
    x2-x4-x5;
    x6-x5-x3;
    x7-x4-x6;

    (1200*(x3^2)-300*(x5^2)-300*(x2^2));
    (300*(x5^2)+1200*(x6^2)-1200*(x4^2));
    (300*(x7^2)+100*(x1^2)+300*(x2^2)+1200*(x4^2))-8.03793743
    
    ]

    X = (X - (inv(D)*F))
    error1 = abs(((X(1,1)-x1)/(X(1,1)))*(100))
    error2 = abs(((X(2,1)-x2)/(X(2,1)))*(100))
    error3 = abs(((X(3,1)-x3)/(X(3,1)))*(100))
    error4 = abs(((X(4,1)-x4)/(X(4,1)))*(100))
    error5 = abs(((X(5,1)-x5)/(X(5,1)))*(100))
    error6 = abs(((X(6,1)-x6)/(X(6,1)))*(100))
    error7 = abs(((X(7,1)-x7)/(X(7,1)))*(100))
    
    if(error1 < C & error2 < C & error3<C & error4<C & error5 < C & error6<C & error7<C)
        flag = false;
    end
    
    x1 = X(1,1)
    x2 = X(2,1)
    x3 = X(3,1)
    x4 = X(4,1)
    x5 = X(5,1)
    x6 = X(6,1)
    x7 = X(7,1)

    disp ("Q1,Q2,Q3,Q4,Q5,Q6,Q7 en m^3 * s^-1 toman los siguientes valores")
    disp (X)
    disp ("iteracion # " + iteracion)
end

disp ("Q1,Q2,Q3,Q4,Q5,Q6,Q7 en m^3 * s^-1 terminan con los siguientes valores")
disp (X)
disp("El numero de iteraciones fue: " + iteracion)
disp (iteracion)