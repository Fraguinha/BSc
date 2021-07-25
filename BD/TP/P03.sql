USE DBProject

-- 15)
SELECT E.EmpNum
FROM Empregado AS E, Atribuicao AS A
WHERE E.EmpNum = A.EmpNum AND A.Funcao = 'coordenador' AND E.EmpNum IN (
 SELECT E.EmpNum
  FROM Empregado AS E, Atribuicao AS A
  WHERE E.EmpNum = A.EmpNum AND A.Funcao = 'colaborador'
);

-- 16)
SELECT E.EmpNum
FROM Empregado AS E, Atribuicao AS A
WHERE E.EmpNum = A.EmpNum AND A.Funcao = 'coordenador' AND E.EmpNum NOT IN (
 SELECT E.EmpNum
  FROM Empregado AS E, Atribuicao AS A
  WHERE E.EmpNum = A.EmpNum AND A.Funcao = 'colaborador'
);

-- 17)
SELECT Designacao
FROM Projecto
WHERE ProjNum IN (
 SELECT P.ProjNum
FROM Projecto AS P, Atribuicao AS A1, Atribuicao AS A2, Empregado AS E1, Empregado AS E2
WHERE P.ProjNum = A1.ProjNum AND P.ProjNum = A2.ProjNum AND A1.EmpNum = E1.EmpNum AND A2.EmpNum = E2.EmpNum AND E1.EmpNum != E2.EmpNum AND E1.DepNum != E2.DepNum
);

-- 18)
SELECT DISTINCT E.Nome
FROM Empregado AS E, Atribuicao AS A1, Atribuicao AS A2
WHERE E.EmpNum = A1.EmpNum AND E.EmpNum = A2.EmpNum AND A1.ProjNum != A2.ProjNum;

-- 19)
SELECT COUNT(EmpNum) AS Num
FROM Empregado AS E;

-- 20)
SELECT COUNT(EmpNum) AS Num
FROM Empregado AS E
WHERE E.DepNum = 1;

-- 21)
SELECT COUNT(E.EmpNum) AS Num
FROM Empregado AS E, Departamento as D
WHERE E.DepNum = D.DepNum AND D.Local = 'Covilhã';

-- 22)
SELECT Nome
FROM Departamento
WHERE DepNum NOT IN (
 SELECT E.DepNum
FROM Empregado AS E
);

-- 23)
SELECT SUM(Salario) AS Num
FROM Empregado
WHERE DepNum = 1;

-- 24)
SELECT SUM(Salario) AS Num
FROM Empregado
WHERE EmpNum IN (
 SELECT EmpNum
FROM Atribuicao
WHERE ProjNum = 1
);

-- 25)
SELECT COUNT(DISTINCT Categoria) AS Num
FROM Empregado;

-- 26)
SELECT MAX(Salario) AS Num
FROM Empregado

-- 27)
SELECT Nome
FROM Empregado
WHERE Salario = (
 SELECT MIN(Salario) AS Salario
FROM Empregado
);
