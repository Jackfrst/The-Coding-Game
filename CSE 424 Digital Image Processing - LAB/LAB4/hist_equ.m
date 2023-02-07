f = imread('h1.tif');
[M, N] = size(f);
n = zeros([1, 256]);

for x = 1 : M
    for y = 1 : N
        i = f(x, y);
        n(i+1) = n(i+1) + 1;
    end
end

c = 255 / (M * N);
s = zeros([1, 256]);

for k = 0 : 255
    t = 0;
    for j = 0 : k
        t = t + n(j+1);
    end
    s(k+1) = round(t * c);
end


f_equ = zeros([M, N]);
for x = 1 : M
    for y = 1 : N
        i = f(x, y);
        f_equ(x, y) = s(i+1);
    end
end
figure; imshow(f);
figure; imshow(f_equ, []);

n_equ = zeros([1, 256]);
for x = 1 : M
    for y = 1 : N
        i = f_equ(x, y);
        n_equ(i+1) = n_equ(i+1) + 1;
    end
end
figure; stem(n);
figure; stem(n_equ);


