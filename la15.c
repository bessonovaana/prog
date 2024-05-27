#include <stdio.h>
#include <string.h>

typedef struct {
    char destination[50];
    int train_number;
    int departure_time[2]; 
} Train;
int main(){
    FILE *f=fopen("Train.dat","wb");
    if (f==NULL){
        printf("ERROR reading\n");
        return 1;
    }
    int n;
    printf("enter numer of train: ");
    scanf("%d",&n);
    Train trains[n];
    for (int i=0;i<n;i++){
        printf("Введите данные о поезде %d:\n", i + 1);

        printf("Название пункта назначения: ");
        scanf("%s", trains[i].destination);

        printf("Номер поезда: ");
        scanf("%d", &trains[i].train_number);

        printf("Время отправления (часы минуты): ");
        scanf("%d %d", &trains[i].departure_time[0], &trains[i].departure_time[1]);
    }
    fwrite(trains, sizeof(Train), n, f);
    fclose(f);
int search_time[2];
    printf("Введите время, после которого нужно искать поезда (часы минуты): ");
    scanf("%d %d", &search_time[0], &search_time[1]);

    f = fopen("Train.dat", "rb");
    if (f == NULL) {
        perror("Ошибка открытия файла");
        return 0;
    }

   
    int found = 0;
    while (fread(&trains, sizeof(Train), 1, f)) {
        if (trains->departure_time[0] > search_time[0] ||
            (trains->departure_time[0] == search_time[0] && trains->departure_time[1] > search_time[1])) {
            printf("Поезд %d отправляется в %s в %02d:%02d\n", trains->train_number, trains->destination, trains->departure_time[0], trains->departure_time[1]);
            found = 1;
        }
    }

   
    if (!found) {
        printf("Поездов, отправляющихся после %02d:%02d, нет\n", search_time[0], search_time[1]);
    }

    fclose(f);

}