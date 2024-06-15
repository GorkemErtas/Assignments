-- Use this template for your se2222 project
-- Before submission be sure that your file is named like [your_ID].sql
-- You will get minus 20% of total score for each day after due date
-- Name:...
-- ID:...

-- 1. Create and use a schema for your project named SE2222_[your_ID]
CREATE SCHEMA SE2222_123456789;
USE SE2222_123456789;
-- 1. Definitions:
-- All table definitions of your project including any constraints
-- Before each table creation give a short explanation of the table

-- Ex:
-- A1 table holds A values
CREATE TABLE A1(
A INT PRIMARY KEY);
-- 2. Insertions(Data manipulation):
-- For each table, add enough number of rows to make your queries in step three to produce meaningful result sets.

-- Ex:
INSERT INTO A1(A) VALUES(1);
-- 3. Queries:
-- Write 5 queries with explanations 
-- Write 5 queries. Your queries should do a task that is meaningful in your selected context (project topic). 
-- At least one that joins two or more tables
-- At least one that include group functions
-- At least one with one or more sub-query(es)
-- At least one update
-- At least one delete
-- At least one include arithmetic functions
-- At least one uses alias

-- Ex:
-- Finding all records in A1 table
SELECT * FROM A1;