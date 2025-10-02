syms y(t)
ode = diff(y,t,3) + 0.6 * diff(y,t,2) + 25.1125*diff(y,t,1) + 2.5063 == 0;

D1 = diff(y,t,1);
D2 = diff(y,t,2);

cond1 = y(0) == 1.5;
cond2 = D1(0) == 2;
cond3 = D2(0) == -1;

ySol(t) = dsolve(ode,cond1,cond2,cond3);



data = load('./prog_sol_2.txt');
x = data(:,1);
y = data(:,2);

figure;

subplot(2,1,1)
fplot(ySol,[0,10])
title('Exact Solution')
ylabel('y(t)')
xlabel('t')
grid on;
xlim([0 10])

subplot(2,1,2)
plot(x,y,'r-','LineWidth',1,'DisplayName','Numeric Approximation')
title('Numeric Approximation')
ylabel('y(t)')
xlabel('t')
grid on;
xlim([0 10])

saveas(gcf,'./fig_2.png');

figure;
fplot(ySol,[0,10],'b--','DisplayName','Exact solution')
hold on;
plot(x,y,'r:','LineWidth',1,'DisplayName','Numeric Approximation')
hold off;
ylabel('y(t)')
xlabel('t')
grid on;
xlim([0 10])

legend show;

saveas(gcf,'./fig_2_overlay.png')