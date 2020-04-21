
char getChar (char mensaje[], char error[], char opc_1, char opc_2);

int getInt (char mensaje[], char error[], int min, int max);

float getFloat (char mensaje[], char error[], float min, float max);

// char[] getString (char mensaje[], char arrayParametro[], int cantidad);

void InicializarArray (int arrayParametro[], int cantidad, int numeroIndice);

int SumarArray (int arrayParametro[], int cantidad, int numeroIndice);

int ContarCargados (int arrayParametro[], int cantidad, int numeroIndice);

int ContarNoCargados  (int arrayParametro[], int cantidad, int numeroIndice);

int ContarSuperioresParametro  (int arrayParametro[], int cantidad, int numeroIndice, int numeroDeCorte);

int ContarInferioresParametro  (int arrayParametro[], int cantidad,int numeroIndice, int numeroDeCorte);

int MostrarMaximo  (int arrayParametro[], int cantidad,int numeroIndice);

int MostrarMinimo  (int arrayParametro[], int cantidad,int numeroIndice);

float PromedioArray (int arrayParametro[], int cantidad, int numeroIndice);

int MostrarPares  (int arrayParametro[], int cantidad,int numeroIndice);

void MostrarArrayTodos  (int arrayParametro[], int cantidad);

void MostrarVaciosParaUsuario  (int arrayParametro[], int cantidad, int numeroIndice);

void MostrarCargadosParaUsuario  (int arrayParametro[], int cantidad, int numeroIndice);
