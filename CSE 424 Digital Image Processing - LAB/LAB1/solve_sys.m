function x = solve_sys(A,b)
    x = zeros([1,2]);
    adj = zeros([2,2]);
    
    det = A(1,1) * A(2,2) - A(1,2) * A(2,1);
    adj(1,1) = A(2,2);
    adj(1,2) = -A(1,2);
    adj(2,1) = -A(2,1);
    adj(2,2) = A(1,1);
    
    inv = (1/det) * adj;
    
    x = inv * b';   
end 