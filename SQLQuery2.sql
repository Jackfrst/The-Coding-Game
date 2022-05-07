create table Employee
(
ID int,
Name varchar(20),
Salary int,
DepartmentID int
);

insert into Employee values
(1,'Ashik',5000,1),
(2,'Bisal',8000,1),
(3,'Diner',3000,2),
(4,'Ali',5000,1),
(5,'Roy',8000,1),
(6,'Tim',3000,3);

insert into Employee values
(7,'Ria',7000,null);

select * from Employee;

select * from Employee
where Salary=5000;

select * from Employee
where Department='Sales';

create table Department
(
DepartmentID int,
DepartmentName varchar(20),
Location varchar(20)
);

insert into Department values
(1,'Sales','Dhaka'),
(2,'Transport','Natore'),
(3,'IT','Rajshahi');


select * from Employee;
select * from Department;

select * from Employee
where Salary>5000;

select * from Employee
where Salary>=5000;

select DepartmentName, Location from Department
where DepartmentName= 'Sales';

select DepartmentID from Department
where DepartmentName='Transport';


select ID, Name from Employee
where DepartmentID=(select DepartmentID from Department
where DepartmentName='Transport');

update Employee
set DepartmentID=2
where ID=6;

select ID,Name,DepartmentName from Employee
right join Department
on Employee.DepartmentID= Department.DepartmentID;

select ID,Name,DepartmentName from Department
right join Employee
on Employee.DepartmentID= Department.DepartmentID;




