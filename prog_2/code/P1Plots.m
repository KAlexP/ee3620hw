f1 = [0,1,2,3,2,1];
f2 = [-2,-2,-2,-2,-2,-2,-2];
f3 = [1,-1,1,-1];
f4 = [0,0,0,-3,-3];

% Compute convolutions
c1 = conv(f1, f1);
c2 = conv(f1, f2);
c3 = conv(f1, f3);
c4 = conv(f2, f3);
c5 = conv(f1, f4);

figure;

subplot(5,1,1);
stem(0:length(c1)-1, c1, 'filled');
title('f1 * f1');

subplot(5,1,2);
stem(0:length(c2)-1, c2, 'filled');
title('f1 * f2');

subplot(5,1,3);
stem(0:length(c3)-1, c3, 'filled');
title('f1 * f3');

subplot(5,1,4);
stem(0:length(c4)-1, c4, 'filled');
title('f2 * f3');

subplot(5,1,5);
stem(0:length(c5)-1, c5, 'filled');
title('f1 * f4');
