CREATE TABLE Supplier
(
  SNUM CHAR(5) NOT NULL,
  SNAME CHAR(20) NOT NULL,
  STATUS INT NOT NULL,
  CITY CHAR(15) NOT NULL,
  PRIMARY KEY (SNUM)
);

CREATE TABLE Parts
(
  PNUM CHAR(6) NOT NULL,
  PNAME CHAR(20) NOT NULL,
  COLOR CHAR(6) NOT NULL,
  WEIGHT INT NOT NULL,
  CITY CHAR(15) NOT NULL,
  PRIMARY KEY (PNUM)
);

CREATE TABLE Shipment
( 
  SNUM CHAR(5) NOT NULL,
  PNUM CHAR(6) NOT NULL,
  Qty INT NOT NULL,
  PRIMARY KEY (SNUM, PNUM),
  FOREIGN KEY (SNUM) REFERENCES Supplier(SNUM),
  FOREIGN KEY (PNUM) REFERENCES Parts(PNUM)
);
INSERT INTO Supplier VALUES ('S1', 'Smith', 20, 'London');
INSERT INTO Supplier VALUES ('S2', 'Jones', 10, 'Paris');
INSERT INTO Supplier VALUES ('S3', 'Blake', 30, 'Paris');
INSERT INTO Supplier VALUES ('S4', 'Clark', 20, 'London');
INSERT INTO Supplier VALUES ('S5', 'Adams', 30, 'Athens');

 
INSERT INTO Parts VALUES ('P1', 'Nut', 'Red', 12, 'London');
INSERT INTO Parts VALUES ('P2', 'Bolt', 'Green', 17, 'Paris');
INSERT INTO Parts VALUES ('P3', 'Screw', 'Blue', 17, 'Rome');
INSERT INTO Parts VALUES ('P4', 'Screw', 'Red', 14, 'London');
INSERT INTO Parts VALUES ('P5', 'Cam', 'Blue', 12, 'Paris');
INSERT INTO Parts VALUES ('P6', 'Cog', 'Red', 19, 'London');

 
INSERT INTO Shipment VALUES ('S1', 'P1', 300);
INSERT INTO Shipment VALUES ('S1', 'P2', 200);
INSERT INTO Shipment VALUES ('S1', 'P3', 400);
INSERT INTO Shipment VALUES ('S1', 'P4', 200);
INSERT INTO Shipment VALUES ('S1', 'P5', 100);
INSERT INTO Shipment VALUES ('S1', 'P6', 300);
INSERT INTO Shipment VALUES ('S2', 'P1', 300);
INSERT INTO Shipment VALUES ('S2', 'P2', 400);
INSERT INTO Shipment VALUES ('S3', 'P2', 200);
INSERT INTO Shipment VALUES ('S4', 'P2', 200);
INSERT INTO Shipment VALUES ('S4', 'P4', 300);
INSERT INTO Shipment VALUES ('S4', 'P5', 400);