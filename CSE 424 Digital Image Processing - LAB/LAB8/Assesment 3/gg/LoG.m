function [nLoG] = LoG(sigma)
k=ceil(sigma)*5;
k = (k-1)/2; %Determining kernel size
[x,y] = meshgrid(-k:k,-k:k); %Initializing kernel

a = (x.^2+y.^2-2*sigma^2)/sigma^4;
b = exp(-( x.^2 + y.^2 )/(2*sigma^2));
b= b/sum(b(:));

LoG=a.*b; %LoG filter 
nLoG=LoG-mean2(LoG); %Normalized LoG filter
end

