clc;
% taking input images
f=imread("Marr-Hildreth.tif");
%% Marr-Hildreth filter
% LoG filter definition 
sigma = 4;
log_filt=LoG(sigma);
%% Convolving 
LoG_img = zeros(size(f));
K = size(log_filt,1);
mid = round(K/2-1);
f = double(f);

for i=1:size(f,1)-K-1
    for j=1:size(f,2)-K-1
        LoG_img(i+mid,j+mid) = sum(sum(log_filt.*f(i:i+(K-1),j:j+(K-1))));
    end
end
figure, imshow(LoG_img); title("LoG filtered image");
%% Slope 
slope = 0.5*mean(abs(LoG_img(:)));
%% Zero cross
detectedEdges = zero_cross(LoG_img,slope);
f = uint8(f);
figure, 
subplot(1,2,1);imshow(f); title("Input image");
subplot(1,2,2);imshow(detectedEdges); title("Edge detected imges");