clc;
image = imread('adaptive thres.tif');
mean_image = imfilter(image, fspecial('average',[55,55]),'replica');
subtract = image - (mean_image+20);

black_white = im2bw(subtract,0);

subplot(1,2,1); imshow(black_white); title('Threshold Image');
subplot(1,2,2); imshow(image); title('Original Image');