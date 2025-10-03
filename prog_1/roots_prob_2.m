% Declare roots
z = [-0.100002,-0.249999 + 5j, -0.249999 - 5j];
% Plot the Roots
p = plot(real(z),imag(z),"o");
% Make Graph Look Nice
p.Parent.XAxisLocation = 'origin';
p.Parent.YAxisLocation = 'origin';
grid on;
xlim([-0.3 0.3])
ylim([-5.5 5.5])
xlabel("\tau")
ylabel("j")
title('Roots to differential equation in Problem 2')
% Save Graph
saveas(gca,'./figures/roots.png')