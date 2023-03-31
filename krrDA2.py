// Create more nodes for semesters
CREATE (:Semester {semester_id: 3, name: "Spring 2022"});
CREATE (:Semester {semester_id: 2, name: "Fall 2021"});

// Create more nodes for HODs
CREATE (:HOD {name: "Dr. Rachel Smith", age: 45, gender: "Female", phone: "555-555-5555", department: "Biology"});

// Create relationships between nodes
MATCH (s:Student),(c:Course),(sem:Semester)
WHERE s.student_id = 3 AND c.course_id = 301 AND sem.semester_id = 3
CREATE (s)-[:ENROLLED_IN {semester: sem.name}]->(c);

MATCH (s:Student),(c:Course),(sem:Semester)
WHERE s.student_id = 4 AND c.course_id = 401 AND sem.semester_id = 3
CREATE (s)-[:ENROLLED_IN {semester: sem.name}]->(c);

MATCH (s:Student),(c:Course),(sem:Semester)
WHERE s.student_id = 5 AND c.course_id = 501 AND sem.semester_id = 2
CREATE (s)-[:ENROLLED_IN {semester: sem.name}]->(c);

MATCH (t:Teacher),(c:Course)
WHERE t.teacher_id = 3 AND c.course_id = 301
CREATE (t)-[:TEACHES]->(c);

MATCH (t:Teacher),(c:Course)
WHERE t.teacher_id = 4 AND c.course_id = 401
CREATE (t)-[:TEACHES]->(c);

MATCH (p:Parent),(s:Student)
WHERE p.parent_id = 3 AND s.student_id = 3
CREATE (p)-[:PARENT_OF]->(s);

MATCH (p:Parent),(s:Student)
WHERE p.parent_id = 4 AND s.student_id = 4
CREATE (p)-[:PARENT_OF]->(s);

MATCH (p:Parent),(s:Student)
WHERE p.parent_id = 5 AND s.student_id = 5
CREATE (p)-[:PARENT_OF]->(s);

MATCH (d:Dean),(t:Teacher)
WHERE d.name = "Dr. Mark Johnson" AND t.teacher_id = 3
CREATE (d)-[:SUPERVISES]->(t);

MATCH (h:HOD),(t:Teacher),(sem:Semester)
WHERE h.name = "Dr. Rachel Smith" AND t.teacher_id = 4 AND sem.semester_id = 3
CREATE (h)-[:MANAGES {semester: sem.name}]->(t);
