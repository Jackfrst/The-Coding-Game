f = im2double(imread('k.tif'));
figure; imshow(f, []);
title('original image');
[M, N] = size(f);
f = f + rand([M, N]);
h = ones([25, 25]) / 625;
H = fftshift(fft2(h, M, N));
F = fftshift(fft2(f));
G = F .* H;

p = [0 -1 0; -1 4 -1; 0 -1 0];
P = fftshift(fft2(p, M, N));
P_abs_sq = abs(P) .^ 2;
H_conj = conj(H);
H_abs_sq = abs(H) .^ 2;
g = 0.005;
F_hat = (H_conj ./ (H_abs_sq + g * P_abs_sq)) .* G;

figure; imshow(real(ifft2(fftshift(G))), []);
title('noisy and blurred image');
f_hat = real(ifft2(fftshift(F_hat)));
figure; imshow(f_hat, []);
title('restored image');