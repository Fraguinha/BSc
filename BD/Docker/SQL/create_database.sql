CREATE DATABASE DBProject
GO

USE DBProject
GO

if not exists (select *
from dbo.sysobjects
where id = object_id(N'[dbo].[Departamento]') )
begin
  CREATE TABLE Departamento
  (
    DepNum int NOT NULL
      CHECK (DepNum >= 1),
    Nome nvarchar(30) NOT NULL,
    Local nvarchar(30) NOT NULL
      DEFAULT 'Covilha',

    CONSTRAINT PK_DepNum PRIMARY KEY (DepNum),
    CONSTRAINT U_Nome UNIQUE (Nome)
  );
end

if not exists (select *
from dbo.sysobjects
where id = object_id(N'[dbo].[Empregado]') )
begin
  CREATE TABLE Empregado
  (
    EmpNum int NOT NULL
      CONSTRAINT PK_EmpNum PRIMARY KEY (EmpNum)
      CHECK (EmpNum >= 1),
    Nome nvarchar (50) NOT NULL ,
    Categoria nvarchar (30) NULL ,
    Salario decimal(10,2) NOT NULL
      DEFAULT 0.0
      CHECK (Salario >= 0.0),
    DepNum int NOT NULL,

    CONSTRAINT FK_DepNum FOREIGN KEY (DepNum)
	     REFERENCES Departamento(DepNum)
	     ON UPDATE CASCADE
	     ON DELETE NO ACTION
  );
end

if not exists (select *
from dbo.sysobjects
where id = object_id(N'[dbo].[Projecto]') )
begin
  CREATE TABLE Projecto
  (
    ProjNum int
      CONSTRAINT nn_ProjNum NOT NULL
      CONSTRAINT C_ProjNum CHECK (ProjNum >= 10),
    Designacao nvarchar (30)
      CONSTRAINT nn_Designacao NOT NULL,
    Fundos decimal(10,2) NOT NULL
      DEFAULT 10.0
      CHECK (Fundos >= 0.0)
  );

  ALTER TABLE Projecto DROP CONSTRAINT C_ProjNum;
  ALTER TABLE Projecto ADD  CONSTRAINT C_ProjNum CHECK (ProjNum >= 0);

  ALTER TABLE Projecto Add  CONSTRAINT PK_ProjNum  PRIMARY KEY (ProjNum);
  ALTER TABLE Projecto Add  CONSTRAINT U_Designacao  UNIQUE (Designacao);
end

if not exists (select *
from dbo.sysobjects
where id = object_id(N'[dbo].[Atribuicao]') )
begin
  CREATE TABLE Atribuicao
  (
    EmpNum int
      CONSTRAINT nn_EmpNum NOT NULL,
    ProjNum int
      CONSTRAINT nn_ProjNum NOT NULL,
    Funcao nvarchar(30)
      CONSTRAINT nn_Funcao NOT NULL,

    CONSTRAINT PK_Atribuicao
	    PRIMARY KEY (EmpNum, ProjNum),

    CONSTRAINT FK_EmpNum FOREIGN KEY (EmpNum)
	    REFERENCES Empregado(EmpNum)
	    ON UPDATE CASCADE,

    CONSTRAINT FK_ProjNum FOREIGN KEY (ProjNum)
	    REFERENCES Projecto(ProjNum)
	    ON UPDATE CASCADE

  );
end
GO

INSERT INTO Departamento
  (DepNum, Nome, Local)
Values
  (1, 'Camarote', 'Camarate');

INSERT INTO Departamento
  (DepNum, Nome, Local)
Values
  (2, 'Informatica', 'Covilha');

INSERT INTO Departamento
  (DepNum, Nome, Local)
Values
  (3, 'Producao', 'Guarda');

INSERT INTO Departamento
  (DepNum, Nome, Local)
Values
  (4, 'Comercial', 'Lisboa');

SET IMPLICIT_TRANSACTIONS ON

INSERT INTO EMPREGADO
VALUES
  (1, 'Jose', 'Artista', 230000, 1);

INSERT INTO EMPREGADO
VALUES
  (2, 'Artur', 'Programador', 250000, 2);

INSERT INTO EMPREGADO
VALUES
  (3, 'Carlos', 'Analista', 300000, 2);

INSERT INTO EMPREGADO
VALUES
  (4, 'Zezinho', 'Artes graficas', 150000, 1);

INSERT INTO EMPREGADO
VALUES
  (5, 'Abilio', 'Chefe seccao', 100000, 3);

INSERT INTO EMPREGADO
VALUES
  (6, 'Antonio', 'Design', 100000, 3);

INSERT INTO EMPREGADO
VALUES
  (7, 'Daniela', 'Modelo', 80000, 3);

INSERT INTO EMPREGADO
VALUES
  (8, 'Margarida', 'Director', 350000, 4);

INSERT INTO EMPREGADO
VALUES
  (9, 'Fazenda', 'Patrao', 6000000, 4);

INSERT INTO EMPREGADO
VALUES
  (10, 'Marilia', 'Secretaria', 85000, 4);

COMMIT;

SET IMPLICIT_TRANSACTIONS OFF

BEGIN TRAN

INSERT INTO Projecto
  (ProjNum, Designacao, Fundos)
Values
  (1, 'Rir a gargalhada', 60000);

INSERT INTO Projecto
  (ProjNum, Designacao, Fundos)
Values
  (2, 'BD do IPG', 5000000);

INSERT INTO Projecto
  (ProjNum, Designacao, Fundos)
Values
  (3, 'Sapataria da Beira', 3000000);

INSERT INTO Projecto
  (ProjNum, Designacao, Fundos)
Values
  (4, 'Lotaria', 5060000);

COMMIT;

BEGIN TRAN

INSERT INTO Atribuicao
  (EmpNum, ProjNum, Funcao)
VALUES
  (1, 1, 'Animador');

INSERT INTO Atribuicao
  (EmpNum, ProjNum, Funcao)
VALUES
  (2, 2, 'Colaborador');

INSERT INTO Atribuicao
  (EmpNum, ProjNum, Funcao)
VALUES
  (3, 2, 'Coordenador');

INSERT INTO Atribuicao
  (EmpNum, ProjNum, Funcao)
VALUES
  (3, 2, 'Colaborador');

IF @@ERROR <> 0
  Begin
  select 'An error occurred in the insert operation'

  INSERT INTO Atribuicao
    (EmpNum, ProjNum, Funcao)
  VALUES
    (3, 3, 'Colaborador');
End

INSERT INTO Atribuicao
  (EmpNum, ProjNum, Funcao)
VALUES
  (5, 3, 'Coordenador');

INSERT INTO Atribuicao
  (EmpNum, ProjNum, Funcao)
VALUES
  (6, 3, 'Colaborador');

INSERT INTO Atribuicao
  (EmpNum, ProjNum, Funcao)
VALUES
  (7, 3, 'Colaborador');

COMMIT;
GO
