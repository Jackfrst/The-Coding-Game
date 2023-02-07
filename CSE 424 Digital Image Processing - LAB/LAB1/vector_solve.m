A = [2,4;2,4];
b = [5,6];

x = solve_sys(A,b);

b1 = A * x;
disp(x);
disp(b1);

