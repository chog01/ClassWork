clear;
syms t s
y = 2 + 3*exp(-0.2*t) + 4*exp(-0.3*t)*cos(2*pi*0.5*t);
Y = laplace(y);
g = ilaplace(Y);

% Plotting both on the same graph
figure;
fplot(y, [-5, 5]); 
hold on;
% Using a red dashed line with thicker linewidth to differentiate g(t)
h = fplot(g, [-5, 5]);
set(h, 'Color', 'r', 'LineStyle', '--', 'LineWidth', 2);
legend('y(t)', 'g(t) = ilaplace(Y(s))');
title('Comparison of y(t) and g(t)');
grid on;