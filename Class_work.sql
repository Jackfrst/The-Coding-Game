create database vu21;


create table customer
(
Customer_Name varchar(25),
Customer_city varchar(25),
Customer_country varchar(25),

);

select * from customer;
drop table customer;

create table loan
(
Customer_Name varchar(25),
Loan_Number varchar(10),
Amount int
);

select *from loan;

Create Table student
(
Student_Name varchar(25),
CGPA varchar(5),
Session varchar(15)
);

select * from student;
drop table student;

insert into customer values
('Galvin','Athens','Greece'),
('Smith','Easter Island','Chile'),
('Jony','Athens','USA'),
('Ronald','Baltimore','USA');

insert into loan values

('Jony', 'L-174', '25000') ,
('Michel', 'p-857', '32000') ,
('Ronald', 'K-658', '12580') ,
('Rakesh', 'J-582', NUll) ;



insert into student values
('Sara','3.86','Summer-15'),
('Rakesh','3.24','Summer-16'),
('Wadud','3.69','Spring14'),
('Simran','3.55','FALL-13');

QUESTION2--

alter table customer add Time varchar(5);
update  customer set time='GMT-4'where customer_name='Galvin';
update  customer set time='GMT-6'where customer_name='Smith';
update  customer set time='GMT-7'where customer_name='Jony';
update  customer set time='GMT-7'where customer_name='Ronald';


Question3--
select customer_name from customer where customer_country='USA'
order by customer_name asc;

Question4--

select loan.customer_name ,Amount ,customer_country from customer inner join loan on  customer.customer_name=loan.customer_name
where customer_country='USA'
having (loan.amount)>avg(loan.amount);



Question 5--
select count(distinct(Customer_name)) from customer;

Question 6--

select count(distinct(Customer_name)) from customer
where customer_name is null;

select * from customer;


Question 7--

select max(Amount) as highest_salary,min(amount)as lowest_salary,avg(amount)as average_salary from loan;

Question 8--

select min(customer.customer_name) from customer inner join loan on customer.customer_name=loan.customer_name;

Question 9--

select student_name ,CGPA from student where CGPA between 3.50 and 3.99; 

Question 10--

Delete from student where CGPA= (select CGPA from student where CGPA<'3.50');

select CGPA from student where CGPA<'3.50';