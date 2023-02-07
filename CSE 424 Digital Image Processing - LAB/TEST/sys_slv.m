function x = sys_slv(A,b)
   det = (A(1,1)*A(2,2)) - (A(1,2)*A(2,1));
   Adj(1,1) = A(2,2);
   Adj(2,2) = A(1,1);
   Adj(1,2) = -A(1,2);
   Adj(2,1) = -A(2,1);
   inv = (1/det)* Adj;
   x = inv * b';
end

