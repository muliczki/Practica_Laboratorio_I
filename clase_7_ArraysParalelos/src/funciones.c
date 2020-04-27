

	void InicializarAlumnos (int estado[], int tam, int valorLibre)
	{
	int i;
	for(i=0;i<tam;i++)
	{
		estado[i]=valorLibre;
	}
	}

	int BuscarVacio (int estado[], int tam, int valorLibre)
		{
		int i;
		int indice=-1;
		for(i=0;i<tam;i++)
		{
			if(estado[i]==valorLibre)
				{
				indice = i;
				break;
				}
		}
		return indice;
		}

	void CargarAlumno (int legajo[],/* int nota1, int nota2,*/ int estado[], int tam, int valorLibre )
	{
	int i;
	int indice;

	}
	indice = BuscarVacio(estado, tam, valorLibre);
	if(indice!=-1)
	{
		printf("Ingrese legajo: ");
		scanf("%d",&legajo[indice]);
	}


	}
