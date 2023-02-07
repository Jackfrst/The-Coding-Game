clc;
f = imread('h.tif');
[M, N] = size(f);

P = 2 * M;
Q = 2 * N;
f_p = zeros([P, Q]);
for x = 1 : M
    for y = 1 : N
        f_p(x, y) = f(x, y);
    end
end

for x = 1 : P
    for y = 1 : Q
        f_p(x, y) = (-1)^(x+y) * f_p(x, y);
    end
end

F = fft2(f_p);

D =  @(u,v) sqrt((u-P/2)^2 +(v-Q/2)^2);
H =  zeros([P,Q]);
for u = 1:P
    for v = 1:Q
        if( D(u,v) <= 30)
            H(u,v)= 1;
        end
    end 
end 

G = F .* H;
g_p = real(ifft2(G));

for x = 1:P
    for y =  1:Q
       g_p(x,y) = (-1)^(x+y) * g_p(x,y);
    end 
end

g = zeros([M,N]);
for x = 1:M
    for y =  1:N
       g(x,y) = g_p(x,y);
    end 
end

figure; imshow(f_p, []);
figure; imshow(g, []);