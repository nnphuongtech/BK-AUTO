#include <stdio.h>
#include <string.h>

int main() {
    char names[50][50];
    char phones[50][15];
    char emails[50][50];
    int count = 0;

    int choice;

    do {
        printf("\n===================================\n");
        printf("     QUAN LY DANH BA DIEN THOAI    \n");
        printf("===================================\n");
        printf("1. Them lien he moi\n");
        printf("2. Hien thi danh sach lien he\n");
        printf("3. Tim kiem lien he\n");
        printf("4. Cap nhat lien he\n");
        printf("5. Xoa lien he\n");
        printf("6. Thoat\n");
        printf("===================================\n");
        printf("Nhap lua chon cua ban (1-6): ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("\n--- THEM LIEN HE MOI ---\n");
                if (count >= 50) {
                    printf("Danh ba da day!\n");
                } else {
                    printf("Nhap ho va ten: ");
                    gets(names[count]);

                    printf("Nhap so dien thoai: ");
                    gets(phones[count]);

                    printf("Nhap email: ");
                    gets(emails[count]);

                    count++;
                    printf("=> Them thanh cong!\n");
                }
                break;

            case 2:
                printf("\n--- DANH SACH LIEN HE ---\n");
                if (count == 0) {
                    printf("Danh ba hien dang trong!\n");
                } else {
                    for (int i = 0; i < count; i++) {
                        printf("%d. Ten: %s | SDT: %s | Email: %s\n", i + 1, names[i], phones[i], emails[i]);
                    }
                }
                break;

            case 3:
                printf("\n--- TIM KIEM LIEN HE ---\n");
                if (count == 0) {
                    printf("Danh ba hien dang trong!\n");
                } else {
                    char search[50];
                    int found = 0;

                    printf("Nhap ten can tim: ");
                    gets(search);

                    printf("\nKet qua tim kiem:\n");
                    for (int i = 0; i < count; i++) {
                        if (strcmp(names[i], search) == 0) {
                            printf("%d. Ten: %s | SDT: %s | Email: %s\n", i + 1, names[i], phones[i], emails[i]);
                            found = 1;
                        }
                    }

                    if (found == 0) {
                        printf("Khong tim thay ai co ten %s.\n", search);
                    }
                }
                break;

            case 4:
                printf("\n--- CAP NHAT LIEN HE ---\n");
                if (count == 0) {
                    printf("Danh ba hien dang trong!\n");
                } else {
                    int pos;
                    printf("Nhap STT lien he can sua (1-%d): ", count);
                    scanf("%d", &pos);
                    getchar(); 

                    if (pos < 1 || pos > count) {
                        printf("STT khong hop le!\n");
                    } else {
                        int index = pos - 1;

                        printf("Nhap ten moi: ");
                        gets(names[index]);

                        printf("Nhap SDT moi: ");
                        gets(phones[index]);

                        printf("Nhap email moi: ");
                        gets(emails[index]);

                        printf("=> Cap nhat thanh cong!\n");
                    }
                }
                break;

            case 5:
                printf("\n--- XOA LIEN HE ---\n");
                if (count == 0) {
                    printf("Danh ba hien dang trong!\n");
                } else {
                    int pos;
                    printf("Nhap STT lien he can xoa (1-%d): ", count);
                    scanf("%d", &pos);
                    getchar();

                    if (pos < 1 || pos > count) {
                        printf("STT khong hop le!\n");
                    } else {
                        int index = pos - 1;
                        for (int i = index; i < count - 1; i++) {
                            strcpy(names[i], names[i + 1]);
                            strcpy(phones[i], phones[i + 1]);
                            strcpy(emails[i], emails[i + 1]);
                        }

                        count--;
                        printf("=> Xoa thanh cong!\n");
                    }
                }
                break;

            case 6:
                printf("\nCam on ban da su dung chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le! Vui long chon tu 1 den 6.\n");
                break;
        }

    } while (choice != 6); 
    return 0;
}