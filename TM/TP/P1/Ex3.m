%% Exercicio 3
t = 1/16 : 1/16 : 1;
m = 6 * sin (2*pi*t)
plot(t, m)

% amostras dobro
mQ = [9/4 17/4 11/2 6 11/2 17/4 9/4 1/4 -9/4 -17/4 -11/2 -6 -11/2 -17/4 -9/4 -1/4]

% erros
Erro = (m(1:end) - mQ).^2

% erro medio
E = sum(Erro)/length(Erro)
