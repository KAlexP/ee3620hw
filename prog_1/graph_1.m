% Load C Program Solution
data = load('./prog_out/prog_sol_1.txt');
x = data(:,1);
y = data(:,2);
% Set up Analyzed solution 
x2 = 0:0.001:10;
y2 = 3 * exp(-2.5 * x);
% Start The figure
figure;
% Plot The Exact Solution
plot(x2, y2,'b--','LineWidth',1,'DisplayName','Exact Solution')
hold on;
% Plot the C Program Solution
plot(x,y,'r:','LineWidth',1,'DisplayName','Numeric Approximation')
hold off;
% Make graph look nice
grid on;
lgd = legend('Exact solution','Numeric Approximation','Location','best');
lgd.Box = 'on';
lgd.AutoUpdate = 'off';
lgd.ItemTokenSize = [15,7];
% Save graph
exportgraphics(gca,'fig_1_overlay.png','Resolution',300)
