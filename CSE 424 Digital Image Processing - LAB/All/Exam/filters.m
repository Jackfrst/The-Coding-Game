clc;

f = im2double(rgb2gray(imread('cat.jpg')));
[M,N] = size(f);

%filters 
ha = ones([7,7]) / 49; %avg
%hlap = [ 0,1,0;1,-4,1;0,1,0];
%hsobel1 = [ -1,-2,-1; 0,0,0; 1,2,1];
%hsobel1 = [ -1,0,1; -2,0,2; -1,0,1];

%padding
f_p = padarray(f,[6,6]);
g = zeros([M+6,N+6]);
[M_p,N_p] =  size(f_p);

%Convolution
for x = 4:M_p-3
    for y = 4:N_p-3
        g(x,y) = sum(sum(f_p(x-3:x+3,y-3:y+3).*ha));
    end
end

subplot(121);
imshow(f);
subplot(122);
imshow(g);