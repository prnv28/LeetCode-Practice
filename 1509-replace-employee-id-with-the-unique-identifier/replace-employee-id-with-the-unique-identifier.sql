SELECT eu.unique_id, e.name
FROM Employees as e LEFT OUTER JOIN EmployeeUNI as eu
on e.id=eu.id;
