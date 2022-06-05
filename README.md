# ft_containers
Implementazione di alcuni containers della STL (Standard Template Library)

Un contenitore è un oggetto che memorizza una collezione di altri oggetti come suoi elementi. 
essendo implementati come classi Template, questi permettono una grande flessibilità nei tipi di dati supportati come elementi.
Il contenitore gestisce lo spazio di archiviazione per i suoi elementi e fornisce funzioni membro per accedervi, 
direttamente o tramite iteratori (oggetti di riferimento con proprietà simili ai puntatori).

In questo progetto sono stati implementati 3 containers:

<strong><h3>Vector</h3></strong>
Container di dati molto simile all'array, infatti porprio come questo, anche il vettore immagazzina in maniera contigua i suoi elementi.<br>
Il vettore rappresenta però una versione evoluta dell'array del C, infatti al contrario di esso, non ha una capacità massima prefissata in tempo di compilazione, ma si espande durante l'esecuzione a seconda delle necessità e per questo viene definito come <strong>array dinamico</strong>.
Questo array potrebbe aver bisogno di essere riassegnato per crescere di dimensioni quando vengono inseriti nuovi elementi, il che implica l'allocazione di un nuovo array e lo spostamento di tutti gli elementi ad esso. 
Questo è un compito relativamente costoso in termini di tempo di elaborazione, per questo motivo il vettore potrà allocare un po' di spazio in più per adattarsi alla possibile crescita, e quindi avere una capacità effettiva maggiore dello spazio di archiviazione strettamente necessario per contenere i suoi elementi.

<strong><h3>Stack</h3></strong>
Gli Stack sono tipi di container definiti come LIFO (last-in first-out), dove gli elementi sono inseriti ed estratti soltanto dalla fine del container.
Lo stack é basato sul vettore del quale inibisce alcune funzionalità e ne specializza delle altre per le sue necessità.


<strong><h3>Map</h3></strong>
Le mappe sono contenitori associativi che memorizzano elementi formati da una combinazione di un valore chiave e un valore mappato, seguendo un ordine specifico.
In una mappa, i valori chiave vengono generalmente utilizzati per ordinare e identificare in modo univoco gli elementi, mentre i valori mappati memorizzano il contenuto associato a questa chiave. I tipi di chiave e di valore mappato possono differire e sono raggruppati insieme nel tipo di elemento value_type, che è un tipo <strong>Pair</strong> che combina entrambi.<br>
<code>typedef pair<const Key, T> value_type;</code>
  
 Internamente, gli elementi di una mappa sono sempre ordinati in base alla sua chiave seguendo un criterio di ordinamento specifico e rigoroso indicato dal suo oggetto di confronto interno (Compare).
