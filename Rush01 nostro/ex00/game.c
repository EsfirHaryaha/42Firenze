
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
int	solve(int grid[g_lunghezza_lato][g_lunghezza_lato], int regole[g_lunghezza_perimetro], int posCella)
{
	//prende cella dopo cella (0,0) (0,1) ecc 
	//per ogni cella mette un numero a partire da 1 e chiama valid
	// se la cella va bene passa alla prossima e apre un'altro solve


	//controllo se non siamo gia passati oltre l'ultima cella
	//se si allora abbiamo risolto il puzzle perche anche l'ultima cella ha soddisfatto i requisiti
	if (posCella > (g_lunghezza_lato * g_lunghezza_lato) - 1)
	{
		return (0);
	}	


	//estraggo le coordinate della cella
	int riga = posCella / g_lunghezza_lato;
	int col = posCella % g_lunghezza_lato;

	
	//provo a inserire nella cella i vari numeri da 1 a g_lunghezza_lato
	int	val;
	int	error = 1;

	val = 1;
	while ( val <= g_lunghezza_lato && error != 0)
	{
		int errorValidazione = valid(grid, riga, colonna, val); //1  1  0
		if (errorValidazione == 0)
		{
			//assegno alla grid il valore che non ha dato errori
			grid[riga][col] = val;
			error = solve(grid, (postCella + 1)); //attenzione grid in questo punto e' una copia del grid originale!!!! controllare che conserva i valori che abbiamo impostato
		}
		val++;
	}

	if(error != 0)
	{
		//nessun valore soddisfava le regole quindi il puzzle non ha soluzioni
		return 1;
	}
	return 0;
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
	int	**grid;

	errori = solve(grid, regole, 0);

	if (errori != 0)
	{
		//stampa puzzle impossibile e fa return 1 del main
	}
	//se non ci sono errori stampa la grid
	stampaGrid(grid);
	return (0);
}