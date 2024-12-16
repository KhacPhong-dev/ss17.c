#include <stdio.h>
#include <string.h>
#include <ctype.h>

void nhap_arr(char *arr) {
    printf("Nhap vao arr: ");
    fgets(arr, 1000, stdin);
    arr[strcspn(arr, "\n")] = '\0';
}

void dao_nguoc_arr(char *arr) {
    int do_dai = strlen(arr);
    printf("arr dao nguoc: ");
    for (int i = do_dai - 1; i >= 0; i--) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

int dem_so_tu(char *arr) {
    int dem = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if ((arr[i] != ' ' && arr[i + 1] == ' ') || (arr[i] != ' ' && arr[i + 1] == '\0')) {
            dem++;
        }
    }
    return dem;
}

void so_sanh_arr(char *arr1, char *arr2) {
    if (strlen(arr1) > strlen(arr2)) 
        printf("arr moi ngan hon arr ban dau.\n");
    else if (strlen(arr1) < strlen(arr2)) 
        printf("arr moi dai hon arr ban dau.\n");
    else 
        printf("Hai arr co do dai bang nhau.\n");
}

void in_hoa_arr(char *arr) {
    for (int i = 0; arr[i] != '\0'; i++) {
        arr[i] = toupper(arr[i]);
    }
    printf("arr in hoa: %s\n", arr);
}

void them_arr(char *arr1, char *arr2) {
    strcat(arr1, arr2);
    printf("arr sau khi them: %s\n", arr1);
}

int main() {
    char arr1[2000] = "", arr2[1000];
    int lua_chon;

    do {
        printf("\n--- menu ---\n");
        printf("1. Nhap vao arr\n");
        printf("2. In ra arr dao nguoc\n");
        printf("3. Dem so luong tu trong arr\n");
        printf("4. So sanh arr khac\n");
        printf("5. In hoa arr\n");
        printf("6. Them arr khac\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &lua_chon);
        getchar();

        switch (lua_chon) {
            case 1:
                nhap_arr(arr1);
                break;
            case 2:
                dao_nguoc_arr(arr1);
                break;
            case 3:
                printf("So tu trong arr: %d\n", dem_so_tu(arr1));
                break;
            case 4:
                printf("Nhap arr khac: ");
                nhap_arr(arr2);
                so_sanh_arr(arr1, arr2);
                break;
            case 5:
                in_hoa_arr(arr1);
                break;
            case 6:
                printf("Nhap arr de them: ");
                nhap_arr(arr2);
                them_arr(arr1, arr2);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (lua_chon != 7);

    return 0;
}