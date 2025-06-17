SELECT B.id 
FROM Weather as A JOIN Weather as B
ON DATE_ADD(A.recordDate, INTERVAL 1 DAY) = DATE(B.recordDate)
WHERE A.temperature<B.temperature;
-- WHERE DATEDIFF(B.recordDate,A.recordDate)=1 AND a.temperature<B.temperature;
