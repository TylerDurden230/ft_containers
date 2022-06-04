# ft_containers
Implementazione di alcuni containers della STL (Standard Template Library)

Un contenitore è un oggetto che memorizza una collezione di altri oggetti come suoi elementi. 
essendo implementati come classi Template, questi permettono una grande flessibilità nei tipi di dati supportati come elementi.
Il contenitore gestisce lo spazio di archiviazione per i suoi elementi e fornisce funzioni membro per accedervi, 
direttamente o tramite iteratori (oggetti di riferimento con proprietà simili ai puntatori).

In questo progetto sono stati implementati 3 containers:

<strong><h3>Vector</h3></strong>
Container di dati molto simile all'array, infatti porprio come questo, anche il vettore immagazzina in maniera contigua i suoi elementi.
Il vettore rappresenta però una versione evoluta dell'array del C, infatti al contrario di esso non ha una capacità massima prefissata in tempo di compilazione, ma si espande durante l'esecuzione a seconda delle necessità e per questo viene definito come <strong>array dinamico</strong>.

