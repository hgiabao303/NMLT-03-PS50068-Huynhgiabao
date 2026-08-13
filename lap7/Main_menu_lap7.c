#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Nguyên mẫu hàm (Function Prototypes)
void demNguyenAmPhuAm();
void kiemTraDangNhap();
void sapXepChuoi();
void thapPhanSangNhiPhan();
void xoaXuongDong(char s[]);

int main() {
    int luaChon;
    do {
        printf("\n+---------------------------------------------------+");
        printf("\n|              MENU CHUONG TRINH LAB 7              |");
        printf("\n+---------------------------------------------------+");
        printf("\n| 1. Dem Nguyen am va Phu am trong chuoi            |");
        printf("\n| 2. Dang nhap he thong (User & Password)           |");
        printf("\n| 3. Sap xep danh sach Chuoi theo thu tu Alphabet   |");
        printf("\n| 4. Chuyen doi so Thap phan sang Nhi phan (Chuoi)  |");
        printf("\n| 5. Thoat chuong trinh                             |");
        printf("\n+---------------------------------------------------+");
        printf("\n>> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &luaChon);
        getchar(); // Đọc bỏ ký tự '\n' còn sót lại trong bộ đệm bàn phím

        switch (luaChon) {
            case 1:
                demNguyenAmPhuAm();
                break;
            case 2:
                kiemTraDangNhap();
                break;
            case 3:
                sapXepChuoi();
                break;
            case 4:
                thapPhanSangNhiPhan();
                break;
            case 5:
                printf("\nDa thoat chuong trinh!\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon lai (1-5).\n");
        }
    } while (luaChon != 5);

    return 0;
}

// Hàm hỗ trợ xóa ký tự '\n' do fgets đọc vào
void xoaXuongDong(char s[]) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

// Chức năng 1: Đếm Nguyên âm và Phụ âm trong Chuỗi
void demNguyenAmPhuAm() {
    char s[100];
    int demNA = 0, demPA = 0;

    printf("\n--- CHUC NANG 1: DEM NGUYEN AM VA PHU AM ---\n");
    printf("Nhap vao chuoi ky tu: ");
    fgets(s, sizeof(s), stdin);
    xoaXuongDong(s);

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = tolower(s[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            demNA++;
        } else if (isalpha(ch)) { // Nếu là chữ cái nhưng không phải nguyên âm
            demPA++;
        }
    }

    printf("So nguyen am trong chuoi: %d\n", demNA);
    printf("So phu am trong chuoi: %d\n", demPA);
}

// Chức năng 2: Đăng nhập hệ thống
void kiemTraDangNhap() {
    char userSys[] = "admin";
    char passSys[] = "123456";
    char user[50], pass[50];

    printf("\n--- CHUC NANG 2: DANG NHAP HE THONG ---\n");
    printf("User: ");
    fgets(user, sizeof(user), stdin);
    xoaXuongDong(user);

    printf("Password: ");
    fgets(pass, sizeof(pass), stdin);
    xoaXuongDong(pass);

    if (strcmp(user, userSys) == 0 && strcmp(pass, passSys) == 0) {
        printf("Dang nhap thanh cong!\n");
    } else {
        printf("Username hoac Password khong chinh xac!\n");
    }
}

// Chức năng 3: Sắp xếp danh sách Chuỗi theo thứ tự Alphabet
void sapXepChuoi() {
    char s[5][50];
    char temp[50];

    printf("\n--- CHUC NANG 3: SAP XEP DANH SACH CHUOI ---\n");
    printf("Nhap vao 5 chuoi/ten:\n");
    for (int i = 0; i < 5; i++) {
        printf("Chuoi %d: ", i + 1);
        fgets(s[i], sizeof(s[i]), stdin);
        xoaXuongDong(s[i]);
    }

    // Thuật toán Bubble Sort dùng strcmp và strcpy
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (strcmp(s[i], s[j]) > 0) {
                strcpy(temp, s[i]);
                strcpy(s[i], s[j]);
                strcpy(s[j], temp);
            }
        }
    }

    printf("\nDanh sach sau khi sap xep Alphabet:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d. %s\n", i + 1, s[i]);
    }
}

// Chức năng 4: Chuyển đổi Thập phân sang Nhị phân bằng Chuỗi
void thapPhanSangNhiPhan() {
    int n;
    char nhiPhan[50] = "";
    int index = 0;

    printf("\n--- CHUC NANG 4: THAP PHAN SANG NHI PHAN ---\n");
    printf("Nhap vao so nguyen duong: ");
    scanf("%d", &n);
    getchar();

    if (n <= 0) {
        printf("Ket qua nhi phan: 0\n");
        return;
    }

    int tempN = n;
    while (tempN > 0) {
        nhiPhan[index++] = (tempN % 2) + '0';
        tempN /= 2;
    }
    nhiPhan[index] = '\0';

    // Đảo ngược chuỗi để có kết quả nhị phân chuẩn
    printf("So %d sang Nhi phan la: ", n);
    for (int i = index - 1; i >= 0; i--) {
        putchar(nhiPhan[i]);
    }
    printf("\n");
}