*This project has been created as part of the 42 curriculum by eharyaha.*

## Description

Libft è il primo progetto del curriculum 42 e consiste nel creare la tua prima libreria in C. L'obiettivo è reimplementare una serie di funzioni standard della libc (la libreria standard del C) e aggiungere alcune funzioni bonus utili per i progetti futuri.

Questo progetto è fondamentale perché la libreria che crei qui verrà usata in tutti i progetti successivi del curriculum. È quindi importante capire bene come funzionano queste funzioni e implementarle correttamente.

La libreria è divisa in due parti:
- **Parte obbligatoria**: 23 funzioni base della libc (isalpha, strlen, memset, etc.)
- **Parte bonus**: funzioni aggiuntive per la manipolazione di stringhe e una struttura dati per liste collegate

## Instructions

### Compilazione

Per compilare solo la parte obbligatoria:
```bash
make
```

Per compilare anche le funzioni bonus:
```bash
make bonus
```

Questo creerà il file `libft.a`, che è una libreria statica in formato archive.

### Pulizia

Per rimuovere i file oggetto (.o):
```bash
make clean
```

Per rimuovere anche la libreria compilata:
```bash
make fclean
```

Per ricompilare tutto da zero:
```bash
make re
```

### Utilizzo

Una volta compilata la libreria, puoi usarla nei tuoi progetti includendo l'header `libft.h` e linkando la libreria durante la compilazione:

```c
#include "libft.h"

int main(void)
{
    char *str = "Hello World";
    int len = ft_strlen(str);
    ft_putstr_fd(str, 1);
    return (0);
}
```

Compila con:
```bash
gcc main.c -L. -lft
```

Oppure se la libreria è in una cartella diversa:
```bash
gcc main.c libft.a
```

## Resources

Durante lo sviluppo di questo progetto ho consultato diverse risorse per capire meglio come funzionano le cose:

- **Documentazione ufficiale**: Ho letto attentamente i manuali delle funzioni usando `man` (ad esempio `man strlen`, `man malloc`, etc.) per capire esattamente il comportamento atteso di ogni funzione
- **Stack Overflow**: Quando mi sono trovato di fronte a problemi specifici o comportamenti strani, ho cercato su Stack Overflow per vedere come altri avevano risolto situazioni simili
- **GitHub**: Ho guardato implementazioni di altri studenti 42 (dopo aver finito il mio, ovviamente!) per confrontare approcci diversi e capire meglio alcune scelte di design
- **Tutorial YouTube**: Ho guardato alcuni video che spiegavano concetti come la gestione della memoria, come funzionano le librerie statiche, e la differenza tra stack e heap
- **Ex colleghi**: Ho chiacchierato con persone che avevano già fatto il progetto per avere consigli pratici e capire meglio alcuni edge case

### Uso dell'Intelligenza Artificiale

Ho usato l'AI principalmente per approfondire concetti teorici troppo specifici che erano difficili da discutere con i compagni. In particolare:

- **Allocazione della memoria**: Ho chiesto spiegazioni dettagliate su come funziona fisicamente l'allocazione dinamica della memoria, la differenza tra stack e heap, e come il sistema operativo gestisce queste richieste
- **Funzionamento del processore**: Per capire meglio cosa succede a basso livello quando eseguo certe operazioni, come le operazioni sui puntatori o le conversioni di tipo
- **Sequenze di esecuzione**: Per visualizzare passo passo cosa succede quando chiamo certe funzioni, specialmente quelle che manipolano la memoria come `memmove` o `calloc`
- **Creazione del README**: Ho usato l'AI per aiutarmi a strutturare e scrivere questo README, seguendo le specifiche richieste dal curriculum

L'AI mi ha aiutato a capire il "perché" dietro certi comportamenti, non il "come implementarlo". Tutto il codice è stato scritto da me, ma avere una comprensione più profonda di cosa succede sotto il cofano mi ha aiutato a scrivere codice più sicuro e a evitare bug legati alla gestione della memoria.

## Dettagli della Libreria

### Funzioni Obbligatorie (Part 1 - Libc functions)

#### Classificazione di caratteri
- `ft_isalpha`: verifica se un carattere è una lettera (a-z, A-Z)
- `ft_isdigit`: verifica se un carattere è una cifra (0-9)
- `ft_isalnum`: verifica se un carattere è alfanumerico
- `ft_isascii`: verifica se un carattere è ASCII (0-127)
- `ft_isprint`: verifica se un carattere è stampabile (32-126)

#### Manipolazione di stringhe
- `ft_strlen`: calcola la lunghezza di una stringa
- `ft_strlcpy`: copia una stringa in modo sicuro (con controllo della dimensione)
- `ft_strlcat`: concatena due stringhe in modo sicuro
- `ft_strchr`: trova la prima occorrenza di un carattere in una stringa
- `ft_strrchr`: trova l'ultima occorrenza di un carattere in una stringa
- `ft_strncmp`: confronta due stringhe (fino a n caratteri)
- `ft_strnstr`: trova una sottostringa in una stringa (fino a len caratteri)
- `ft_strdup`: duplica una stringa allocando memoria

#### Manipolazione della memoria
- `ft_memset`: riempie una zona di memoria con un valore specifico
- `ft_bzero`: azzera una zona di memoria
- `ft_memcpy`: copia n byte da una zona di memoria a un'altra
- `ft_memmove`: copia n byte gestendo correttamente le sovrapposizioni
- `ft_memchr`: cerca un byte in una zona di memoria
- `ft_memcmp`: confronta due zone di memoria

#### Conversioni
- `ft_toupper`: converte un carattere in maiuscolo
- `ft_tolower`: converte un carattere in minuscolo
- `ft_atoi`: converte una stringa in un intero

#### Allocazione di memoria
- `ft_calloc`: alloca e azzera una zona di memoria (equivalente a malloc + memset)

### Funzioni Bonus (Part 2 - Additional functions)

#### Manipolazione avanzata di stringhe
- `ft_substr`: estrae una sottostringa da una stringa
- `ft_strjoin`: concatena due stringhe allocando nuova memoria
- `ft_strtrim`: rimuove caratteri specificati dall'inizio e dalla fine di una stringa
- `ft_split`: divide una stringa in un array di stringhe usando un delimitatore
- `ft_itoa`: converte un intero in una stringa
- `ft_strmapi`: applica una funzione a ogni carattere di una stringa e crea una nuova stringa
- `ft_striteri`: applica una funzione a ogni carattere di una stringa (modifica in-place)

#### Output su file descriptor
- `ft_putchar_fd`: stampa un carattere su un file descriptor
- `ft_putstr_fd`: stampa una stringa su un file descriptor
- `ft_putendl_fd`: stampa una stringa seguita da un newline su un file descriptor
- `ft_putnbr_fd`: stampa un numero su un file descriptor

### Funzioni Bonus (Part 3 - Linked lists)

Tutte le funzioni per le liste collegate usano la struttura `t_list`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

- `ft_lstnew`: crea un nuovo elemento di lista
- `ft_lstadd_front`: aggiunge un elemento all'inizio della lista
- `ft_lstadd_back`: aggiunge un elemento alla fine della lista
- `ft_lstsize`: conta il numero di elementi in una lista
- `ft_lstlast`: restituisce l'ultimo elemento della lista
- `ft_lstdelone`: elimina un elemento della lista (chiama una funzione di cleanup)
- `ft_lstclear`: elimina tutta la lista
- `ft_lstiter`: applica una funzione a ogni elemento della lista
- `ft_lstmap`: crea una nuova lista applicando una funzione a ogni elemento

## Note Tecniche

- Tutte le funzioni seguono esattamente il comportamento delle funzioni originali della libc
- La gestione della memoria è importante: le funzioni che allocano memoria (come `ft_strdup`, `ft_substr`, etc.) restituiscono puntatori che devono essere liberati con `free()`
- Le funzioni bonus non sono incluse di default: devi compilare con `make bonus` per includerle
- Il codice compila con i flag `-Wall -Wextra -Werror` per garantire che non ci siano warning
