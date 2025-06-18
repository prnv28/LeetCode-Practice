SELECT T1.name
FROM (SELECT A.id, A.name, COUNT(B.managerId) as cnt
FROM Employee A
JOIN Employee B
ON A.id=B.managerID 
GROUP BY A.id) AS T1
WHERE T1.cnt>=5;