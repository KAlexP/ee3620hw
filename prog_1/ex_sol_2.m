
x = 0:0.01:5;
% y = solution here
figure;
plot(x,y);
xlabel('x');
ylabel('y');
title('Exact Solution of (D^3 + 0.6D^2 + 25.1125D + 2.5063)y(t)=0');
grid on;

saveas(gcf, 'ex_plot_2.png');
