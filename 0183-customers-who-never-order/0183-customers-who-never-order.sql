# Write your MySQL query statement below
select c.name As Customers
from customers c
left join orders o
on c.id=o.customerId
where o.customerId is NULL;