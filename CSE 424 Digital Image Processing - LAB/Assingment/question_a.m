clc;
% read image
f=imread('WIRE_BOND.tif');
[M,N] = size(f);

% create structuring element			
se=[0 1 0; 1 1 1; 0 1 0];

% store number of rows
% in P and number of columns in Q.		
[P, Q]=size(se);

% create a zero matrix of size I.	
ge=zeros(size(f, 1), size(f, 2));

for i = ceil(P/2): M - floor(P/2)
	for j = ceil(Q/2): N - floor(Q/2)

		% take all the neighbourhoods.
		en=f(i-floor(P/2):i+floor(P/2), j-floor(Q/2):j+floor(Q/2));

		% take logical se
		ne=en(logical(se));
	
		% compare and take minimum value of the neighbor
		% and set the pixel value to that minimum value.
		ge(i, j)=min(ne(:));	
	end
end

figure,imshow(f),title("Original Image");
figure,imshow(ge),title("Eroded Image");
