clc;
f = imread('h.tif');
[M, N] = size(f);

%this part is for padding
P = 2 * M;
Q = 2 * N;
f_p = zeros([P, Q]);
for x = 1 : M
    for y = 1 : N
        f_p(x, y) = f(x, y);
    end
end

%this part is for centering the FS
for x = 1 : P
    for y = 1 : Q
        f_p(x, y) = (-1)^(x+y) * f_p(x, y);
    end
end

%this part is for Fourier transform of the image
F = fft2(f_p);

%this part is for generating the filter transfer function
Hblp = zeros([P, Q]); %butterworth
Hglp = zeros([P, Q]); %Gaussian

D = @(u, v) sqrt((u-M)^2+(v-N)^2);
D0 = 15;
n = 2;

for u = 1 : P
    for v = 1 : Q
            Hblp(u, v) = 1 / (1 + (power((D(u, v) / D0), (2 * n))));
            %Hbhp(u, v) = 1 / (1 + (power(( D0 / D(u, v) ), (2 * n))));
            Hglp(u, v) = exp(-power(D(u, v), 2) / (2 * power(D0, 2)));
    end;
end;

H = zeros([P, Q]);

%LPF
% D = @(u, v) sqrt((u-M)^2+(v-N)^2);
% D0 = 50;

% for u = 1 : P
%     for v = 1 : Q
%         if D(u, v) <= D0
%             H(u, v) = 1;
%         end
%     end;
% end;


Hghp = 1 - Hglp;
G1 = F .* Hblp;
G2 = F .* Hghp;

%this part is for Inverse Fourier transform of the image
g_p = real(ifft2(G1 .* G2));

for x = 1 : P
    for y = 1 : Q
        g_p(x, y) = (-1)^(x+y) * g_p(x, y);
    end
end

%this part is for Extracting the Original sized Image
g = zeros([M, N]);
for x = 1 : M
    for y = 1 : N
        g(x, y) = g_p(x, y);
    end
end

figure; imshow(f, []);
figure; imshow(g, []);