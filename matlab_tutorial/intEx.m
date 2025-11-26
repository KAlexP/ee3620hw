f = @(t) t .* sin(2*pi*t);
out = quad(f,0,1);
disp(out)