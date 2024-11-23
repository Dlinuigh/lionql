CREATE DATABASE test_db;
USE test_db;
CREATE TABLE departments (
    department_id INT PRIMARY KEY AUTO_INCREMENT,
    department_name VARCHAR(100) NOT NULL
);
CREATE TABLE employees (
    employee_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    birth_date DATE,
    hire_date DATE,
    salary DECIMAL(10, 2),
    department_id INT,
    FOREIGN KEY (department_id) REFERENCES departments(department_id)
);
INSERT INTO departments (department_name)
VALUES ('HR'), ('IT'), ('Sales'), ('Marketing');
INSERT INTO employees (first_name, last_name, birth_date, hire_date, salary, department_id)
VALUES 
('John', 'Doe', '1985-02-15', '2015-06-01', 55000, 1),
('Jane', 'Smith', '1990-07-25', '2018-09-15', 65000, 2),
('Alice', 'Johnson', '1992-10-10', '2020-01-05', 45000, 3),
('Bob', 'Brown', '1980-03-05', '2012-05-20', 75000, 2),
('Charlie', 'Davis', '1988-12-30', '2016-07-15', 50000, 4);
SELECT * FROM employees;
SELECT e.first_name, e.last_name, e.salary, d.department_name
FROM employees e
JOIN departments d ON e.department_id = d.department_id
WHERE d.department_name = 'IT';
SELECT first_name, last_name, salary
FROM employees
WHERE salary > 50000;
SELECT d.department_name, AVG(e.salary) AS avg_salary
FROM employees e
JOIN departments d ON e.department_id = d.department_id
GROUP BY d.department_name;
SELECT first_name, last_name, hire_date
FROM employees
WHERE hire_date > '2015-01-01';
UPDATE employees
SET salary = salary * 1.1
WHERE first_name = 'Alice' AND last_name = 'Johnson';
UPDATE employees
SET department_id = (SELECT department_id FROM departments WHERE department_name = 'HR')
WHERE first_name = 'Charlie' AND last_name = 'Davis';
DELETE FROM employees WHERE first_name = 'Charlie' AND last_name = 'Davis';
DELETE FROM employees WHERE salary < 50000;
CREATE VIEW department_employee_view AS
SELECT e.first_name, e.last_name, e.salary, d.department_name
FROM employees e
JOIN departments d ON e.department_id = d.department_id;
SELECT * FROM department_employee_view;
CREATE INDEX idx_salary ON employees (salary);
SELECT first_name, last_name, salary
FROM employees
WHERE salary > 50000;
DELIMITER //
CREATE PROCEDURE GetEmployeesByDepartment (IN dept_name VARCHAR(100))
BEGIN
    SELECT e.first_name, e.last_name, e.salary
    FROM employees e
    JOIN departments d ON e.department_id = d.department_id
    WHERE d.department_name = dept_name;
END //
DELIMITER ;
CALL GetEmployeesByDepartment('IT');
CREATE TRIGGER employee_after_insert
AFTER INSERT ON employees
FOR EACH ROW
BEGIN
    INSERT INTO employee_logs (action, employee_id, action_time)
    VALUES ('INSERT', NEW.employee_id, NOW());
END;
DROP VIEW department_employee_view;
DROP TABLE employees;
DROP TABLE departments;
