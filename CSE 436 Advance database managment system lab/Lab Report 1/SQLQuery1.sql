create database labreport1;

-- Question 1
CREATE TABLE Customer(
	Customer_Name char(255),
	Customer_City char(255),
	Customer_Country char(255),
	AccountNo char(255),
);

INSERT INTO Customer(Customer_Name,Customer_City,Customer_Country,AccountNo) 
VALUES ('Galvin','Athens','Greece','AC452'),
('Smith','Easter Island','Chile','AC857'),
('Jony','Athens','USA','AC325'),
('Ronald','Baltimore','USA','AC665');

CREATE TABLE loan(
	Customer_Name char(255),
	Loan_number char(255),
	Amount int,
);

INSERT INTO loan(Customer_Name,Loan_number,Amount)
VALUES ('Jony','L-174',25000),
('Michel','P-857',32000),
('Ronald','K-658',12580),
('Rakesh','J-582',NULL);

CREATE TABLE Student(
	Student_Name char(255),
	CGPA float,
	Session char(255),
);

INSERT INTO Student(Student_Name,CGPA,Session)
VALUES ('Sara',3.86,'Summer15'),
('Rakesh',3.24,'Summer16'),
('Wadud',3.69,'Spring14'),
('Simran',3.55,'Fall13');

SELECT * FROM Customer;
SELECT * FROM loan;
SELECT * FROM Student;

-- Question 2
ALTER TABLE Customer ADD TimeZone char(255); 

UPDATE Customer
SET TimeZone = 'GMT-4'
WHERE Customer_Country = 'Greece';

UPDATE Customer
SET TimeZone = 'GMT-6'
WHERE Customer_Country = 'Chile';

UPDATE Customer
SET TimeZone = 'GMT-7'
WHERE Customer_Country = 'USA';

SELECT * FROM Customer;

-- Question 3
SELECT Customer_Name FROM Customer
WHERE Customer_Country = 'USA'
ORDER BY Customer_Name ASC;

-- Question 4
SELECT Customer_Name FROM loan
WHERE Amount < (SELECT AVG(Amount) FROM loan)
ORDER BY Customer_Name ASC;
-- Beacause loan has a inverse relation with asset

-- Question 5
SELECT Count(*) as Number_of_Column FROM Customer;

-- Question 6
SELECT Customer_Name FROM Customer
UNION
SELECT Customer_Name FROM loan;

-- Question 7
-- Showing Ammmount as Salary
SELECT MAX(Amount) AS Highest FROM loan;
SELECT MIN(Amount) AS Lowest FROM loan;
SELECT AVG(Amount) AS Average FROM loan;

-- Question 8
SELECT Customer_Name FROM Customer
INTERSECT
SELECT Customer_Name FROM loan;

-- Question 9
SELECT Student_name,CGPA FROM Student
WHERE CGPA BETWEEN 3.50 AND 3.99;

-- Question 10
DELETE FROM Student
WHERE CGPA IN (SELECT CGPA FROM Student WHERE CGPA < 3.5);
SELECT * FROM Student;
