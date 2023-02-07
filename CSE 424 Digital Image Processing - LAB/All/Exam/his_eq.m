clc;

f = imread('h2.tif');
f1 = imread('h2.tif');
[M,N] = size(f);

n = zeros([1,256]);
n_e = zeros([1,256]);
s = zeros([1,256]);

for x = 1:M
    for y = 1:N
        i = f(x,y)+1;
        n(i) = n(i) + 1;
    end
end

c = 255/ (M * N);

s_ = 0;
for k = 1:256
    s_ = s_ + n(k);
    s(k) = round(c * s_);
end

for x = 1:M
    for y = 1:N
        i = f(x,y);
        f1(x,y) = s(i+1);
    end
end

for x = 1:M
    for y = 1:N
        i = f1(x,y);
        n_e(i) = n_e(i) + 1;
    end
end


subplot(221);
imshow(f);
subplot(222);
stem(n);
subplot(223);
imshow(f1);
subplot(224);
stem(n_e);


