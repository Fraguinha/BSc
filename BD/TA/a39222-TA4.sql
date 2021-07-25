-- Número: 39222
-- Nome: João Fraga
-- Curso: EI
-- Trabalho: TA4

USE DBProject;

-- Q1: Mostre toda a informação que existe na base de dados sobre cada um dos empregados que participam em projetos (não incluir chaves na visualização).

SELECT Nome, Categoria, Salario
FROM Empregado AS E
WHERE E.EmpNum IN (
  SELECT DISTINCT EmpNum
FROM Atribuicao
);

-- Q2: Mostre os valores do terceiro e quarto melhores salários (sugestão: utilizar TOP, DISTINCT, ORDER BY, DESC).

SELECT TOP 2
  Salario
FROM (
  SELECT Salario
  FROM Empregado
  WHERE Salario NOT IN (
    SELECT TOP 2
    Salario
  FROM Empregado
  )
) Tbl;

-- Q3: Mostrar todas as funções que aparecem mais do que uma vez na tabela atribuição, incluindo também a quantidade respetiva (sugestão: utilizar TOP HAVING e GROUP BY).

SELECT Funcao
FROM Atribuicao
GROUP BY Funcao
HAVING COUNT(Funcao) > 1;
