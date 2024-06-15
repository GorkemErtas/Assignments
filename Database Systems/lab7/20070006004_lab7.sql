-- 1. display name, department no and hire date of employees
select ename, deptno, hiredate from emp;
-- 2. display department numbers and locations
select deptno, loc from dept;
-- 3. display all jobs
select job from emp;
-- 4. display all jobs without repetition
select distinct job from emp;
-- 5. display names of employees working as clerk
select ename from emp where job="clerk";
-- 6. display names, salaries of all employees working as clerk 
-- and whose salary is higher than 1000
select ename from emp where job="clerk" and sal>1000;
-- 7. display name and salary of employees including commission
select ename, sal+comm from emp where comm is not null;
-- 8. display name, salary and annual salary of employees 
-- using aliases NAME, SALARY and YEARLY 
select ename as NAME, sal as SALARY, 12*sal as YEARLY from emp;
-- 9. display names of employees beginning with "A"
select ename from emp where ename like "A%";
-- 10. display names of employees with second character "A"
select ename from emp where ename like "_A%";
-- 11. display jobs ending with "MAN"
select job from emp where job like "%MAN";
-- 12. display names and salaries of employees with
-- increasing order of salaries
select ename, sal from emp order by sal asc;
-- 13. display name and job of employees in 
-- decreasing order of salaries
select ename, sal from emp order by sal desc;
-- 14. Display names, jobs and salaries of employees 
-- which have salary between 2000 and 3000
select ename, job, sal from emp where sal between 2000 and 3000;
-- 15. Display the name, job and salary for all employees
--  whose salary is not equal to 1000, 3000, or 5000.
select ename, job, sal from emp where sal not in(1000,3000,5000);
