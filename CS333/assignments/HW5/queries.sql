SELECT Parent.ParentID, Parent.PhoneNumber, Parent.Email FROM Parent 
JOIN Parent_Child ON Parent_Child.ParentID = Parent.ParentID
WHERE Parent_Child.PlayerID = 4;

SELECT Game.GameTime, Game.GameDate FROM Game
JOIN Location ON Game.LocationID = Location.LocationID
WHERE LocationName = "Sellick Bowl";

SELECT Coach.Name, Sport.SportName FROM Coach
JOIN Coach ON Coach.CoachID = Coaches.CoachID
JOIN Coach ON Coach.SportID = Sport.SportID;

SELECT AVG(Age) FROM Player;

SELECT COUNT(Player.PlayerID), Sport.SportName AS TotalPlayers FROM Sport
JOIN Team ON Team.SportID = Sport.SportID
JOIN Player ON Player.TeamID = Team.TeamID
GROUP BY SportName;

SELECT Parent.ParentID, COUNT(Parent_Child.ParentID) FROM Parent
JOIN Parent_Child ON Parent.ParentID = Parent_Child.ParentID
GROUP BY Parent.ParentID
HAVING COUNT(Parent_Child.PlayerID > 1);

SELECT SportName FROM Sport
WHERE Season = 'Winter';

SELECT Team.TeamName, Sport.SportName FROM Team
JOIN Sport ON Team.SportID = Sport.SportID;

SELECT Age, PlayerID FROM Player
WHERE Age > 18;

SELECT COUNT(Player.PlayerID), Team.TeamName FROM Player
LEFT JOIN Player ON Team.TeamID = Player.TeamID
GROUP BY Team.TeamName;


CREATE TRIGGER validate_game_time
BEFORE INSERT ON Game
FOR EACH ROW
BEGIN
    -- Check if the game time is outside allowed hours
    IF NEW.GameTime < '08:00:00' OR NEW.GameTime > '22:00:00' THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Game time must be between 08:00:00 and 22:00:00';
    END IF;
END$$

