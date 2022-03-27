```sql
SELECT E.ID, E.person_name
FROM employee AS E, works NATURAL JOIN company AS T
WHERE E.city = T.city;
```

```sql
SELECT E.ID, E.person_name
FROM employee AS E, employee AS T, manages AS M
WhERE E.city = T.city AND E.street = T.street AND E.ID = M.ID AND T.ID = M.manager_id;
```

```sql
SELECT E.ID, E.person_name
FROM employee AS E, works AS W
WHERE E.ID = W.ID AND salary > (SELECT AVG(salary)
                                FROM works AS T
                                WHERE T.company_name = W.company_name);
```

```sql                  
SELECT company_name
FROM works
GROUP BY company_name
HAVING SUM(salary) <= ALL(SELECT SUM(salary)
                          FROM works
                          GROUP BY company_name);
```

```sql
SELECT distinct T.memb_no, T.name
FROM member NATURAL JOIN borrowed NATURAL JOIN book AS T
WHERE T.publisher = "McGraw-Hill"
```

```sql
WITH num_book AS (SELECT COUNT(distinct isbn)
                  FROM book
                  WHERE publisher = "McGraw-Hill"),
     num_borrow(memb_no, name, value) AS 
               (SELECT T.memb_no, T.name, COUNT(distinct T.isbn)
                FROM FROM member NATURAL JOIN borrowed NATURAL JOIN book AS T
                WHERE publisher = "McGraw-Hill")
SELECT num_borrow.memb_no, num_borrow.name
FROM num_borrow
WHERE num_borrow.value = num_book;
```
```sql
SELECT memb_no, name
FROM member NATURAL JOIN borrowed NATURAL JOIN book AS T
GROUP BY publisher
HAVING COUNT(distinct isbn) >= 5;
```
```sql
WITH num_borrow AS (SELECT COUNT(isbn)
                    FROM borrowed),
     num_member AS (SELECT COUNT(distinct memb_no)
                    FROM member)
SELECT num_borrow / num_member;
```

```sql
WITH num_borrow AS (SELECT COUNT(isbn)
                    FROM borrowed),
     num_member AS (SELECT COUNT(distinct memb_no)
                    FROM member)
SELECT num_borrow / num_member;

WITH dept_total(dept_name, value) AS (SELECT dept_name, SUM(salary)
                                      FROM instructor
                                      GROUP BY dept_name),
     dept_total_avg(value) AS (SELECT AVG(value)
                               FROM dept_total)
SELECT dept_name
FROM dept_total, dept_total_avg
WHERE dept_total.value >= dept_total_avg.value;
```

```sql
SELECT dept_name
FROM (SELECT SUM(salary)
      FROM instructor
      GROUP BY dept_name) AS dept_total(dept_name, value),
     (SELECT AVG(value)
      FROM dept_total) AS dept_total_avg(value)
WHERE dept_total.value >= dept_total_avg.value;
```
