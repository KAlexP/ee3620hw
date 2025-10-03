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
% Get the C program results
data = load('./prog_out/prog_sol_2.txt');
x = data(:,1);
y = data(:,2);
% Start the figure
figure;
% Plot the Exact solution from Above
fplot(ySol,[0,10],'b--','DisplayName','Exact solution')
hold on;
% Plot the Numeric Approximation
plot(x,y,'r:','LineWidth',1,'DisplayName','Numeric Approximation')
hold off;
% Make plot look nice
ylabel('y(t)')
xlabel('t')
grid on;
xlim([0 10])
lgd = legend('Exact solution','Numeric Approximation','Location','best');
lgd.Box = 'on';
lgd.AutoUpdate = 'off';
lgd.ItemTokenSize = [15,7];
set(gcf, 'Renderer', 'opengl')
% Save plot
exportgraphics(gca,'./figures/fig_2_overlay.png','Resolution',300)