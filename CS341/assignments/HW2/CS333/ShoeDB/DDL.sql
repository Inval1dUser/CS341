CREATE TABLE People
(
   PersonID INT NOT NULL,
   Name CHAR(20) NOT NULL,
   Age INT NOT NULL,
   Height INT NOT NULL,
   PRIMARY KEY (PersonID)
);
CREATE TABLE Shoes
(
ShoeID INT NOT NULL,
ShoeSize INT NOT NULL, 
Color CHAR(20) NOT NULL,
Brand CHAR(20) NOT NULL,
ShoeType CHAR(20) NOT NULL,
Owner INT NOT NULL,
PRIMARY KEY (ShoeID),
FOREIGN KEY (Owner) REFERENCES People(PersonID)
);

INSERT INTO Students VALUES (1, 'Ben', 'Soph', 'CS');
INSERT INTO Students VALUES (2, 'George', 'Soph', 'CS');

INSERT INTO Assignments VALUES (1, 'HW', 'CS341', 'Wed', 1, 30);
INSERT INTO Assignments VALUES (2, 'HW', 'CS341', 'Wed', 2, 110);
INSERT INTO Assignments VALUES (3, 'HW', 'CS252', 'Fri', 2, 20);
INSERT INTO Assignments VALUES (4, 'HW', 'CS333', 'Fri', 2, 80);

 

SELECT *
FROM People
;

SELECT *
FROM Shoes
;

SELECT Name
FROM People
;

SELECT ShoeType
FROM Shoes
;

SELECT Name, Color, ShoeType, ShoeSize
FROM People INNER JOIN Shoes ON People.PersonID = Shoes.Owner