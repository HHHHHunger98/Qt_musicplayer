USE studentinfo;

-- Creating tables in studentInfo database.

CREATE TABLE Students (
	
    std_id int auto_increment,
    std_name varchar(20),
    birthday date,
    gender ENUM('male','female'),
    program varchar(20),
    studyField varchar(20),
    pwd varchar(20),
	PRIMARY KEY (std_id)
);

CREATE TABLE Administrators (

    ad_name varchar(20),
    pwd varchar(20),
	PRIMARY KEY (ad_name)
);

CREATE TABLE Teachers (
	
    t_id int auto_increment,
    t_name varchar(20),
    t_title varchar(20),
    age tinyint CHECK (age>0),
    pwd varchar(20),
    gender ENUM('male','female'),
	PRIMARY KEY (t_id)
);

CREATE TABLE Courses (
	
    c_id int auto_increment,
    c_name varchar(40),
    examForm varchar(20),
    credit tinyint CHECK (credit > 0),
    classroom varchar(20),
	PRIMARY KEY (c_id)
);

CREATE TABLE Institutes (
	
    inst_id int auto_increment,
    inst_name varchar(40),
    std_num int CHECK(std_num >= 0),
	PRIMARY KEY (inst_id)
);

CREATE TABLE Exams (
	std_id int auto_increment,
    t_id int,
    c_id int,
    examDate date,
    note int,
    tryTimes int CHECK (tryTimes > 0 AND tryTimes < 4),
    CONSTRAINT PK_Exam PRIMARY KEY (std_id, c_id, tryTimes)
);

AlTER TABLE Exams
ADD FOREIGN KEY	(std_id) REFERENCES Students(std_id);

CREATE TABLE Enrollment (
	std_id int auto_increment,
    c_id int,
    CONSTRAINT PK_Enrollment PRIMARY KEY(std_id, c_id)
);

AlTER TABLE Enrollment
ADD FOREIGN KEY	(std_id) REFERENCES Students(std_id);

/* Insert some values into Students table.
    std_id int auto_increment,
    std_name varchar(20),
    birthday date,
    gender ENUM('male','female'),
    program varchar(20),
    studyField varchar(20),
    pwd varchar(20),
*/
INSERT INTO Students VALUE(1, 'WZH', '1998-03-26', 'male', 'Master', 'Informatik', '123456');
INSERT INTO Students VALUE(2, 'aaa', '1997-06-26', 'male', 'Master', 'Informatik', '123456');
INSERT INTO Students VALUE(5, 'bbb', '1996-09-26', 'male', 'Master', 'Informatik', '123456');
INSERT INTO Students VALUE(6, 'ccc', '1995-12-26', 'male', 'Master', 'Informatik', '123456');

/* Insert some values into Administrators table.
    ad_id int auto_increment,
    ad_name varchar(20),
    pwd varchar(20),
*/
INSERT INTO Administrators VALUE('me', '123');

/* Insert some values into Courses table.
	c_id int auto_increment,
    c_name varchar(40),
    examForm varchar(20),
    credit tinyint CHECK (credit > 0),
    classroom varchar(20),
	PRIMARY KEY (c_id)
*/
INSERT INTO Courses VALUE(1, 'Database', 'oral exam', 6, 'APB 1006');
INSERT INTO Courses VALUE(2, 'AI', 'exam + exercise', 6, 'APB 1007');
INSERT INTO Courses VALUE(3, 'Software Engineering', 'exam + presentation', 4, 'APB 2007');
INSERT INTO Courses VALUE(4, 'Computer Graphic', 'oral exam', 6, 'APB 1067');
INSERT INTO Courses VALUE(5, 'Compiler Construction', 'oral exam', 6, 'APB 2006');
INSERT INTO Courses VALUE(6, 'Operating System', 'oral exam', 6, 'APB 2106');

/* Insert some values into Enrollment table.
	std_id int auto_increment,
    c_id int,
    CONSTRAINT PK_Enrollment PRIMARY KEY(std_id, c_id)
*/
INSERT INTO Enrollment VALUE(1, 1);
INSERT INTO Enrollment VALUE(1, 2);
INSERT INTO Enrollment VALUE(1, 3);

SELECT pwd FROM Students WHERE std_name='WZH';
SELECT pwd FROM Students WHERE std_id='1';
SELECT std_id, std_name, birthday, gender, program, studyField FROM Students WHERE std_id = '1';
SELECT * FROM Enrollment WHERE std_id='1';

SELECT * FROM Courses WHERE c_id IN (SELECT c_id FROM Enrollment WHERE std_id='1');