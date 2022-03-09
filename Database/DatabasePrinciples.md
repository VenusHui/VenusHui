> writer: VenusHui
>  
> time: 2022.02.22
>  
> last edit: 2022.03.03
>
> Reference :《Database System Concepts》 Seventh Edition

## Database Principles and Applications

### Intrduction

#### 1.1 Database System Applications

#### 1.2 Purpose(用途) of Database Systems

* typical file-processing system
  + data redundancy and inconsistency
  + difficult to access data
  + data isolation
  + integrity(完整性) problems
  + atomicity problems
  + concurrent-access anomalies(异常)
  + multiple
  + security problems

#### 1.3 View of Data

* describe data
  + data
  + data relationships
  + data semantics(语义)
  + consistency constraints

* data models
  + Relational Model
    - form of tables, rows & columns
    - an example of record-based model
  + Entity-Relationship(E-R) Model
    - use the a collection of objects(*entities*) objects such as graphic symbols to do database design
  + Semi-srtuctured Data Model
    - every data item of a particular type must have the same set of attributes
    - eg. JSON & XML
  + Object-Based Data Model
    - integrate(集成) the object-oriented concept into relational databases
  
* data abstration
  + physical level
  + logical level: physical data independence
  + view level

* instances(实例) and schemas(模式)
  + schema like the value type while instance like the specific value compared with the programming languages
  + according the levels of abstraction, database have several schemas
    - physical schema: physical level, hidden beneath the logical schema and can be changed without affecting the logical schema
    - logical schema(the most important): logical level
    - subschemas: view level, describe different views of the database

#### 1.4 Database Languages

* data-definitioin language(DDL)
  + specify the database schema
  + domain(域) constraints
  + referential integrity
  + authorization

* data-manipulation language(DML)
  + express the database queries and updates
    - procedural DMLs: what data are needed and how to get them
    - declarative DMLs: only what data are needed

* the DDl and DML simply form parts of a database language such as SQL

----------------------------------------------

### Introduction to the Relational Model

#### 2.1 Structure of Relational Databases

* a relational database consist of a collection of tables
  + a row in a table represents a relationship among a set of values
  + a table is a collection of such relationships
----------------------------------------------
* Processing
  + parasing and translation
  + Optimization
  + Evaluation

* relation schema: a set of attributes

* tuple(元组) such as one row of the two elements table

* attribute values: atomical

* relations are totally unordered

* arbitrary(任意的)

* Keys
  + a subset of R(Relation)
  + superkey
  + candidate key: K is minimal(no subset or the subset of itself is also a superkey, not the num of attributes up to this)
  + primaray key: choose one(or more) candidate key
  + foreign key:
    - referencing relation
    - referenced relation
* join operation "$\times$"
  + cartesian product(笛卡尔积)
  + predicate(谓词): the condition of operation

* union operation
  + the same arity
  + compatible(兼容的)

* set-intersection operation
  + the same arity
  + compatible

* set-diiference operation
  + the same arity
  + compatible

* the assignment operation
  + <-

* rename operation

### Introduction to SQL(structured query language)

#### DDL

#### domain types in SQL

* char(n): fixed length n

* varchar(n): max length n

* int

* numeric(p, d): pn.dn

* real, double precision

* float

#### create table

```sql
create table tableName(
  attributeName1 dataType1,
  attributeName2 dataType2 not null,
  primary key(attrubuteName1),
  foreign key(attributeName2) references anotherTable
);
```

#### update to tables

```sql
insert into tableName values ();
delete from tableName -- only delete the data tuples
drop table tableName -- the total structure of the table
alter table tableName add attributeName domainOfAttribute
alter table tableName drop attributeName
```

#### basic query structures

```sql
select attributes
from relations
where predicateName -- optional

select distinct attributes -- the distinct tuple
from relations(tableName)

select all attributes -- keep the duplicated elements, by default choice
from relations

select * -- * refers to select all attributes
from relations

select 'value' -- no 'from', result is a table with ine column and a single row with 'value'

select 'value' as tableName -- name the result table

select 'value'
from relations

```

* SQL names are case insensitive
* relational algebra do not allow duplication but SQL allows
* select clause can contain arithmetic expressions
* I think select clause returns a particular table
* the where clause: the additonal comparisions, use and, or, not
* the from clause
  + when selecting from several relations, use the form 'tableName.attributeName' to name the result attribute

#### the rename operation

```sql
select T.attributeName
from tableName as T, tableName as S
where T.attributeName > S.attributeName and S.attributeName = ''
```

#### self join example

```sql
select T.attributeName1
from tableName T, tableName S
where T.attributeName1 = 'value' and T.attributeName2 = S.attributeName1
```

* recurrence(递归) usually not supported by SQL

#### string operations

* wildcard character(通配符)
  + `%`: matches any substring
  + `_`: matches any character

```sql
-- tansferred meaning character '\'
where '100\%' escape '\'
```

* case sensitive

#### ordering the dispaly of tuples

```sql
order by attributeName desc -- by default asc(升序), here desc means 降序

order by attributeName1, attributename2
```

#### where clause predicates(条件谓词)

```sql
where attributeName between 'value1' and 'value2' -- between

where attributeNane (attributeName1, attributeName2) = ('value1', 'value2') -- tuple comparision
```

#### set operations

```sql
union

intersect

except

-- retain the duplicated elements
union all

intersect all

except all
```

#### null values(don't know)

* the result of any arithmetic expression involving null is null

* the predicate *is null* can be used to check null values

```sql
where attributeName is null
```

* treat as unknown of any comparision involving null

* true, false, unknown support boolean calculation(布尔运算/逻辑运算)

#### aggregate functions(聚集函数)

```sql
avg
min
max
sum
count

select avg(attributeName)
from tableName
where attributebName = 'value'

-- group by
select attibuteName1, avg(attributeName2) as theNewName
from tableName
group by attributeName1

-- having clause
select attibuteName1, avg(attributeName2) as theNewName
from tableName
group by attributeName1
having avg(attributeName2) > 'value' -- before the group by must be where while afer must be having
```

#### nested subqueries and set membership

```sql
select distinct attributeName
from tableName
where attributeName not in('value1', 'value2')

select distinct attributeName
from tableName
where attributeName in(select attributeName
                       from tableName
                       where attributeName = 'value') -- the same using with 'not in'
```

#### set comparison

* 'some' clause

```sql
select attributeName
frome tableName
where attributeName > some() -- at least one element in this ()
```

  + some means *exists* not arbitrary

* 'all' clause

```sql
select attributeName
frome tableName
where attributeName > some() -- at least one element in this ()
```

  + all means *arbitrary*

* 'exists' clause

```sql
select attributeName
frome tableName
where exists(select
             from
             where) -- exists return a value whether the inner select is empty or not
-- usually use rename operation to associate outer select and inner select
-- the same using with 'not exist'
```

  + correlation name

* 'unique'
  + the unique construct evaluates to true if a given subquery cintains no duplicates

```sql

```

### modification of the database

#### deletion

```sql
delete from tableName -- delete all the data tuples, not affect the defination of the table
drop table tableName -- delete the total structure of the table

delete from tableName
where attributeName = 'value' -- also can use subquerys
```

* the logic: always deal with the subquerys first

#### insertion

```sql
insert into tableName
  values('attributeValue', 'attributeValue')

insert into tableName(attributeName, attributeName) -- list all the attribute
  values('attributeValue', null)

insert into tableName1
  select attributeName, attributeName -- all the attributes in table1, also can use the fixed data
  from tableName2
  where -- conditions

insert into tableName select* from tableName -- double the table
```

#### upadates

```sql
update tableName
  set attributeName = 'value'
  where -- conditions
```

* notice the order of the updates

* case statement for conditoinal updates

```sql
update tableName
  set attributeName = case
                        when -- condition 
                        then -- operation1
                        else -- operation2
                      end
```

### Intermediate SQL

#### join relations

* join operation take two relations and return one relation

+ natural join
  - when the common attributes are the same, they can be natural joined together
```sql
select attributeNAme1, attributeName2
from tableName1 natural join tableName2

select attributeNAme1, attributeName2
from tableName1, tableName2
where tableName1.commonAttribute = tableName2.commonAttribute
```
  - dangerous
    - beware the unrelated attributes with same name which get quated incorrectly
+ inner join
+ outer koin
