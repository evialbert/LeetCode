CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      select distinct Salary as getNthHighestSalary
      from (
          select Salary, dense_rank () over (order by Salary desc) as salaryRank
          from Employee
          ) as sub
      where salaryRank = N      
  );
END