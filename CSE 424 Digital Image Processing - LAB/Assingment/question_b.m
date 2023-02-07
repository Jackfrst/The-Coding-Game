clc;
% read image
f=imread('FINGER_PRINT.tif');
[M,N] = size(f);

% create structuring element            
se = ones(11, 11);
 
% store number of rows
% in P and number of columns in Q.		
[P, Q]=size(se);

% create a zero matrix of size I.	
gd=zeros(size(f, 1), size(f, 2));

for i = ceil(P/2): M - floor(P/2)
	for j = ceil(Q/2): N - floor(Q/2)

		% take all the neighbourhoods.
		dn=f(i-floor(P/2):i+floor(P/2), j-floor(Q/2):j+floor(Q/2));

		% take logical se
		nd=dn(logical(se));
	
		% compare and take minimum value of the neighbor
		% and set the pixel value to that minimum value.
		gd(i, j)=max(nd(:));	
	end
end

figure,imshow(f),title("Original Image");
figure,imshow(gd),title("Dilated Image");