#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define DEBUG 1
#define lengh 20
#include <windows.h>

void input();
void output();
void findstruct();

int k;
worker workers[lengh];

int main()
{
    system("chcp 1251");
    system("cls");
    system("chcp 65001");


    // Ввод
    input();
    output();
    findstruct();
}

void input()
{
#if (DEBUG == 1)

    printf("Выбран режим ввода с клавиатуры\n");
    printf("Введите количество служащих (от 1 до 20): ");

    if (scanf("%d", &k) == 0 || k < 1 || k>20) {
        printf("Введено некорректное число.");
        exit(1);
    }

    //заполнение массива структур
    for (int i = 0; i < k; i++)
    {
        //ввод фамилии служащего
        printf("\nВведите фамилию %d служащего: ",i+1);
        scanf("%s",workers[i].full_name.surname);

        if (strlen(workers[i].full_name.surname) > 20) {
            printf("Введено неверное кол-во символов");
            exit(1);
        }

        //ввод имени служащего
        printf("Введите имя служащего: ");
        scanf("%s",workers[i].full_name.name);

        if (strlen(workers[i].full_name.name) > 20) {
            printf("Введено неверное кол-во символов");
            exit(1);
        }

        //ввод отчества служащего
        printf("Введите отчество служащего: ");
        scanf("%s",workers[i].full_name.patronymic);

        if (strlen(workers[i].full_name.patronymic) > 20) {
            printf("Введено неверное кол-во символов");
            exit(1);
        }

        //ввод возраста служащего
        printf("Введите возраст служащего: ");
        if (scanf("%d", &workers[i].age) == 0 || workers[i].age < 0) {
            printf("Введено некорректное число");
            exit(1);
        }

        //ввод улицы проживания служащего
        printf("Введите улицу проживания служащего: ");
        scanf("%s",workers[i].address.street);

        if (strlen(workers[i].address.street) > 20) {
            printf("Введено неверное кол-во символов");
            exit(1);
        }

        //ввод номера дома служащего
        printf("Введите номер дома служащего: ");

        if (scanf("%d", &workers[i].address.number_home) == 0 || workers[i].address.number_home < 0) {
            printf("Введено некорректное число");
            exit(1);
        }

        //ввод номера квартиры служащего
        printf("Введите номер квартиры служащего: ");

        if (scanf("%d", &workers[i].address.number_flat) == 0 || workers[i].address.number_flat < 0) {
            printf("Введено некорректное число");
            exit(1);
        }
    }
#else
    printf("Выбран заранее введенный массив отделов\n");
	k = 3;

	//работник 1
	strcpy(workers[0].full_name.surname, "Ivanova");
	strcpy(workers[0].full_name.name, "Alla");
	strcpy(workers[0].full_name.patronymic, "Ivanovna");
	workers[0].age = 19;
	strcpy(workers[0].address.street, "Stavropolskaya");
	workers[0].address.number_home = 17;
	workers[0].address.number_flat = 67;

	//работник 2
	strcpy(workers[1].full_name.surname, "Ivanova");
	strcpy(workers[1].full_name.name, "Larisa");
	strcpy(workers[1].full_name.patronymic, "Ramilevna");
	workers[1].age = 19;
	strcpy(workers[1].address.street, "Stavropolskaya");
	workers[1].address.number_home = 20;
	workers[1].address.number_flat = 69;

	//работник 3
	strcpy(workers[2].full_name.surname, "Ivanova");
	strcpy(workers[2].full_name.name, "Bulat");
	strcpy(workers[2].full_name.patronymic, "Rinatovich");
	workers[2].age = 19;
	strcpy(workers[2].address.street, "Stavropolskaya");
	workers[2].address.number_home = 20;
	workers[2].address.number_flat = 69;

#endif
}

void output()
{
    for (int i = 0; i < k; i++)
    {
        //вывод массива
        printf("\n");
        printf("%d-й Служащий:\n\n", i + 1);

        printf("Фамилия, Имя, Отчество: %s %s %s\n", workers[i].full_name.surname, workers[i].full_name.name, workers[0].full_name.patronymic);
        printf("Возраст: %d\n", workers[i].age);
        printf("Улица, дом, квартира: %s %d %d\n", workers[i].address.street, workers[i].address.number_home, workers[i].address.number_flat );
    }
}
//функция поиска самого молодого служащего и вывода необходимого массива
void findstruct()
{
    long int min = 100000000;
    int number;
    char this_street[20];

    printf("\nВведите конкретную улицу: ");
    scanf("%s", &this_street);

    printf("Введите конкретный дом: ");
    scanf("%d", &number);

//находим самого молодого служащего
    for (int i = 0; i < k; i++)
    {
        if ((workers[i].age <= min) && (workers[i].address.number_home == number)
            && (strcmp(workers[i].address.street,this_street) == 0))
            min = workers[i].age;
    }
    if (min == 100000000)
    {
        printf("Таких служателей нет\n");
        exit(1);
    }
//вывод массива
    for (int i = 0; i < k; i++)
    {
        if ((workers[i].age == min) && (workers[i].address.number_home == number)
            && (strcmp(workers[i].address.street,this_street) == 0))
        {
            printf("\nСамый молодой служащий:\n");

            printf("Фамилия, Имя, Отчество: %s %s %s\n", workers[i].full_name.surname,
                   workers[i].full_name.name, workers[0].full_name.patronymic);

            printf("Возраст: %d\n", workers[i].age);

            printf("Улица, дом, квартира: %s %d %d\n", workers[i].address.street,
                   workers[i].address.number_home, workers[i].address.number_flat );
        }
    }
}

