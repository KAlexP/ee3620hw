
x = 0:0.01:10;
y = 3 * exp(-2.5 * x);
figure;
plot(x, y)
xlabel('t');
ylabel('y(t)');
title('Exact solution of (D+2.5)y(t) = 0');
grid on;

saveas(gcf, 'exact_1.png');
