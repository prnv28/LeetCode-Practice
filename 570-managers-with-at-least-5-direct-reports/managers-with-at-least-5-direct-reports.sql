SELECT name
FROM Employee
WHERE id IN(
    SELECT managerID
    FROM Employee
    GROUP BY managerID
    HAVING COUNT(*)>=5
);