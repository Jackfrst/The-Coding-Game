f = imread('a.tif');
[M, N] = size(f);
g = zeros([M, N]);

for x = 1 : M
    for y = 1 : N
        g(x, y) = f(x, y) & '01';
    end
end
figure; imshow(f);
figure; imshow(g);