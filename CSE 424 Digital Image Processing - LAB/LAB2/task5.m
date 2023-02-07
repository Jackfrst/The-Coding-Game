f = imread('f.tif');
[M, N] = size(f);
n = zeros(256);

for x = 1 : M
    for y = 1 : N
        i = f(x, y);
        n(i+1) = n(i+1) + 1;
    end
end

figure; stem(n);
figure; imhist(f);