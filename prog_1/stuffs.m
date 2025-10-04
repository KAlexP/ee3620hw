syms y(t)
% The differential equation in Problem 2
ode = diff(y,t,3) + 0.6 * diff(y,t,2) + 25.1125*diff(y,t,1) + 2.5063 == 0;
D1 = diff(y,t,1);
D2 = diff(y,t,2);
% Set initial conditions
cond1 = y(0) == 1.5;
cond2 = D1(0) == 2;
cond3 = D2(0) == -1;
% Solve the differential equation
ySol(t) = dsolve(ode,cond1,cond2,cond3);

S = simplify(ySol);

latex(S)