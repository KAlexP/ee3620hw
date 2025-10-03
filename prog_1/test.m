syms y(t)
% The differential equation in Problem 2
ode = diff(y,t,3) + 6 * diff(y,t,2) + 11*diff(y,t,1) + 6 == 0;
D1 = diff(y,t,1);
D2 = diff(y,t,2);
% Set initial conditions
cond1 = y(0) == 1;
cond2 = D1(0) == 1;
cond3 = D2(0) == 1;
% Solve the differential equation
ySol(t) = dsolve(ode,cond1,cond2,cond3);

figure;
% Plot the Exact solution from Above
fplot(ySol,[0,10],'b--','DisplayName','Exact solution')

% Make plot look nice
ylabel('y(t)')
xlabel('t')
grid on;
xlim([0 10])