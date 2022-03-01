> writer: VenusHui
>  
> time: 2022.02.22
>  
> last edit: 2022.02.28
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
- SQL names are case insensitive
- relational algebra do not allow duplication but SQL allows
- select clause can contain arithmetic expressions
- I think select clause returns a particular table
- the where clause: the additonal comparisions, use and, or, not
- the from clause
  - when selecting from several relations, use the form 'tableName.attributeName' to name the result attribute

#### the rename operation
```sql
select T.attributeName
from tableName as T, tableName as S
where T.attributeName > S.attributeName and S.attributeName = ''
```