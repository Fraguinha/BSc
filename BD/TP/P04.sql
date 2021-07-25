USE DBProject;

-- 28)
SELECT AVG(Salario) AS Num
FROM Empregado
WHERE DepNum = 1;

-- 29)
SELECT Designacao
FROM Projecto
WHERE Fundos = (
 SELECT MAX(Fundos)
FROM Projecto
);

-- 30)
SELECT Nome
FROM Empregado
WHERE EmpNum IN (
 SELECT EmpNum
FROM Atribuicao
WHERE ProjNum = (
   SELECT ProjNum
FROM Projecto
WHERE Fundos = (
     SELECT MAX(Fundos)
FROM Projecto
   )
 )
);

-- 31)
SELECT Nome
FROM Empregado AS E1
WHERE E1.Salario > (
 SELECT AVG(E2.Salario)
FROM Empregado AS E2
WHERE E1.DepNum = E2.DepNum
);

-- 32)
SELECT COUNT(EmpNum) AS Num
FROM Empregado
GROUP BY DepNum;

-- 33)
SELECT COUNT(EmpNum) AS Num
FROM Empregado
WHERE Categoria = 'Programador'
GROUP BY DepNum;

-- 34)
SELECT D.Nome, Num
FROM Departamento AS D, (
 SELECT E.DepNum, COUNT(E.EmpNum) AS Num
  FROM Empregado AS E
  GROUP BY DepNum
) AS T
WHERE D.DepNum = T.DepNum;

-- 35)
SELECT D.Nome, T.AVGS, T.MINS, T.MAXS
FROM Departamento AS D, (
 SELECT E.DepNum, AVG(Salario) AS AVGS, MIN(Salario) AS MINS, MAX(Salario) AS MAXS
  FROM Empregado AS E
  GROUP BY DepNum
) T
WHERE D.DepNum = T.DepNum;

-- 36)
SELECT D.Nome, T.AVGS, T.MINS, T.MAXS
FROM Departamento AS D, (
 SELECT E.DepNum, AVG(Salario) AS AVGS, MIN(Salario) AS MINS, MAX(Salario) AS MAXS
  FROM Empregado AS E
  GROUP BY DepNum
) T
WHERE D.DepNum = T.DepNum
ORDER BY T.AVGS DESC;
