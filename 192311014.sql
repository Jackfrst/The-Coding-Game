--Question 1
create table student(
	id int,
	name varchar(20),
	cgpa float,
	session varchar(20)
);

--Question 2
insert into student values
(1, 'Atik',3.56 , 'Fall-20'), 
(2, 'Benny',3.84 , 'Spring-15'), 
(3, 'Delwar',3.15 , 'Fall-20'), 
(4, 'Wasim',2.88 , 'Fall-20'); 


--Question 3
Update student
set cgpa = 3.38
where id =1


--Question 4
Delete from student
where name = 'Wasim'


--Question 5
insert into student values
(4, 'Emon',3.25 , 'Summer-20'); 
