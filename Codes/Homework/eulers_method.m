h = 0.25;
x = 1 : h : 2;
y = zeros(size(x));
y(1) = 2;
n = numel(y);

for i = 1:n-1
    f = 3 * x(i) ^ 2 + 1;
    y(i + 1) = y(i) + h * f;
    fprintf('Iteration %d: x = %0.4f, y = %0.4f\n',i, x(i), y(i));
end

fprintf('Iteration %d: x = %0.4f, y = %0.4f\n',i + 1, x(i + 1), y(i + 1));