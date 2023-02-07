clc;

f = im2double(rgb2gray(imread('cat.jpg')));
[M,N] = size(f);
h = ones([7,7]) / 49;
f_p = padarray(f,[6,6]);
g = zeros([M+6,N+6]);
[M_p,N_p] =  size(f_p);


for x = 4:M_p-3
    for y = 4:N_p-3
        g(x,y) = sum(sum(f_p(x-3:x+3,y-3:y+3).*h));
    end
end

subplot(121);
imshow(f);
subplot(122);
imshow(g);