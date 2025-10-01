data = load('./prog_sol_1.txt');
x = data(:,1);
y = data(:,2);

plot(x,y,'-','Color','red')
xlabel('t')
ylabel('y(t)')
title('Problem 1 C Program Output')
grid on;
xlim([0 10])

saveas(gcf,'./c_solve_1.png');
