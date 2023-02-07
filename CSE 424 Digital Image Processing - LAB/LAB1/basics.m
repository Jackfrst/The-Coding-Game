clc;

% Matrix
% a = [2,3;5,4];
% disp(a);
% disp(size(a));

% Random number
% A = rand([5,5]);
% disp(A);
% disp(A(1:2,1:2));

% Variable Declare 
% n = 1 : 0.5 : 10;
% disp(n);

% Image
f = rgb2gray(imread('demo.jpg'));
[M,N] = size(f);
% disp(size(f));
 imshow(f);

% Edit Image
% imshow(f * 6 , []);
a = f(1 , 1);
for i = 1: M
    for j = 1: N
        if a < f(i, j)
            a = f(i, j);
            x_h = i;
            y_h = j;
        else    
        end    
    end 
end
p_h = [x_h, y_h];

fprintf('The brightest pixel is (X Y) :');
disp(p_h);
fprintf('The Peak brightness is :');
disp(a);
