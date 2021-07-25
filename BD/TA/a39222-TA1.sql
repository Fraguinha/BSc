--
-- Número: 39222
-- Nome: João Fraga
-- Curso: Engenharia Informática
-- Trabalho: TA1
--

USE DBProject;

-- Q1: Quais são os nomes e os salários dos empregados que não trabalham no departamento 3 e que recebem menos de 1/20 do salário do patrão.
SELECT Nome, Salario
FROM Empregado
WHERE DepNum != 3 AND Salario < (
  SELECT Salario
  FROM Empregado
  WHERE Categoria = 'Patrao'
) / 20;

-- Q2: Quais são os empregados que tem um nome com 7 letras.
SELECT Nome
FROM Empregado
WHERE Nome LIKE '_______';

-- Q3: Quais são os nomes e funções dos empregados que não participam em projetos.
SELECT Nome, Categoria
FROM Empregado
WHERE EmpNum NOT IN (
  SELECT EmpNum
FROM Atribuicao
);
