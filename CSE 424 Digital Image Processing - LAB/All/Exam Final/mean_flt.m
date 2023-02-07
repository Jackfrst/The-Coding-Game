%READ AN IMAGE
f = imread('h.tif');
figure,imshow(f),title('ORIGINAL IMAGE');

A = imnoise(f,'salt & pepper',0.02);
figure, imshow(A, []);
title('Noissy image');

%PREALLOCATE THE OUTPUT MATRIX
g=zeros(size(A));

%PAD THE MATRIX A WITH ZEROS
A_p = padarray(A,[1 1]);
[M_p,N_p] = size(A_p);
   
%Arithmatic
for i= 2 : M_p-1
    for j= 2 : N_p-1
        
       g(i,j) = mean(mean(A_p(i-1:i+1,j-1:j+1)));

    end
end

% Q = 5; 
% %Contaharmonic
% for i= 2 : M_p-1
%     for j= 2 : N_p-1
%         
%        q1 = sum(sum(A_p(i-1:i+1,j-1:j+1).^ Q+1));
%        q2 = sum(sum(A_p(i-1:i+1,j-1:j+1).^ Q));
%        g(i,j)= q1 / q2;
% 
%     end
% end


g=uint8(g);
figure,imshow(g),title('IMAGE AFTER Mean FILTERING');