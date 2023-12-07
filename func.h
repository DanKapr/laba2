typedef struct {
	char name[40];
	char poroda[40];
	char pol[40];
	int age;
}sobaka;
void write(sobaka *arr, int n);
void reed(sobaka **arr, int *n);
void create(sobaka **arr, int *n);
void search(sobaka *arr, int n, char *name); 



