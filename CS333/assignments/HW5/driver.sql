-- Drop existing tables to avoid conflicts
DROP TABLE IF EXISTS Parent_Child;
DROP TABLE IF EXISTS Coaches;
DROP TABLE IF EXISTS Player;
DROP TABLE IF EXISTS Parent;
DROP TABLE IF EXISTS Coach;
DROP TABLE IF EXISTS Team;
DROP TABLE IF EXISTS Game;
DROP TABLE IF EXISTS Location;
DROP TABLE IF EXISTS Sport;
DROP TABLE IF EXISTS Relatives;

-- Create the Relatives table
CREATE TABLE Relatives (
    RelativeID INT AUTO_INCREMENT PRIMARY KEY,
    LastName VARCHAR(50)
);

-- Create the Parent table
CREATE TABLE Parent (
    ParentID INT AUTO_INCREMENT PRIMARY KEY,
    PhoneNumber VARCHAR(15),
    Email VARCHAR(50)
);

-- Create the Player table
CREATE TABLE Player (
    PlayerID INT AUTO_INCREMENT PRIMARY KEY,
    Age INT,
    TeamID VARCHAR(50)
);

-- Create the Sport table
CREATE TABLE Sport (
    SportID INT AUTO_INCREMENT PRIMARY KEY,
    SportName VARCHAR(50),
    Season VARCHAR(20)
);

-- Create the Coach table
CREATE TABLE Coach (
    CoachID INT AUTO_INCREMENT PRIMARY KEY,
    PhoneNumber VARCHAR(15),
    Name VARCHAR(50)
);

-- Create the Coaches association table
CREATE TABLE Coaches (
    SportID INT,
    CoachID INT,
    PRIMARY KEY (SportID, CoachID),
    FOREIGN KEY (SportID) REFERENCES Sport(SportID),
    FOREIGN KEY (CoachID) REFERENCES Coach(CoachID)
);

-- Create the Team table
CREATE TABLE Team (
    TeamID INT AUTO_INCREMENT PRIMARY KEY,
    TeamName VARCHAR(50),
    SportID INT,
    FOREIGN KEY (SportID) REFERENCES Sport(SportID)
);

-- Create the Location table
CREATE TABLE Location (
    LocationID INT AUTO_INCREMENT PRIMARY KEY,
    LocationName VARCHAR(50),
    Address VARCHAR(100)
);

-- Create the Game table
CREATE TABLE Game (
    GameID INT AUTO_INCREMENT PRIMARY KEY,
    GameTime TIME,
    GameDate DATE,
    LocationID INT,
    FOREIGN KEY (LocationID) REFERENCES Location(LocationID)
);

-- Create the Parent_Child association table
CREATE TABLE Parent_Child (
    ParentID INT,
    PlayerID INT,
    PRIMARY KEY (ParentID, PlayerID),
    FOREIGN KEY (ParentID) REFERENCES Parent(ParentID),
    FOREIGN KEY (PlayerID) REFERENCES Player(PlayerID)
);

-- Insert at least 10 rows into the Relatives table
INSERT INTO Relatives (LastName)
VALUES 
('Smith'),
('Johnson'),
('Williams'),
('Brown'),
('Jones'),
('Garcia'),
('Miller'),
('Davis'),
('Rodriguez'),
('Martinez');

INSERT INTO Player (Age, TeamID)
VALUES
(14, 1),
(18, 2),
(17, 3),
(12, 4),
(20, 5),
(18, 6),
(12, 7),
(13, 8),
(15, 9),
(10, 10);

-- Insert at least 10 rows into the Game table
INSERT INTO Parent (PhoneNumber, Email)
VALUES
('555-1234', 'parent1@example.com'),
('555-2345', 'parent2@example.com'),
('555-3456', 'parent3@example.com'),
('555-4567', 'parent4@example.com'),
('555-5678', 'parent5@example.com'),
('555-6789', 'parent6@example.com'),
('555-7890', 'parent7@example.com'),
('555-8901', 'parent8@example.com'),
('555-9012', 'parent9@example.com'),
('555-0123', 'parent10@example.com');



INSERT INTO Location (LocationName, Address)
VALUES
('Stadium A', '123 Main St'),
('Stadium B', '234 Oak St'),
('Arena C', '345 Pine St'),
('Field D', '456 Maple St'),
('Court E', '567 Elm St'),
('Pool F', '678 Cedar St'),
('Gym G', '789 Birch St'),
('Rink H', '890 Walnut St'),
('Track I', '901 Cherry St'),
('Hall J', '012 Spruce St');
-- Display all rows from the Relatives table
SELECT * FROM Relatives;

-- Display all rows from the Player table
SELECT * FROM Player;

-- Display all rows from the Location table
SELECT * FROM Location;

SHOW TABLES;
