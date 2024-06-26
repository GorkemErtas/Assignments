select upper(ename) as employee_name, lower(job) as job_title from emp;
select substr(ename,1,3) as first_three_characters from emp;
select concat(ename, '/', job) as EMPLOYEES from emp;
select ename, length(ename) from emp;
select emp.ename, dept.dname from emp join dept on emp.deptno = dept.deptno;
select dept.dname, emp.ename from dept left join emp on emp.deptno = dept.deptno;
select dname from dept left join emp on emp.deptno = dept.deptno where ename is null;
select ename, sal, salgrade.grade from emp join salgrade on emp.sal between salgrade.losal and salgrade.hisal;
select emp.ename, manager.ename as manager_name from emp join emp as manager on emp.mgr = manager.empno;
select empno, ename, job, sal, comm, emp.deptno, dname from emp join dept on emp.deptno = dept.deptno where emp.comm is not null;