
int g_lunghezza_lato = 4; // <-- variabile globale
int g_lunghezza_perimetro;


// la funzione valid controlla la validita' del valore appena inserito da solve
int	valid(int **grid, int riga, int col, int val);
{
	//controlla ripetizioni nella riga poi nella colonna
	//controlla visibilita a destra sinistra sopra sotto o li rende impossibili?
	//in caso di qualunque errore return 1 altrimenti return 0

	grid[riga][col] = val;

	int error = 0;

	//al momento fa tutti i controlli anche se trova un errore prima della fine, vedere se si riesce ad accorciare
	error = error + controllaDoppioniRiga(grid, riga, col);
	error = error + controllaDoppioniColonna(grid, riga, col);
	error = error + controllaDaDestra(grid, riga, col);
	error = error + controllaDaSinistra(grid, riga, col);
	error = error + controllaDaSopra(grid, riga, col);
	error = error + controllaDaSotto(grid, riga, col);

	return error;
}


//la funzione solve che riempie a tentativi la griglia cella dopo cella, e' la nostra funzione annidata
//posCella ci permette di capire quale cella stiamo cercando di validare, dal main si parte dalla prima cella  che nel array equivale a 0
int	solve(int griglia[g_lunghezza_lato][g_lunghezza_lato], int indici_visibilita[g_lunghezza_perimetro], int posCella)
{
	//prende cella dopo cella (0,0) (0,1) ecc 
	//per ogni cella mette un numero a partire da 1 e chiama valid
	// se la cella va bene passa alla prossima e apre un'altro solve


	//controllo se non siamo gia passati oltre l'ultima cella
	//se si allora abbiamo risolto il puzzle perche anche l'ultima cella ha soddisfatto i requisiti	
	
	if (posCella > (g_lunghezza_lato * 4) - 1)
	{
		//deve stampare qui la grigli perche sono le copie di copie di copie di quella originale, se non la stampi perdi tutto
		stampa_griglia(griglia);
		return (0);
	}


	//estraggo le coordinate della cella
	int riga = posCella / g_lunghezza_lato;
	int colonna = posCella % g_lunghezza_lato;


	//provo a inserire nella cella i numeri da 1 a g_lunghezza_lato
	int	val;

	val = 1;
	while ( val <= g_lunghezza_lato)
	{
		//facciamo subito il controllo che il numero sia unico nella riga
		if(is_unique(griglia, riga, colonna, val))
		{
			griglia[riga][colonna] = val;
			
			//se non sono all'ultima colonna dell'ultima riga vado avanti
			if ((col < 3 || check_constraints(grid, clues, row, col + 1)) &&
				(row < 3 || check_constraints(grid, clues, row + 1, col)))
			{
				int erroreSolve = solve(griglia, regole, (postCella + 1)); //attenzione grid in questo punto e' una copia del grid originale!!!!
				if (erroreSolve)
				    return 1;
			}
			grid[row][col] = 0;
		}
		val++;
	}
	//nessun valore soddisfava le regole quindi il puzzle non ha soluzioni
	return 1;
}





//main che prende la stringa come argomento, fa i controlli e trasforma in array  e richiama solve
int	main(int argc, int **argv)
{
	//--------controlli sul parametro passato

	//definire la larghezza della griglia in modo dinamico calcolandolo da argv che viene passato



	
	//--------logica del gioco
//
//
//
//dichiaro l'array della griglia
	int	**griglia;

	errori = solve(griglia, regole, 0);

	if (errori != 0)
	{
		//puzzle impossibile, fa return 1 del main
	}
	return (0);
}
