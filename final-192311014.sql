create database Database_Final_Lab;
use Database_Final_Lab;

Create table Student(
	Id int,
	Name varchar(3)
);

--Question 1

Alter Table Student
Alter COLUMN Name varchar(15); 

Insert into Student values
(153,'Catherin'),
(151,'Atik'),
(152,'Belal');

ALTER TABLE Student
ALTER COLUMN Id INT NOT NULL;

ALTER TABLE Student 
ADD PRIMARY KEY (Id);

select * from Student;

--Question 2

select REPLACE('example@example.com','example','mi');

-------------

Create table Table1(
	Id int,
	Name varchar(15),
	Email varchar(25)
);

Insert into Table1 values
(1,'Tania','tania@gmail.com'),
(2,'Rasel','rasel@gmail.com');

Create table Table2(
	Email varchar(25),
	Name varchar(15),
	Id int
);

Insert into Table2 values
('siam@gmail.com','siam',1),
('rasel@gmail.com','Rasel',2);

--Question 3

(select ID,Name,Email from Table1)
union 
(select ID,Name,Email from Table2)
order by Name;

-------------

Alter Table Student
Add dept varchar(15);

update  Student 
set dept ='EEE'
where id = 151;

update  Student 
set dept ='CSE'
where id = 152;

update  Student 
set dept ='EEE'
where id = 153;

--Question 4


SELECT Dept,ID,COUNT(Id) as Number_Of_student FROM Student
WHERE ID<153 
GROUP BY Dept,name,id;














