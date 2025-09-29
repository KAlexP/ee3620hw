
x = 0:0.01:5;
y = 3 * exp(-2.5 * x);
figure;
plot(x, y)
xlabel('t');
ylabel('y');
title('Exact solution of (D+2.5)y(t) = 0');
grid on;

saveas(gcf, 'exact_1.png');
