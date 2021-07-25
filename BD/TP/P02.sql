USE DBProject

-- 1)
SELECT Nome, Categoria
FROM Empregado;

-- 2)
SELECT *
FROM Empregado
WHERE Categoria = 'Programador';

-- 3)
SELECT Nome
FROM Empregado
WHERE Categoria = 'Programador';

-- 4)
-- a)
SELECT Nome
FROM Empregado
WHERE Salario >= 200000 AND Salario <= 350000;
-- b)
SELECT Nome
FROM Empregado
WHERE Salario BETWEEN 200000 AND 350000;

-- 5)
SELECT *
FROM Empregado
WHERE Nome LIKE 'C%';

-- 6)
SELECT *
FROM Projecto
WHERE Designacao LIKE '%ria%';

-- 7)
SELECT DISTINCT DepNum
FROM Empregado;

-- 8)
SELECT DepNum
FROM Empregado;

-- 9)
SELECT *
FROM Empregado AS E, Departamento AS D
WHERE E.DepNum = D.DepNum;

-- 10)
SELECT E.*, D.Nome, D.Local
FROM Empregado AS E, Departamento AS D
WHERE E.DepNum = D.DepNum;

-- 11)
SELECT E.*, D.Nome, D.Local
FROM Empregado AS E INNER JOIN Departamento AS D
  ON E.DepNum = D.DepNum;

-- 12)
SELECT D.DepNum, D.Nome, E.EmpNum, E.Nome
FROM Departamento AS D
  LEFT JOIN Empregado AS E
  ON D.DepNum = E.DepNum;

-- 13)
-- a)
SELECT E.EmpNum
FROM Empregado AS E, Atribuicao AS A
WHERE E.EmpNum = A.EmpNum AND (A.Funcao = 'coordenador' OR A.Funcao = 'colaborador');
-- b)
--???

-- 14)
SELECT EmpNum
FROM Atribuicao AS A1
WHERE Funcao = 'coordenador' AND EXISTS
(SELECT EmpNum
  FROM Atribuicao AS A2
  WHERE A1.EmpNum = A2.EmpNum AND Funcao = 'colaborador');
