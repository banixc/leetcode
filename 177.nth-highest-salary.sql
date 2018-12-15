CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
 SET N = N -1;
  RETURN (
     
      # Write your MySQL query statement below.
SELECT 
 MAX(Salary) FROM Employee where salary not in (select * FROM  (
SELECT Salary max_salary FROM Employee GROUP BY Salary ORDER BY Salary DESC LIMIT N) t  )
  );
END