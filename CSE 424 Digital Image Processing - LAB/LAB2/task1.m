f = rgb2gray(imread('demo.jpg'));
[M, N] = size(f);
c_M = M / 2;
c_N = N / 2;
D = @(x, y) max(abs(x-c_M), abs(y-c_N));

for x = 1 : M
    for y = 1 : N
        if D(x, y) <= 50
            f(x, y) = 0;
        end
    end
end
imshow(f, []);