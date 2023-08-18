function [solVec,err,iter,flag] = sorSolver(A,b,w,max_it,tol)

%Allocate size of x vector
[~,N] = size(A);
solVec = zeros(N,1);

%Check number of input parameters
if nargin == 3
    w = 0.5;
    max_it = 1e4;
    tol = 1e-4;
elseif nargin == 4
    max_it = 1e4;
    tol = 1e-4;
elseif nargin == 5
    tol = 1e-4;
elseif nargin ~= 6
    error('sor: invalid input parameters');
end

flag = 0;
iter = 0;

norma2_b = norm(b);
if (norma2_b == 0.0)
    norma2_b = 1.0;
end

r = b - A * solVec;
err = norm(r) / norma2_b;
if (err < tol)
    return
end

% separate A into several matrix for SOR/Gauss-Seidel
[ M, N, b ] = matsep(A, b, w, 2);

for iter = 1 : max_it
    x_1 = solVec;
    solVec = M \ (N * solVec + b); % adjust the aproximation
    %err = norm(x - x_1) / norm(x); % compute error
    err = norm(x_1 - solVec, 1); % compute error
    if (err <= tol) % check for convergence
        break
    end
end
b = b / w; % vector b

if (err > tol) % no convergence
    flag = 1;
end

end


function [ M, N, b ] = matsep(A, b, w, flag)

if nargin ~= 4
    error('matsep: invalid input parameters');
end

[ m, n ] = size(A);
if m ~= n
    error('matsep: input matrix A must have dimension nXn');
end

[ l, o ] = size(b);
if l ~= n && o ~= 1
    error('matsep: input matrix b must have dimension nX1');
end

if (flag == 1) % separation for Jacobi
    M = diag(diag(A));
    N = diag(diag(A)) - A;
elseif (flag == 2) % separation for SOR/Gauss-Seidel
    b = w * b;
    M =  w * tril(A, -1) + diag(diag(A));
    N = -w * triu(A,  1) + (1.0 - w) * diag(diag(A));
end

end