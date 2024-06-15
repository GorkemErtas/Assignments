-- 1 Calculate the average salary for each department and display the department number and average salary.
SELECT e.DEPTNO, AVG(e.SAL) as AVG_SALARY
FROM EMP e
GROUP BY e.DEPTNO;
-- 2 Find the total salary and commission for each job title.
SELECT e.JOB, SUM(e.SAL) as TOTAL_SALARY, SUM(e.COMM) as TOTAL_COMMISSION
FROM EMP e
GROUP BY e.JOB;
-- 3 Display the total salary for each job title, but only include job titles with a total salary greater than 5000.
SELECT e.JOB, SUM(e.SAL) as TOTAL_SALARY
FROM EMP e
GROUP BY e.JOB
HAVING SUM(e.SAL) > 5000;
-- 4 List the departments with more than three employees and show the department number along with the employee count.
SELECT e.DEPTNO, COUNT(e.EMPNO) as NUM_EMPLOYEES
FROM EMP e
GROUP BY e.DEPTNO
HAVING COUNT(e.EMPNO) > 3;
-- 5 Show the average salary for each department where the average salary is greater than 2000, 
-- and display the department number along with the average salary.
SELECT e.DEPTNO, AVG(e.SAL) as AVG_SALARY
FROM EMP e
GROUP BY e.DEPTNO
HAVING AVG(e.SAL) > 2000;
-- 6 Display the total salary and employee count for each department and job title combination.
SELECT e.DEPTNO, e.JOB, SUM(e.SAL) as TOTAL_SALARY, COUNT(e.EMPNO) as NUM_EMPLOYEES
FROM EMP e
GROUP BY e.DEPTNO, e.JOB;
-- 7 Find the minimum and maximum salary for each job title and department combination, 
-- but only for those with a maximum salary greater than 2500.
SELECT e.DEPTNO, e.JOB, MIN(e.SAL) as MIN_SALARY, MAX(e.SAL) as MAX_SALARY
FROM EMP e
GROUP BY e.DEPTNO, e.JOB
HAVING MAX(e.SAL) > 2500;
-- 8 Retrieve the number of employees in each department with a salary greater than 1500 and 
-- show the department number along with the employee count.
SELECT e.DEPTNO, COUNT(e.EMPNO) as NUM_EMPLOYEES
FROM EMP e
WHERE e.SAL > 1500
GROUP BY e.DEPTNO;
-- 9 Display department names and the number of employees working in each department.
SELECT d.DNAME, COUNT(e.EMPNO) as NUM_EMPLOYEES
FROM DEPT d LEFT JOIN EMP e ON d.DEPTNO = e.DEPTNO
GROUP BY d.DNAME;
-- 10 Show the highest salary for each department where the department location is 'NEW YORK', 
-- and display the department number and highest salary.
SELECT e.DEPTNO, MAX(e.SAL) as HIGHEST_SALARY
FROM EMP e, DEPT d
WHERE e.DEPTNO = d.DEPTNO AND d.LOC = 'NEW YORK'
GROUP BY e.DEPTNO;