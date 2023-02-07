%READ AN IMAGE
f = imread('h.tif');
figure,imshow(f),title('ORIGINAL IMAGE');

A = imnoise(f,'salt & pepper',0.02);
figure, imshow(A, []);
title('Noissy image');

%PREALLOCATE THE OUTPUT MATRIX
g=zeros(size(A));

%PAD THE MATRIX A WITH ZEROS
A_p =padarray(A,[1 1]);
[M_p,N_p] = size(A_p);
      
for i= 2 : M_p-1
    for j= 2 : N_p-1
        
       g(i,j) = max(max(A_p(i-1:i+1,j-1:j+1)));

    end
end

g=uint8(g);
figure,imshow(g),title('IMAGE AFTER MAX FILTERING');