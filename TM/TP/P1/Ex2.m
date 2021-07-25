%% Exercicio 2
t = 1/8 : 1/8 : 1;
m = 6 * sin (2*pi*t)
plot(t, m)

% amostras
mQ = [9/2 11/2 9/2 1/2 -9/2 -11/2 -9/2 1/2]

% erros
Erro = (m(1:end) - mQ).^2

% erro medio
E = sum(Erro)/length(Erro)
