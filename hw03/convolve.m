syms t tau
f = exp(-2*t)*heaviside(t);
g = exp(-3*t)*heaviside(t);
y = simplify(int(subs(f,t,tau)*subs(g,t,t-tau), tau, -inf, inf))
fplot(y, [ -0.5 5 ])
xlabel('t'); ylabel('y(t)')

latex(y)

f = heaviside(t);
g = heaviside(t);
f(t) = 