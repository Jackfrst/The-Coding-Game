clc;

f = imread('Marr-Hildreth.tif');
[M,N] = size(f);
f_ = double(f);
f_p = padarray(f_,[24,24]);
g = zeros(size(f_p));
[M_p,N_p] =  size(f_p);

sigma = 4;
n = 25;
h = [0 -1 0; -1 4 -1; 0 -1 0];

figure,imshow(f),title('Original Picture');

G = zeros([25,25]);

for x = 1:25
    for y = 1:25
       G(x,y) = exp(-(((x-1)^2+(y-1)^2)/(2 * (sigma ^ 2))));
    end
end
G = G/sum(G(:));

for x = 25:M_p- 24
    for y = 25:N_p- 24
        g(x,y) = sum(sum(f_p(x-12:x+12,y-12:y+12).*G));
    end
end

g = g(25:M_p-24,25:N_p-24);

g_ = padarray(g,[2,2]);
[Mg_p,Ng_p] =  size(g_);
LoG = zeros(size(g_));

for x = 3:Mg_p-2
    for y = 3:Ng_p-2
        LoG(x,y) = sum(sum(g_(x-1:x+1,y-1:y+1).*h));
    end
end

LoG = LoG(3:Mg_p-2,3:Ng_p-2);
figure,imshow(LoG),title('LoG Picture');

zeroImage = zeros(size(LoG));
zeroImage(abs(LoG) > .04*max(LoG(:))) = 255;
figure, imshow(uint8(zeroImage)), title('Zero crossing');



