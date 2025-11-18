data = load('./total_result.txt');
x = data(:,1);
y = data(:,2);


figure;
plot(x,y,'LineWidth',1,'DisplayName','Numeric Result')
hold on;
grid on;

t_fine = 0:0.001:20;

y_analytic = (-0.07 .* exp(-2.6038 .* t_fine) + 1.94 .* exp(-1.198 .* t_fine) .* cos(2.08 .* t_fine - 2.98) + 0.0164 .* cos(7.85 .* t_fine +2.03));

y_analytic = real(y_analytic);

plot(t_fine, y_analytic, 'r:','Linewidth',2,'DisplayName', 'Analytic Result')

legend('show');
xlabel('t');
ylabel('y');
title('Total Result: Numeric v. Analytic');
