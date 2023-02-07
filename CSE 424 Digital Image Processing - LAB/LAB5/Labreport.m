clc;

f = im2double(rgb2gray(imread('cat.jpg')));
[M,N] = size(f);

prompt = "Number of Row (Filter _ must be ODD):"; %Taking user given size of the Filter
A = input(prompt);
prompt1 = "Number of Colum (Filter _ must be ODD):";
B = input(prompt1);
h = ones([A,B]) / (A*B); %Creating the filter

f_p = padarray(f,[A-1,B-1]); %Padding the image according the filter size
[M_p,N_p] =  size(f_p); % Getting the size of the padded image
g = zeros([M_p,N_p]); %Creating a housing for the Output image  

x_s = int64(A / 2); %Calculating the mid point, starting point of correlation , ending point of corellation 
y_s = int64(B / 2);
x_e = x_s -1;
y_e = y_s -1;
for x = x_s:M_p-x_e %Correlating the image according the filter 
    for y = y_s:N_p-y_e
        g(x,y) = sum(sum(f_p(x-x_e:x+x_e,y-y_e:y+y_e).*h));
    end
end

g = g((A-1)+1:end-(A-1),(B-1)+1:end-(B-1)); %Unpadding the output image back to input image 

subplot(121); %Showing the input 
imshow(f);
subplot(122); %Showing the output
imshow(g);