% Exercicio 4
t = 1/8 : 2/8 : 7/8;
m = 2 * sin (2*pi*t)
plot(t, m)

% amostras metade
mQ = [1/4 1/4 -1/4 -1/4]

% erros
Erro = (m(1:end) - mQ).^2

% erro medio
E = sum(Erro)/length(Erro)
