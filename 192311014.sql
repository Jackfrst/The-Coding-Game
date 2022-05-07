create database lab6;
use lab6;

--Question 1--
create table Customer(
Customer_name varchar(10),
Customer_city varchar(20),
Customer_Country varchar(10),
);

Insert into Customer values
('Galvin','Athens','Greece'),
('Smith','EasterIsland','Chile'),
('Jony','Athens','USA'),
('Ronald','Baltimore','USA');

Create table Loan(
Customer_name varchar(10),
Loan_number varchar(10),
Amount int
);

Insert into Loan values
('Jony','L-174',25000),
('Michel','P-857',32000),
('Ronald','K-658',12580),
('Rakesh','J-582',NULL);

Create table Student(
Student_name Varchar(10),
CGPA float,
Session varchar(10)
);

Insert into Student Values
('Sara',3.86,'Summer15'),
('Rakesh',3.24,'Summer16'),
('Wadud',3.69,'Spring14'),
('Simran',3.55,'Fall13');

--Question 2--
Alter Table Customer Add Time varchar(10);

insert into Customer(Time) values
('GMT-4'),
('GMT-6'),
('GMT-7'),
('GMT-7');

Update Customer
Set Time = 'GMT-4'
Where Customer_name = 'Galvin';

Update Customer
Set Time = 'GMT-6'
Where Customer_name = 'Smith';

Update Customer
Set Time = 'GMT-7'
Where Customer_name = 'Jony';

Update Customer
Set Time = 'GMT-7'
Where Customer_name = 'Ronald';

--Question 3--
Select Customer_name from Customer
Where Customer_Country = 'USA'
Order by Customer_name;

--Question 4--
Select Customer.Customer_name 
from Customer full join Loan on Customer.Customer_name = Loan.Customer_name
Where Amount > (select avg(Amount) from Loan)
and Customer_Country = 'USA';

--Question 5--
select count(*)
from Customer;

--Question 6--
select count(*)
from Customer
where Customer_name = null or Customer_city = null or 
Customer_Country = null or TIME = null;

--Question 7--
Select Max(Amount)"Maximum",Min(Amount) "Minimum",Avg(Amount) "Avarage" from Loan;

--Question 8--
(Select Customer_name from Customer)
union
(select Customer_name from Loan)
order by Customer_name desc;


--Question 9--
Select Student_name , CGPA 
From Student 
Where CGPA between 3.50 AND 3.99;
 
--Question 10--
Delete from Student
where CGPA < 3.50;
