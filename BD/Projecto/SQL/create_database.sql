CREATE DATABASE C4G;
GO

USE C4G;
GO

CREATE TABLE _Institution
(
  Name NVARCHAR(255) NOT NULL,
  Email NVARCHAR(255) NOT NULL,
  InstitutionID INT NOT NULL IDENTITY(1,1),
  PRIMARY KEY (InstitutionID)
);

CREATE TABLE _Laboratory
(
  Name NVARCHAR(255) NOT NULL,
  Email NVARCHAR(255) NOT NULL,
  LaboratoryID INT NOT NULL IDENTITY(1,1),
  InstitutionID INT NOT NULL,
  PRIMARY KEY (LaboratoryID),
  FOREIGN KEY (InstitutionID) REFERENCES _Institution(InstitutionID)
);

CREATE TABLE _Workgroup
(
  Name NVARCHAR(255) NOT NULL,
  Email NVARCHAR(255) NOT NULL,
  WorkgroupID INT NOT NULL IDENTITY(1,1),
  LaboratoryID INT NOT NULL,
  PRIMARY KEY (WorkgroupID),
  FOREIGN KEY (LaboratoryID) REFERENCES _Laboratory(LaboratoryID)
);

CREATE TABLE _Resource
(
  Name NVARCHAR(255) NOT NULL,
  Description NVARCHAR(255) NOT NULL,
  ResourceID INT NOT NULL IDENTITY(1,1),
  PRIMARY KEY (ResourceID)
);

CREATE TABLE _Member
(
  Name NVARCHAR(255) NOT NULL,
  Email NVARCHAR(255) NOT NULL,
  MemberID INT NOT NULL IDENTITY(1,1),
  PRIMARY KEY (MemberID)
);

CREATE TABLE _User
(
  Username NVARCHAR(255) NOT NULL,
  Password NVARCHAR(255) NOT NULL,
  PRIMARY KEY (Username)
);

CREATE TABLE _Admin
(
  Username NVARCHAR(255) NOT NULL,
  PRIMARY KEY (Username),
  FOREIGN KEY (Username) REFERENCES _User(Username)
);

CREATE TABLE _Resource_Requisition
(
  Date_Start DATE NOT NULL,
  Date_End DATE NOT NULL,
  Quantity INT NOT NULL,
  Username NVARCHAR(255) NOT NULL,
  ResourceID INT NOT NULL,
  PRIMARY KEY (Username, ResourceID, Quantity, Date_Start, Date_End),
  FOREIGN KEY (Username) REFERENCES _User(Username),
  FOREIGN KEY (ResourceID) REFERENCES _Resource(ResourceID)
);

CREATE TABLE _Resource_allocation
(
  Quantity INT NOT NULL,
  LaboratoryID INT NOT NULL,
  ResourceID INT NOT NULL,
  PRIMARY KEY (LaboratoryID, ResourceID),
  FOREIGN KEY (LaboratoryID) REFERENCES _Laboratory(LaboratoryID),
  FOREIGN KEY (ResourceID) REFERENCES _Resource(ResourceID)
);

CREATE TABLE _Service
(
  Name NVARCHAR(255) NOT NULL,
  Description NVARCHAR(255) NOT NULL,
  ServiceID INT NOT NULL IDENTITY(1,1),
  MemberID INT NOT NULL,
  PRIMARY KEY (ServiceID),
  FOREIGN KEY (MemberID) REFERENCES _Member(MemberID)
);

CREATE TABLE _Service_Requisition
(
  Date_Start DATE NOT NULL,
  Date_End DATE NOT NULL,
  ServiceID INT NOT NULL,
  Username NVARCHAR(255) NOT NULL,
  PRIMARY KEY (ServiceID, Username, Date_Start, Date_End),
  FOREIGN KEY (ServiceID) REFERENCES _Service(ServiceID),
  FOREIGN KEY (Username) REFERENCES _User(Username)
);

CREATE TABLE _Service_Allocation
(
  WorkgroupID INT NOT NULL,
  ServiceID INT NOT NULL,
  PRIMARY KEY (WorkgroupID, ServiceID),
  FOREIGN KEY (WorkgroupID) REFERENCES _Workgroup(WorkgroupID),
  FOREIGN KEY (ServiceID) REFERENCES _Service(ServiceID)
);

CREATE TABLE _Dependency
(
  ResourceID INT NOT NULL,
  ServiceID INT NOT NULL,
  PRIMARY KEY (ResourceID, ServiceID),
  FOREIGN KEY (ResourceID) REFERENCES _Resource(ResourceID),
  FOREIGN KEY (ServiceID) REFERENCES _Service(ServiceID)
);
GO

INSERT INTO _User
  ([Username], [Password])
VALUES('admin', 'admin');

INSERT INTO _Admin
  ([Username])
VALUES('admin');

INSERT INTO _User
  ([Username], [Password])
VALUES('user', 'user');

GO

-- Testing

INSERT INTO _Institution
  ([Name], [Email])
VALUES('Universidade da Beira Interior', 'university@email.com');

INSERT INTO _Laboratory
  ([Name], [Email], [InstitutionID])
VALUES('Laboratory', 'laboratory@email.com', '1');

INSERT INTO _Workgroup
  ([Name], [Email], [LaboratoryID])
VALUES('Workgroup', 'workgroup@email.com', '1');

INSERT INTO _Member
  ([Name], [Email])
VALUES('Member', 'member@email.com');

INSERT INTO _Resource
  ([Name], [Description])
VALUES('Resource 1', 'Generic resource description');

INSERT INTO _Resource_Allocation
  ([Quantity], [ResourceID], [LaboratoryID])
VALUES('6', '1', '1');

INSERT INTO _Service
  ([Name], [Description], [MemberID])
VALUES('Service 1', 'Generic service description', '1');

INSERT INTO _Service_Allocation
  ([ServiceID], [WorkgroupID])
VALUES('1', '1');

INSERT INTO _Dependency
  ([ResourceID], [ServiceID])
VALUES('1', '1');
