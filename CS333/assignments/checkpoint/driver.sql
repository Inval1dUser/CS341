-- Drop tables if they exist in the correct order to handle foreign key constraints
DROP TABLE IF EXISTS Trade;
DROP TABLE IF EXISTS Investor;
DROP TABLE IF EXISTS Dividend_Payout;
DROP TABLE IF EXISTS Market_index;
DROP TABLE IF EXISTS Stock_Performance;
DROP TABLE IF EXISTS Stock;
DROP TABLE IF EXISTS Company;
DROP TABLE IF EXISTS Sector;

-- Create Company table
CREATE TABLE Company (
    Company_ID INT AUTO_INCREMENT PRIMARY KEY,
    Name VARCHAR(50),
    Sector VARCHAR(50),
    Industry VARCHAR(50),
    Address VARCHAR(50),
    Founded_Date DATE
);

-- Create Stock table
CREATE TABLE Stock (
    StockID INT AUTO_INCREMENT PRIMARY KEY,
    Ticker VARCHAR(5),
    Stock_Type VARCHAR(50),
    Currency VARCHAR(50),
    Company_ID INT,
    FOREIGN KEY (Company_ID) REFERENCES Company(Company_ID)
);

-- Create Stock_Performance table
CREATE TABLE Stock_Performance (
    StockID INT,
    Low INT,
    High INT,
    Close_Price DECIMAL(10, 2),
    Open_Price DECIMAL(10, 2),
    Market_Cap BIGINT,
    Volume_Traded INT,
    Date DATE,
    FOREIGN KEY (StockID) REFERENCES Stock(StockID)
);

-- Create Market_index table
CREATE TABLE Market_index (
    Index_ID INT AUTO_INCREMENT PRIMARY KEY,
    Description VARCHAR(255),
    Name VARCHAR(50)
);

-- Create Dividend_Payout table
CREATE TABLE Dividend_Payout (
    Dividend_ID INT AUTO_INCREMENT PRIMARY KEY,
    Dividend_Amount DECIMAL(10, 2),
    Payment_Date DATE,
    Declaration_Date DATE,
    StockID INT,
    FOREIGN KEY (StockID) REFERENCES Stock(StockID)
);

-- Create Sector table
CREATE TABLE Sector (
    Sector_ID INT AUTO_INCREMENT PRIMARY KEY,
    Description VARCHAR(255),
    Name VARCHAR(50)
);

-- Create Investor table
CREATE TABLE Investor (
    Investor_ID INT AUTO_INCREMENT PRIMARY KEY,
    Phone_Number VARCHAR(50),
    Email VARCHAR(100),
    Name VARCHAR(100),
    Investor_Type VARCHAR(15)
);

-- Create Trade table
CREATE TABLE Trade (
    Trade_ID VARCHAR(50) PRIMARY KEY,
    Trade_Date DATE,
    Trade_Type VARCHAR(10),
    Quantity INT,
    Price_Paid DECIMAL(10, 2),
    Market_Value DECIMAL(15, 2),
    StockID INT,
    InvestorID INT,
    FOREIGN KEY (StockID) REFERENCES Stock(StockID),
    FOREIGN KEY (InvestorID) REFERENCES Investor(Investor_ID)
);

-- Insert data into Company table
INSERT INTO Company (Name, Sector, Industry, Address, Founded_Date) VALUES
('Apple Inc.', 'Technology', 'Consumer Electronics', 'Cupertino, CA', '1976-04-01'),
('Microsoft Corp', 'Technology', 'Software Infrastructure', 'Redmond, WA', '1975-04-04'),
('Amazon.com Inc.', 'Consumer Discretionary', 'Internet & Direct Marketing', 'Seattle, WA', '1994-07-05'),
('Alphabet Inc.', 'Communication Services', 'Interactive Media', 'Mountain View, CA', '2015-10-02'),
('Tesla Inc.', 'Consumer Discretionary', 'Automotive', 'Palo Alto, CA', '2003-07-01'),
('Facebook Inc.', 'Communication Services', 'Interactive Media', 'Menlo Park, CA', '2004-02-04'),
('Berkshire Hathaway', 'Financials', 'Diversified Financials', 'Omaha, NE', '1839-01-01'),
('Johnson & Johnson', 'Healthcare', 'Pharmaceuticals', 'New Brunswick, NJ', '1886-01-01');

-- Insert data into Stock table
INSERT INTO Stock (Ticker, Stock_Type, Currency, Company_ID) VALUES
('AAPL', 'Common Stock', 'USD', 1),
('MSFT', 'Common Stock', 'USD', 2),
('AMZN', 'Common Stock', 'USD', 3),
('GOOGL', 'Common Stock', 'USD', 4),
('TSLA', 'Common Stock', 'USD', 5),
('META', 'Common Stock', 'USD', 6),
('BRK.A', 'Common Stock', 'USD', 7),
('JNJ', 'Common Stock', 'USD', 8);

-- Insert data into Stock_Performance table
INSERT INTO Stock_Performance (StockID, Low, High, Close_Price, Open_Price, Market_Cap, Volume_Traded, Date) VALUES
(1, 135, 150, 147.52, 146.50, 2500000000, 100000000, '2024-11-10'),
(2, 290, 310, 305.20, 298.00, 2300000000, 80000000, '2024-11-10'),
(3, 1350, 1400, 1378.99, 1362.10, 1700000000, 60000000, '2024-11-10'),
(4, 2780, 2820, 2801.01, 2790.00, 1800000000, 40000000, '2024-11-10'),
(5, 1200, 1240, 1220.50, 1215.00, 750000000, 30000000, '2024-11-10'),
(6, 300, 310, 307.89, 305.00, 800000000, 50000000, '2024-11-10'),
(7, 500000, 510000, 505000.00, 502000.00, 600000000, 200000, '2024-11-10'),
(8, 160, 170, 167.35, 165.00, 400000000, 25000000, '2024-11-10');

-- Insert data into Market_index table
INSERT INTO Market_index (Description, Name) VALUES
('Measures the performance of 500 large companies listed on stock exchanges in the United States', 'S&P 500'),
('Tracks the 30 large, publicly-owned companies in the United States', 'Dow Jones Industrial Average'),
('Tracks 100 of the largest domestic and international non-financial companies listed on the Nasdaq Stock Market', 'Nasdaq-100'),
('Measures the performance of all the stocks listed on the New York Stock Exchange', 'NYSE Composite'),
('Tracks the largest publicly traded companies in Japan', 'Nikkei 225'),
('Tracks the performance of large companies across 23 developed countries', 'MSCI World'),
('Tracks the performance of the largest companies in the Eurozone', 'Euro Stoxx 50'),
('An index of the largest companies in Germany', 'DAX 30');

-- Insert data into Dividend_Payout table
INSERT INTO Dividend_Payout (Dividend_Amount, Payment_Date, Declaration_Date, StockID) VALUES
(1.67, '2024-12-10', '2024-10-30', 1),
(2.30, '2024-11-15', '2024-10-10', 2),
(1.50, '2024-11-20', '2024-10-15', 3),
(0.55, '2024-12-01', '2024-10-22', 4),
(0.75, '2024-12-05', '2024-10-25', 5),
(2.00, '2024-12-10', '2024-10-30', 6),
(0.85, '2024-12-12', '2024-11-01', 7),
(1.30, '2024-12-15', '2024-11-05', 8);

-- Insert data into Sector table
INSERT INTO Sector (Description, Name) VALUES
('Includes companies that produce software, hardware, and semiconductor equipment', 'Technology'),
('Companies focused on manufacturing, distributing, and providing healthcare-related products and services', 'Healthcare'),
('Companies providing financial services such as banks, investment funds, and insurance companies', 'Financials'),
('Companies involved in energy production, including oil, gas, and renewable energy', 'Energy'),
('Companies focused on real estate development, management, and REITs', 'Real Estate'),
('Companies that manufacture and sell automobiles and automotive components', 'Automotive'),
('Companies involved in retail and consumer services', 'Consumer Discretionary'),
('Companies focused on telecommunications and media services', 'Communication Services');

-- Insert data into Investor table
INSERT INTO Investor (Phone_Number, Email, Name, Investor_Type) VALUES
('123-456-7890', 'investor1@example.com', 'Alice Johnson', 'Individual'),
('234-567-8901', 'investor2@example.com', 'Bob Smith', 'Institutional'),
('345-678-9012', 'investor3@example.com', 'Charlie Brown', 'Individual'),
('456-789-0123', 'investor4@example.com', 'Daisy Lee', 'Institutional'),
('567-890-1234', 'investor5@example.com', 'Edward Miller', 'Individual'),
('678-901-2345', 'investor6@example.com', 'Fiona Adams', 'Institutional'),
('789-012-3456', 'investor7@example.com', 'George Harris', 'Individual'),
('890-123-4567', 'investor8@example.com', 'Hannah White', 'Institutional');

-- Insert data into Trade table
INSERT INTO Trade (Trade_ID, Trade_Date, Trade_Type, Quantity, Price_Paid, Market_Value, StockID, InvestorID) VALUES
('23423e3', '2024-11-01', 'BUY', 100, 150.50, 15050.00, 1, 1),
('3324d3d', '2024-11-02', 'SELL', 50, 152.00, 7600.00, 2, 2),
('94029ei', '2024-11-03', 'BUY', 200, 134.25, 26850.00, 3, 3),
('40di302', '2024-11-04', 'SELL', 75, 2800.00, 210000.00, 4, 4),
('23940di', '2024-11-05', 'BUY', 30, 1200.00, 36000.00, 5, 5),
('492u933', '2024-11-06', 'SELL', 120, 305.00, 36600.00, 6, 6),
('392429e', '2024-11-07', 'BUY', 40, 500000.00, 20000000.00, 7, 7),
('4034920', '2024-11-08', 'SELL', 150, 167.35, 25102.50, 8, 8);

-- Select data from tables
SELECT * FROM Company;
SELECT * FROM Stock;
SELECT * FROM Stock_Performance;
SELECT * FROM Dividend_Payout;
SELECT * FROM Market_index;
SELECT * FROM Sector;
SELECT * FROM Investor;
SELECT * FROM Trade;

-- Show all tables in the database
SHOW TABLES;
