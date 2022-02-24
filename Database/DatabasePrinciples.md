> writer: VenusHui
>  
> time: 2022.02.22
>  
> last edit: 2022.02.22
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

* data Models
  + data, data relationships, data semantics(语义), and consistency constraints
  + relational Model
  + entity-Relationship Model
  + semi-srtuctured Data Model
  + object-based Data Model

* relatinal Data Model
  + form of tables, rows & columns

* data Abstration
  + physical level
  + logical level: physical data independence
  + view level

* instances and schemas(模式)

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

* the DDl and DML simply form parts of a database language sucn as SQL

* Processing
  + parasing and translation
  + Optimization
  + Evaluation

- relation schema: a set of attributes

- tuple(元组) such as one row of the two elements table

- attribute values: atomical

- relations are totally unordered

- arbitrary(任意的)

- Keys
  - a subset of R(Relation)
  - superkey
  - candidate key: K is minimal(no subset or the subset of itself is also a superkey, not the num of attributes up to this)
  - primaray key: choose one(or more) candidate key
  - foreign key:
    - referencing relation
    - referenced relation