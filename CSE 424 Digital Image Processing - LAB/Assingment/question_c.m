% read image
f=imread('FINGER_PRINT.tif');
[M,N] = size(f);

% create structuring element            
se = ones(3, 3);
 
% store number of rows
% in P and number of columns in Q.		
[P, Q]=size(se);

% create a zero matrix of size I.	
gd = zeros(M, N);
ge = zeros(M, N); 

for i = ceil(P/2): M - floor(P/2)
	for j = ceil(Q/2): N - floor(Q/2)

		% take all the neighbourhoods.
		en=f(i-floor(P/2):i+floor(P/2), j-floor(Q/2):j+floor(Q/2));

		% take logical se
		eh=en(logical(se));
	
		% compare and take minimum value of the neighbor
		% and set the pixel value to that minimum value.
		gd(i, j)=max(eh(:));	
	end
end

for i = ceil(P/2): M - floor(P/2)
	for j = ceil(Q/2): N - floor(Q/2)

		% take all the neighbourhoods.
		dn = gd(i-floor(P/2):i+floor(P/2), j-floor(Q/2):j+floor(Q/2));

		% take logical se
		dh = dn(logical(se));
	
		% compare and take minimum value of the neighbor
		% and set the pixel value to that minimum value.
		ge(i, j)=min(dh(:));	
	end
end

figure,imshow(f),title("Original Image");
figure,imshow(ge),title("Closed Image");