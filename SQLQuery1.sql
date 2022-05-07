create database  lab5;
use lab5;

create table Teacher (
TID int Not Null, 
FirstName varchar(10),
LastName varchar(10),
Dept varchar(10),
Age int ,
Salary int,
primary key (TID)); 

insert into Teacher values
(1,'Meraj','Ali','CSE',25,30000),
(2,'Sanjir','Shishir','CSE',24,31000),
(3,'Moshiur','Rahman','EEE',23,29000),
(4,'Symun','Islam','EEE',24,36000),
(5,'Sazzed','Islam','ECE',22,28000),
(6,'Samia','Sultana','CSE',26,38000),
(7,'Arifa','Ferdoushi','ECE',30,50000);

create table Student (
id int Not Null, 
name varchar(10),
dept varchar(10),
Semester int ,
CourseCode varchar(10),
Age int ,
CreditTaken int,
TeacherID int,
primary key (id),
FOREIGN KEY (TeacherID) REFERENCES Teacher(TID)
); 

insert into Student values
(1,'Noor','CSE',7,'CSE-313',22,3,1),
(2,'Arko','EEE',6,'EEE-231',21,4,7),
(3,'Ratul','ECE',8,'ECE-341',23,3,5),
(4,'Toru','EEE',5,'EEE-221',20,4,4),
(5,'Rashmi','CSE',7,'CSE-314',23,1,1),
(6,'Sanjida','ECE',6,'ECE-231',22,3,7),
(7,'Mamun','CSE',7,'ECE-316',24,4,Null);

--Question 1--
Select  FirstName,
LastName,
Teacher.Dept,
Salary,
Semester,
CourseCode,
CreditTaken from Teacher inner join Student on Teacher.TID = Student.TeacherID
where CreditTaken > 1;


--Question 2--
Select Count(Student.id) as NumberofStudent,
Teacher.FirstName,
Sum(CreditTaken) as TotalCredit,
Salary,
Teacher.Dept
from Teacher join Student 
on  Teacher.TID = Student.TeacherID 
Group By FirstName,salary,Teacher.Dept;

--Question 3--
Select Teacher.FirstName, 
Teacher.LastName, 
Teacher.Dept, 
Teacher.Salary,
Student.CourseCode,
Sum(CreditTaken) as TotalCredit
from Teacher
Left Join Student on Student.TeacherID = Teacher.TID
where Teacher.Salary between 30000 and 40000
Group by FirstName,LastName,Teacher.Dept,Salary,CourseCode;

-- Question 4 --
Select Teacher.FirstName,
Teacher.Dept,
Teacher.Salary,
Student.Semester,
Student.CourseCode,
Student.CreditTaken
from Teacher
Left Join Student on Student.TeacherID = Teacher.TID
Order By Teacher.Dept, FirstName;

-- Question 5 --
Select Teacher.FirstName,
Teacher.Dept,
Teacher.Salary,
Student.Semester,
Student.CourseCode,
Student.CreditTaken
from Teacher
Join Student on Student.TeacherID = Teacher.TID
Order By Student.Semester;

-- Question 6 --
Select Teacher.FirstName, 
Teacher.LastName, 
Teacher.Dept, 
Teacher.Salary,
Student.CourseCode,
Student.CreditTaken
from Teacher
Join Student on Student.TeacherID = Teacher.TID
Order BY CreditTaken desc;

-- Question 7 --
Delete from Student
Where name = 'Arko' and Semester = '6';

-- Question 8 --
Delete from Teacher
Where FirstName = 'Faruk'

-- Question 9 --
select max(salary) as totalSalary, FirstName, sum(CreditTaken) as totalCredit, Teacher.Dept
from Teacher inner join Student
on Teacher.TID = Student.TeacherID
where CourseCode like '%31'
group by FirstName, Teacher.Dept;

select * from Student;
select Teacher.FirstName from Teacher;

drop table Student;
drop table Teacher;