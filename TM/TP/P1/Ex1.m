%% Exercicio 1
t = 1/8 : 2/8 : 1;
m = 6 * sin (2*pi*t)
plot(t, m)

% amostras
mQ = [9/2 9/2 -9/2 -9/2]

% erros
Erro = (m(1:end) - mQ).^2 % o "." representa element-wise

% erro medio
E = sum(Erro)/length(Erro)
