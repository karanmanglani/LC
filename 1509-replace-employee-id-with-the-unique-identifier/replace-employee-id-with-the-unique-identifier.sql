# Write your MySQL query statement below
-- SELECT 
--     (SELECT eu.unique_id FROM EmployeeUNI eu WHERE eu.id = ep.id) AS unique_id,
--     ep.name
-- FROM Employees ep;


# Write your MySQL query statement below
SELECT B.UNIQUE_ID, A.NAME
FROM EMPLOYEES A
LEFT JOIN EMPLOYEEUNI B
ON A.ID = B.ID;