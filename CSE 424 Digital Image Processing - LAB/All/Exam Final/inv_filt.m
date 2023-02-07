clc;
f = im2double(imread('h.tif'));
figure; imshow(f, []);
title('original image');

[M, N] = size(f);
f = f + rand([M, N]);
h = ones([25, 25]) / 625;
H = fftshift(fft2(h, M, N));
F = fftshift(fft2(f));

G = F .* H;

F_hat = G ./ H;

figure; imshow(real(ifft2(fftshift(G))), []);
title('noisy and blurred image');

f_hat = real(ifft2(fftshift(F_hat)));
figure; imshow(f_hat, []);
title('restored image');