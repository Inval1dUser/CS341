SELECT *
FROM People
;

SELECT *
FROM Shoes
;

SELECT Name
From People
;

SELECT ShoeType
FROM Shoes
;

SELECT Name, Color, ShoeType, ShoesSize
FROM People INNER JOIN Shoes ON People.PersonID = Shoes.Owner
;
