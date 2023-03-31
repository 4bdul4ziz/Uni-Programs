//1st graph
CREATE (MedicalRecord:Category {name: "Medical Record"})
CREATE (TextSummarizationTool:Category {name: "Summary"})
CREATE (ImportantMedicalTerminology:Category {name: "Medical Term"})
CREATE (ConceptsAndRelationships:Category {name: "Concepts"})

CREATE (patientHistory:Term {name: "Patient History"})
CREATE (diagnosis:Term {name: "Diagnosis"})
CREATE (treatmentPlans:Term {name: "Treatment Plans"})

CREATE (S:Function {name: "PageRank"})

CREATE (ImportantMedicalTerminology)-[:IN_CATEGORY]->(MedicalRecord)
CREATE (ConceptsAndRelationships)-[:IN_CATEGORY]->(MedicalRecord)
CREATE (S)-[:OPERATES_ON]->(MedicalRecord)
CREATE (S)-[:GENERATES]->(TextSummarizationTool)

CREATE (patientHistory)-[:HAS_ELEMENT]->(MedicalRecord)
CREATE (diagnosis)-[:HAS_ELEMENT]->(MedicalRecord)
CREATE (treatmentPlans)-[:HAS_ELEMENT]->(MedicalRecord)

CREATE (p:Element {name: "Fever"})
CREATE (c:Element {name: "Infection"})

CREATE (p)-[:BELONGS_TO]->(ImportantMedicalTerminology)
CREATE (c)-[:BELONGS_TO]->(ConceptsAndRelationships)
CREATE (p)-[:INCLUDED_IN]->(S)
CREATE (c)-[:INCLUDED_IN]->(S)

//2nd graph
CREATE (LegalDocument:Category {name: "Legal Doc"})
CREATE (TextSummarizationTool:Category {name: "Summary"})
CREATE (KeyClauses:Category {name: "Key Clauses"})
CREATE (ContractNegotiation:Category {name: "Contract Negotiation"})

CREATE (Summary:Function {name: "PageRank"})

CREATE (KeyClauses)-[:IN_CATEGORY]->(LegalDocument)
CREATE (ContractNegotiation)-[:IN_CATEGORY]->(LegalDocument)
CREATE (Summary)-[:OPERATES_ON]->(LegalDocument)
CREATE (Summary)-[:GENERATES]->(TextSummarizationTool)

CREATE (keyClausesSnippet:Snippet {name: "Key Clauses"})
CREATE (contractNegotiationSnippet:Snippet {name: "Contract Neg."})

CREATE (keyClausesSnippet)-[:INCLUDED_IN]->(KeyClauses)
CREATE (contractNegotiationSnippet)-[:INCLUDED_IN]->(ContractNegotiation)

CREATE (summarySnippet:Snippet {name: "Summary"})
CREATE (summarySnippet)-[:GENERATED_BY]->(Summary)


//3rd graph
CREATE (Traveler:Category {name: "Traveler"})
CREATE (TravelGuide:Category {name: "Travel Guide"})
CREATE (Destination:Category {name: "Destination"})
CREATE (Summary:Category {name: "Summary"})

CREATE (name:Property {name: "name"})
CREATE (age:Property {name: "age"})
CREATE (travelPreferences:Property {name: "travel preferences"})
CREATE (title:Property {name: "title"})
CREATE (author:Property {name: "author"})
CREATE (content:Property {name: "content"})
CREATE (description:Property {name: "description"})
CREATE (source:Property {name: "source"})

CREATE (PLANS_TRIP_TO:RelationshipType {name: "PLANS_TRIP_TO"})
CREATE (VISITS:RelationshipType {name: "VISITS"})
CREATE (CONTAINS:RelationshipType {name: "CONTAINS"})
CREATE (SUMMARIZES:RelationshipType {name: "SUMMARIZES"})

CREATE (Traveler)-[:HAS_PROPERTY]->(name)
CREATE (Traveler)-[:HAS_PROPERTY]->(age)
CREATE (Traveler)-[:HAS_PROPERTY]->(travelPreferences)
CREATE (TravelGuide)-[:HAS_PROPERTY]->(title)
CREATE (TravelGuide)-[:HAS_PROPERTY]->(author)
CREATE (TravelGuide)-[:HAS_PROPERTY]->(content)
CREATE (Destination)-[:HAS_PROPERTY]->(name)
CREATE (Destination)-[:HAS_PROPERTY]->(location)
CREATE (Destination)-[:HAS_PROPERTY]->(description)
CREATE (Summary)-[:HAS_PROPERTY]->(content)
CREATE (Summary)-[:HAS_PROPERTY]->(source)

CREATE (Traveler)-[:PLANS_TRIP_TO]->(Destination)
CREATE (Traveler)-[:VISITS]->(Destination)
CREATE (TravelGuide)-[:CONTAINS]->(Destination)
CREATE (Summary)-[:SUMMARIZES]->(TravelGuide)
CREATE (Paris:Destination {name: "Paris", location: "France", description: "City of love and lights"})
CREATE (Rome:Destination {name: "Rome", location: "Italy", description: "Eternal city with ancient history"})
CREATE (Bali:Destination {name: "Bali", location: "Indonesia", description: "Island paradise with beaches and temples"})

CREATE (Traveler1:Traveler {name: "John", age: 30, preference: "beaches"})
CREATE (Traveler2:Traveler {name: "Sarah", age: 25, preference: "adventure"})

CREATE (TravelGuide1:TravelGuide {title: "10 must-see attractions in Paris", author: "Traveler's Digest", content: "article content"})
CREATE (TravelGuide2:TravelGuide {title: "Top 5 adventure activities in Bali", author: "Adventurer's Journal", content: "article content"})
CREATE (TravelGuide3:TravelGuide {title: "Ancient history sites to visit in Rome", author: "History Buff", content: "article content"})

CREATE (Summary1:Summary {content: "summary content", source: "Traveler's Digest"})
CREATE (Summary2:Summary {content: "summary content", source: "Adventurer's Journal"})
CREATE (Summary3:Summary {content: "summary content", source: "History Buff"})

CREATE (Traveler1)-[:PLANS_TRIP_TO]->(Bali)
CREATE (Traveler2)-[:PLANS_TRIP_TO]->(Paris)
CREATE (Traveler2)-[:VISITS]->(Rome)

CREATE (TravelGuide1)-[:CONTAINS]->(Paris)
CREATE (TravelGuide2)-[:CONTAINS]->(Bali)
CREATE (TravelGuide3)-[:CONTAINS]->(Rome)

CREATE (Summary1)-[:SUMMARIZES]->(TravelGuide1)
CREATE (Summary2)-[:SUMMARIZES]->(TravelGuide2)
CREATE (Summary3)-[:SUMMARIZES]->(TravelGuide3)

//4th graph
CREATE (Email:Category {name: "Email"})
CREATE (Summary:Category {name: "Summary"})
CREATE (Content:Category {name: "Content"})
CREATE (InThread:Category {name: "InThread"})
CREATE (Summarizes:Category {name: "Summarizes"})
CREATE (Contains:Category {name: "Contains"})
CREATE (ReplyTo:Category {name: "ReplyTo"})

CREATE (e1:Element {name: "e1"})
CREATE (e2:Element {name: "e2"})
CREATE (e3:Element {name: "e3"})
CREATE (e4:Element {name: "e4"})
CREATE (e5:Element {name: "e5"})

CREATE (Email)-[:IN_CATEGORY]->(e1)
CREATE (Summary)-[:IN_CATEGORY]->(e2)
CREATE (Content)-[:IN_CATEGORY]->(e3)
CREATE (InThread)-[:IN_CATEGORY]->(e4)
CREATE (Summarizes)-[:IN_CATEGORY]->(e5)

CREATE (e1)-[:BELONGS_TO]->(Email)
CREATE (e2)-[:BELONGS_TO]->(Summary)
CREATE (e3)-[:BELONGS_TO]->(Content)
CREATE (e4)-[:BELONGS_TO]->(InThread)
CREATE (e5)-[:BELONGS_TO]->(Summarizes)

CREATE (e3)-[:HAS_ELEMENT]->(e1)
CREATE (e3)-[:HAS_ELEMENT]->(e2)
CREATE (e3)-[:HAS_ELEMENT]->(e5)

CREATE (e4)-[:HAS_ELEMENT]->(e1)
CREATE (e4)-[:HAS_ELEMENT]->(e1)
CREATE (e4)-[:HAS_ELEMENT]->(ReplyTo)

CREATE (e5)-[:HAS_ELEMENT]->(e2)
CREATE (e5)-[:HAS_ELEMENT]->(e1)

CREATE (e6:Element {name: "e6"})
CREATE (e7:Element {name: "e7"})

CREATE (Contains)-[:IN_CATEGORY]->(e6)
CREATE (ReplyTo)-[:IN_CATEGORY]->(e7)

CREATE (e6)-[:BELONGS_TO]->(Contains)
CREATE (e7)-[:BELONGS_TO]->(ReplyTo)

CREATE (e6)-[:HAS_ELEMENT]->(e1)
CREATE (e6)-[:HAS_ELEMENT]->(e2)
CREATE (e6)-[:HAS_ELEMENT]->(e3)

CREATE (e7)-[:HAS_ELEMENT]->(e1)
CREATE (e7)-[:HAS_ELEMENT]->(e2)


//5th graph
CREATE (article:Article {title: "Political News", author: "BBC News", date: "2021-03-11"})
CREATE (summary:Summary {content: "Congress", source: "BBC News"})
CREATE (topic:Topic {name: "Politics"})
CREATE (tool:Tool {name: "PageRank"})

CREATE (article)-[:CONTAINS]->(topic)
CREATE (summary)-[:SUMMARIZES]->(article)
CREATE (summary)-[:GENERATED_BY]->(tool)

CREATE (user:User {name: "Alice"})
CREATE (user)-[:REQUESTS_SUMMARY]->(article)
CREATE (user)-[:RECEIVES_SUMMARY]->(summary)

//6th graph
CREATE (env:Environment {name: 'Internal Document Management System'})
CREATE (folder:Folder {name: 'Policy Documents Folder'})
CREATE (db:Database {name: 'Policy Document Summary Database'})
CREATE (summary:Summary {content: 'Summary Doc', source: 'Internal Document Management System'})
CREATE (summary)-[:SAVED_IN]->(db)
CREATE (folder)-[:CONTAINS]->(doc1:PolicyDocument {name: 'Document 1', content: '...'})
CREATE (folder)-[:CONTAINS]->(doc2:PolicyDocument {name: 'Document 2', content: '...'})
CREATE (folder)-[:CONTAINS]->(doc3:PolicyDocument {name: 'Document 3', content: '...'})
CREATE (doc1)-[:IN_FOLDER]->(folder)
CREATE (doc2)-[:IN_FOLDER]->(folder)
CREATE (doc3)-[:IN_FOLDER]->(folder)
CREATE (doc1)-[:SUMMARIZED_BY]->(summary)
CREATE (doc2)-[:SUMMARIZED_BY]->(summary)
CREATE (doc3)-[:SUMMARIZED_BY]->(summary)

