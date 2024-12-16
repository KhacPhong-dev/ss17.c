#include <stdio.h>

void nhap_mang(int *arr, int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void in_chan(int *arr, int n) {
    printf("Cac phan tu chan trong mang: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int la_so_nguyen_to(int x) {
    if (x < 2) return 0;
    for (int i = 2; i < x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void in_nguyen_to(int *arr, int n) {
    printf("Cac phan tu la so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (la_so_nguyen_to(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void dao_nguoc_mang(int *arr, int n) {
    printf("Mang dao nguoc: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sap_xep_tang_dan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sap_xep_giam_dan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void tim_kiem_mang(int *arr, int n, int x) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d tim thay tai vi tri %d\n", x, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Phan tu %d khong tim thay trong mang.\n", x);
    }
}

int main() {
    int arr[100], n, lua_chon, x;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Sap xep mang\n");
        printf("   1. Tang dan\n");
        printf("   2. Giam dan\n");
        printf("6. Tim kiem phan tu\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &lua_chon);

        switch (lua_chon) {
            case 1:
                nhap_mang(arr, &n);
                break;
            case 2:
                in_chan(arr, n);
                break;
            case 3:
                in_nguyen_to(arr, n);
                break;
            case 4:
                dao_nguoc_mang(arr, n);
                break;
            case 5:
                printf("Lua chon sap xep:\n");
                printf("1. Tang dan\n");
                printf("2. Giam dan\n");
                printf("Lua chon: ");
                int lua_chon2;
                scanf("%d", &lua_chon2);
                if (lua_chon2 == 1) {
                    sap_xep_tang_dan(arr, n); 
                } else if (lua_chon2 == 2) {
                    sap_xep_giam_dan(arr, n); 
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            case 6:
                printf("Nhap phan tu can tim: ");
                scanf("%d", &x);
                tim_kiem_mang(arr, n, x);
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