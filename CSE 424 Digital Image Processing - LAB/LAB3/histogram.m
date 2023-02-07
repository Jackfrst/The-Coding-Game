f1 = imread("h1.tif");
f = imread("h1.tif");
 [M,N] = size(f);
 
 n = zeros(256);
 
 for x = 1:M
     for y = 1:N
         i = f(x,y);
         n(i+1) = n(i+1) + 1;
     end
 end

% figure;stem(n);
% figure;stem(s);
% figure;imhist(f);

 s = zeros(256);
 c = 255/(M*N);
 sum = 0;
 j = 1;
 for k = 1:256
     sum = sum + n(j);
     s(k) = c * sum;
     j = j+1;
 end
 

for x = 1:M
    for y = 1:N
        for k = 0:255
            if  f(x,y) == k
                f(x,y) = s(k+1);
            end
        end
    end
end
 
% f2 = histeq(f1);

figure;imshow(f);
figure;imshow(f1);
% figure;imshow(f2);

 
 