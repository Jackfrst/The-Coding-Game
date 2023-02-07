clc;

f = imread("h1.tif");
f1 = f;

[M,N] = size(f);
n = zeros([1,256]);
s = zeros([1,256]);
ne = zeros([1,256]);

for x = 1:M
    for y = 1:N
        i = f(x,y)+1;
        n(i) = n(i)+1;
    end
end

sum = 0;
c = 255 / (M * N);
for k = 1:256
    sum = sum + n(k);
    s(k) = round(c * sum);
end

for x = 1:M
    for y = 1:N
        i = f(x,y)+1;
        f1(x,y) = s(i);
    end
end

for x = 1:M
    for y = 1:N
        i = f1(x,y)+1;
        ne(i) = ne(i)+1;
    end
end


subplot(231);
imshow(f);
subplot(232);
stem(n);
subplot(233);
stem(s);
subplot(234);
imshow(f1);
subplot(235);
stem(ne);