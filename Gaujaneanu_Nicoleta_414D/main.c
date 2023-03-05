///     Sa se creeze un program care monitorizeaza situatia unor studenti intr-un catalog( un student are un nume si note la poo, pc, sda) programul trebuie sa contina un meniu cu urmatoarele optiuni

///     1. Adauga student(se adauga un student cu datele sale date de la tastatura)(ex de nume: andrei, ana, alina) fara un al doilea nume
///     2. Se cauta un anumit student dupa numele acestuia
///     3. Se afiseaza numarul de studenti din catalog
///     4. Se afiseaza lista cu numele tuturor studentilor
///     5. Se afiseaza restantierii(se considera un restantier acel student care a ramas restatnier la cel putin una din cele 3 materii)
///     6. Se iese din meniu, inchidem programul


#include <stdio.h>
#include <conio.h> //biblioteca pentru functia getch()
#include <string.h> //biblioteca pentru siruri de caractere


struct student{ // structura student

    char nume[50];
    int pc;
    int sda;
    int poo;

}Studenti[200]; // am definit catalogul global pentru a putea fi accesat de toate functiile


void adauga(int n){ //adauga un student, n reprezinta numarul studentul la care am ajuns

    printf("Dati numele studentului\n");
    scanf("%s", &Studenti[n].nume); // sirurile de caractere nu necesita & in comparatie cu numerele

    printf("Dati nota lui la pc");
    scanf("%d", &Studenti[n].pc);

    printf("Dati nota lui la sda");
    scanf("%d", &Studenti[n].sda);

    printf("Dati nota lui la poo");
    scanf("%d", &Studenti[n].poo);

}



void cauta(int n){

    char nume[15];
    int i;
    int ok = 0;

    printf("Dati numele elevului\n");
    scanf("%s", nume); //citim numele pe care vrem sa l cautam

    for(i = 0; i < n; i++)

        if(strcmp(nume, Studenti[i].nume) == 0) { /// == 0 inseamna ca am gasit elevul cu numele pe care l vreau

            ok = 1;

            printf("Elevul %s este in baza de date\n", Studenti[i].nume);
            printf("Nota lui la pc este %d\n", Studenti[i].pc);
            printf("Nota lui la sda este %d\n", Studenti[i].sda);
            printf("Nota lui la poo este %d\n", Studenti[i].poo);

            break; //daca am gasit un nume iesim din for cu intructiunea break si facem flag = 1
        }

    if (ok == 0)
        printf("Elevul nu a fost gasit in baza de date");

}


int numarare(int n){

    int contor = 0;

    for(int i = 0; i < n; i++)
        contor++;

    printf("Numarul de studenti este: ");
    return contor;

}


void lista(int n){

    for(int i = 0; i < n; i++){
        printf("%s\n", Studenti[i].nume);
    }

}

void restantieri(int n){

    for(int i = 0; i < n; i++)
        if(Studenti[i].sda < 5 || Studenti[i].pc < 5 || Studenti[i].poo < 5)
            printf("Elevul %s este restantier!\n", Studenti[i].nume);

}


int main() {

    char caz;
    int n = 0, flag = 1;

    do {
        printf("1.Adaugati student\n2.Cautati student\n3.Afisati numarul de studenti\n4.Adisati lista cu studenti\n5.Afisati restantierii\n6.Iesire\n");
        caz = getch(); // citeste o optiune, optiunea este un caracter
        //getch();//enterul de la getch este tinut minte in memorie cand o sa cititi a doua optiune in loc ca programul sa citeasca un numar (1 ,2, 3 etc) va citi enter acest getch() este pentru a elimina enterul din memorie
        switch (caz) {
            case '1':
                adauga(n);
                n++;
                break;
            case '2':
                cauta(n);
                break;
            case '3':
                printf("%d",numarare(n));
                break;
            case '4':
                lista(n);
                break;
            case '5':
                restantieri(n);
                break;
            case '6':
                flag = 0;
                break;
            default:
                break;
        }
    }while(flag);

    return 0;
}
