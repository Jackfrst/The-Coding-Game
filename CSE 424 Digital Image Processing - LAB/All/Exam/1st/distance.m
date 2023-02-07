f = rgb2gray(imread('demo.jpg'));
fde = rgb2gray(imread('demo.jpg'));
fd4 = rgb2gray(imread('demo.jpg'));
fd8 = rgb2gray(imread('demo.jpg'));
[M,N] = size(f);

c_M = M/2;
c_N = N/2;

De = @(x,y) sqrt((x - c_M)^2 + (y - c_N)^2);
D4 = @(x,y) abs(x - c_M) + abs(y - c_N);
D8 = @(x,y) max(abs(x - c_M),  abs(y - c_N));

d = 100;
for i = 1:M
    for j = 1:N
       if De(i,j) <= d
            fde(i,j)=0;
       end
       if D4(i,j) <= d
            fd4(i,j)=0;
       end
       if D8(i,j) <= d
            fd8(i,j)=0;
       end
    end
end

imshow(fd4);