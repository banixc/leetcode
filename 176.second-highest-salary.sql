-- Write your MySQL query statement below
SELECT 
 MAX(Salary) SecondHighestSalary FROM Employee where salary not in (
SELECT MAX(Salary) max_salary FROM Employee)