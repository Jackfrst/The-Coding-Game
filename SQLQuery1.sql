create database lab;
use lab;

--Question 1
create table The_customer_table (
customer_id varchar(12) NOT Null,
customer_name varchar(10),
customer_street varchar(20),
customer_city varchar(10),
PRIMARY KEY (customer_id)
);

insert into The_customer_table values
('192-83-7465','Johnson','12 Alma St.','Palo Alto'),
('019-28-3746','Smith','4 North St.','Rye'),
('677-89-9011','Hayes','3 Main St.','Harrison'),
('182-73-6091','Turner','123 Putnam Ave.','Stamford'),
('321-12-3123','Jones','100 Main St.','Harrison'),
('336-66-9999','Lindsay','175 Park Ave.','Pittsfield'),
('019-28-3747','Smith','72 North St.','Rye');


create table The_account_table(
account_number varchar(5) NOT NULL,
balance int,
PRIMARY KEY(account_number)
);

insert into The_account_table values
('A-101',500),
('A-215',700),
('A-102',400),
('A-305',350),
('A-201',900),
('A-217',750),
('A-222',700);


create table The_depositor_table(
customer_id varchar(12),
account_number varchar(5),
FOREIGN KEY (account_number) REFERENCES The_account_table(account_number)
);

insert into The_depositor_table values
('192-83-7465','A-101'),
('192-83-7465','A-201'),
('019-28-3746','A-215'),
('677-89-9011','A-102'),
('182-73-6091','A-305'),
('321-12-3123','A-217'),
('336-66-9999','A-222'),
('019-28-3746','A-201');


--Question 2
select customer_name,customer_street,customer_city from The_customer_table
where customer_city = 'Harrison';

--Question 3
select customer_name,customer_street,customer_city from The_customer_table
where customer_street LIKE '%Ave%';

--Question 4

select customer_name,customer_street from The_customer_table
where customer_name LIKE Char(72)+'%';

--Question 5
select customer_name,customer_city from The_customer_table
where customer_name LIKE 'T%';

--Question 6
select customer_name from The_customer_table
where SUBSTRING(customer_street,3,6) = 'North';


/*select * from The_customer_table;
drop table The_customer_table;

select * from The_account_table;
drop table The_account_table;

select * from The_depositor_table;
drop table The_account_table;*/