#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DIM 30 /* 30 numero massimo di task */

void addtask(char **);
void listtask(char **);
void deletetask(char **);


int main() {
	int user;
	int i, flag;
	char *tasks[DIM];
	/*rendo tutte le task = 0; */
	for (i = 0; i < DIM; i++)
		tasks[i] = NULL;

	flag = 1;

	printf("Task manager by p3ppe!\n\n");
	printf("Azioni possibili:\n"
		"- Add tasks\n"
		"- List tasks\n" /* da aggiungere completa e task completate*/
		"- Delete tasks\n"
		"- Search tasks\n");

	while (flag){
		printf("\nInserire il numero dell'azione che vuoi fare: ");
		scanf("%d", &user);
		switch (user){
			case 1:
				addtask(tasks);
				break;
			case 2:
				listtask(tasks);
				break;
			case 3:
				deletetask(tasks);
				break;
			/*case 4:
				searchtask();
				break; */
		}
	}

	return 0;
}

void addtask(char **tasks){
	char *task;
	int i, flag;
	flag = 1;

	/* devo allocare la memoria per la stringa che poi dovrò copiare nell'array di puntatori */
	task = malloc(100);
	if (task == NULL){	/*controllo che la memoria sia stata allocata correttamente */
		printf("Errore di allocazione memoria");
		return;
	}
	printf("-------------------------------------\n");
	printf("Scrivere la task da aggiungere: \n");
	scanf(" %[^\n]", task);
	for (i = 0; i < DIM && flag; i++){
		if (tasks[i] == NULL){
			tasks[i] = malloc(strlen(task) + 1);
			if (tasks[i] == NULL) {	/*controllo che la memoria sia stata allocata correttamente */
				printf("Errore di allocazione memoria");
				return;
			}
			strcpy(tasks[i], task);		/*devo usare array di puntatori di caratteri*/
			flag = 0;
		}
	}

	if (flag == 1)
		printf("Numero massimo di task raggiunto, cancellarne qualcuna per poterne aggiungere nuove.");
	free(task);
	return;
}

void listtask(char **tasks){
	int i, cont;
	cont = 0;

	printf("---------------------------\n");
	printf("Lista task: \n");
	for (i = 0; i < DIM; i++){
		if (tasks[i] != NULL) {
			printf(" - %s (n. %d)\n", tasks[i], i);
			cont++;
		}
	}

	if (cont == 0)
		printf("Nessuna task trovata!");

	return;
}

void deletetask(char **tasks){
	int num, i;
	listtask(tasks);

	printf("\nInserire il numero della task da eliminare: ");
	scanf("%d", &num);
	free(tasks[num]);
	tasks[num] = NULL;
	for (i = num + 1; i < DIM; i++) {
		if (tasks[i] != NULL) {
			tasks[i - 1] = tasks[i];
			tasks[i] = NULL;
		}else 
			return;
	}

	printf("Task %d eliminata!", num);
	return;
}




