data = load('./prog_sol_2.txt');
x = data(:,1);
y = data(:,2);

x2 = 0:0.001:10;
y2 = 3 * exp(-2.5 * x);

figure;

subplot(2,1,1)
plot(x2, y2,'b-','LineWidth',1,'DisplayName','Exact Solution')
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

