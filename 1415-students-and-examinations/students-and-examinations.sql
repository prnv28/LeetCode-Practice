SELECT
    S.student_id
    ,S.student_name
    ,SU.subject_name
    ,COUNT(E.student_id) attended_exams
FROM Students S
JOIN Subjects SU 
LEFT JOIN Examinations E
ON E.student_id = S.student_id
AND E.subject_name = SU.subject_name
GROUP BY S.student_id,SU.subject_name
ORDER BY S.student_id, SU.subject_name
