#include <stdio.h>

void nhaparr(int arr[], int *n) {
    printf("Nhap so phan tu: ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Phan tu [%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void inarrr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int tinhTong(int arr[], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += arr[i];
    }
    return tong;
}

int max(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[100];
    int n = 0, choice;

    do {
        printf("\n----- MENU -----\n");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. Hien thi cac phan tu trong mang\n");
        printf("3. Tinh do dai mang\n");
        printf("4. Tinh tong cac phan tu trong mang\n");
        printf("5. Hien thi phan tu lon nhat\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhaparr(arr, &n);
                break;
            case 2:
                inarrr(arr, n);
                break;
            case 3:
                printf("Do dai cua mang: %d\n", n);
                break;
            case 4:
                printf("Tong cac phan tu trong mang: %d\n", tinhTong(arr, n));
                break;
            case 5:
                printf("Phan tu lon nhat trong mang: %d\n", max(arr, n));
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