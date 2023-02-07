clc;

f = imread('kidney.tif');
[M,N] = size(f);

for x=1:M
    for y=1:N
        if f(x,y )>= 130
            g(x,y) = 1;
        else
            g(x,y) = 0;
        end
    end
end

for x=1:M
    for y=1:N
        if f(x,y )>= 130
            g1(x,y) = f(x,y);
        else
            g1(x,y) = 0;
        end
    end
end

f1 = im2double(f);
c = 100;
for x=1:M
    for y=1:N
            g2(x,y) = c*log( f1(x,y)+1);
    end
end

gam = 10;
for x=1:M
    for y=1:N
            g3(x,y) = c*f1(x,y).^gam;
    end
end

for x=1:M
    for y=1:N
            g3(x,y) = c*f1(x,y).^gam;
    end
end

a = zeros(256,1);
for x=1:M
     for y=1:N
            for i= 1:256
                j = i - 1;
                if f(x,y) == j
                    a(i,1) = a(i,1) + 1;
                end
            end
    end
end

figure;
subplot(2,1,1);
stem(a);
title('Histogram');
subplot(2,1,2);
imhist(imread('kidney.tif'));

% subplot(2,2,1);
% imshow(g,[]);
% subplot(2,2,2);
% imshow(g1,[]);
% subplot(2,2,3);
% imshow(g2,[]);
% subplot(2,2,4);
% imshow(g3,[]);

% figure;imshow(g,[]);
% figure;imshow(g1,[]);
% figure;imshow(g2,[]);
% figure;imshow(g3,[]);