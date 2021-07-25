USE DBProject

-- 4.

-- a)
INSERT INTO Departamento
  (DepNum, Nome, Local)
VALUES(100, 'E-toupeira', 'Luz-apagada');

-- b)
INSERT INTO Empregado
VALUES(1500, 'Furao mor', 'Coordenador', 1200000, 100);

-- c)
UPDATE Departamento
SET Local = 'Lisboa'
WHERE DepNum = 100;

-- d)
--DELETE FROM Departamento
--WHERE DepNum = 100;

-- e)
DELETE FROM Empregado
WHERE EmpNum = 1500;

-- f)
DELETE FROM Departamento
WHERE DepNum = 100;

-- 5

-- a)
SELECT Nome
FROM Departamento;

-- b)
SELECT Nome
FROM Empregado;

-- c)
SELECT Designacao
FROM Projecto;
