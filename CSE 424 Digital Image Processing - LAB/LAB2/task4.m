f = imread('grain.tif');
[M, N] = size(f);
g = zeros([M, N]);

%demo
T = 130;
for x = 1 : M
    for y = 1 : N
        if f(x, y) >= T
            g(x, y) = f(x, y);
        end
    end
end
figure; imshow(f);
figure; imshow(g, []);

%negetive
% f = imread('b.tif');
% f = im2double(f);
% [M, N] = size(f);
% g = zeros([M, N]);
% 
% for x = 1 : M
%     for y = 1 : N
%         g(x,y) = 255 - f(x,y);
%     end
% end
% figure; imshow(f);
% figure; imshow(g, []);

% %log
% f = imread('b.tif');
% f = im2double(f);
% g = 25 * log(f + 1);
% figure; imshow(f);
% figure; imshow(g);
% 
% %gama
% f = imread('e.tif');
% f = im2double(f);
% c = 1;
% gamma = 3.5;
% g = c * f .^ gamma;
% figure; imshow(f);
% figure; imshow(g);