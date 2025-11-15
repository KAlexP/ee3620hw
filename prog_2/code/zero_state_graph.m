data = load('./zero_state.txt');
x = [0:0.001:10];
y = data(:,1);

plot(x,y,'r','LineWidth',1,'DisplayName','Numeric Zero State')

grid on;
