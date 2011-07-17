CREATE TABLE mytable(id integer primary key, name text, age integer);
INSERT INTO mytable VALUES('1', "XiaoGuo", 22);
INSERT INTO mytable VALUES('2', "guozesheng", 22);
SELECT * FROM mytable;
UPDATE mytable SET name = "guoguo" WHERE id = 2;

--sqlite3 test.db ".dump" > output.sql

