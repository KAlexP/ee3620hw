data = load('./prog_sol_1.txt');
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

saveas(gcf,'./fig_1.png');

figure;

plot(x2, y2,'b--','LineWidth',1,'DisplayName','Exact Solution')
hold on;
plot(x,y,'r:','LineWidth',1,'DisplayName','Numeric Approximation')
hold off;
grid on;

lgd = legend('Exact solution','Numeric Approximation','Location','best');
lgd.Box = 'on';
lgd.AutoUpdate = 'off';

lgd.ItemTokenSize = [15,7];

%lgd.Position = [0.6 0.8 0.2 0.1];

exportgraphics(gca,'fig_1_overlay.png','Resolution',300)
%saveas(gcf,'fig_1_overlay.png');