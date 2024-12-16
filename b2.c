#include <stdio.h>
#include <string.h>

void nhapstr(char *str) {
    printf("Nhap vao chuoi: ");
    fflush(stdin);
    fgets(str, 1000, stdin);
    str[strcspn(str, "\n")] = '\0';
}

void instr(char *str) {
    printf("Chuoi vua nhap: %s\n", str);
}

int demchu(char *str) {
    int count = 0;
    while (*str) {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            count++;
        }
        str++;
    }
    return count;
}

int demso(char *str) {
    int count = 0;
    while (*str) {
        if (*str >= '0' && *str <= '9') {
            count++;
        }
        str++;
    }
    return count;
}

int demkitu(char *str) {
    int count = 0;
    while (*str) {
        if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9') || *str == ' ')) {
            count++;
        }
        str++;
    }
    return count;
}

int main() {
    char str[1000];
    int choice;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhapstr(str);
                break;
            case 2:
                instr(str);
                break;
            case 3:
                printf("So luong chu cai trong chuoi: %d\n", demchu(str));
                break;
            case 4:
                printf("So luong chu so trong chuoi: %d\n", demso(str));
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi: %d\n", demkitu(str));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai!\n");
        }
    } while (choice != 6);

    return 0;
}