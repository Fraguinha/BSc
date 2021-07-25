% 1
A = [1:4;5:8;9:12]

% 2
B = A(2,2)

% 3
A(3,2) = 10

% 4
C = A(2,:)

% 5
D = A(:,2)

% 6
E = A(2:3, 2:3)

% 7
F = A(:,4:-1:1)

% 8
G = A(3:-1:1,:)

% 9
H = A(2:2:3,2:2:4)

% 10
size(A)
size(C)
size(D)

% 11
vlin = reshape(A,1,size(A)(1) * length(A))

% 12
I = A' % As linhas foram trocadas pelas colunas

% 13
Z = zeros(6,8)

% 14
Z(2:2:end,2:2:end) = A(:,:)

% 15
Z(1:2:end,1:2:end) = A(:,:)

% 16
Z(1:2:end,2:2:end) = A(:,:)

% 17
Z(2:2:end,1:2:end) = A(:,:)

% 18
rot90A = A'(end:-1:1,:)

% 19
rot180A = rot90A'(end:-1:1,:)

% 20
sum(A')'
