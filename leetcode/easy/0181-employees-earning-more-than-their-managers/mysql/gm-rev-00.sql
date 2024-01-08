# Runtime: 1036ms
# Memory: N/A
SELECT emp.name AS Employee
FROM Employee AS emp JOIN Employee AS man ON emp.managerId = man.id
WHERE emp.salary > man.salary;
