#include <stdio.h>
#include <string.h>

// Định nghĩa Cấu trúc SinhVien
struct SinhVien {
    char mssv[50];
    char tenSV[50];
    char nganhHoc[50];
    float diemTB;
};

// Nguyên mẫu hàm (Function Prototypes)
void nhapXuatSinhVien(struct SinhVien mangSV[], int *n);
void sapXepSinhVien(struct SinhVien mangSV[], int n);
void timKiemSinhVien(struct SinhVien mangSV[], int n);
void xuatHocBong(struct SinhVien mangSV[], int n);
void xoaXuongDong(char s[]);

int main() {
    struct SinhVien mangSV[100];
    int n = 0;
    int luaChon;

    do {
        printf("\n+---------------------------------------------------+");
        printf("\n|        HE THONG QUAN LY SINH VIEN (LAB 8)         |");
        printf("\n+---------------------------------------------------+");
        printf("\n| 1. Nhap va Xuat danh sach sinh vien               |");
        printf("\n| 2. Sap xep sinh vien theo diem TB tang dan        |");
        printf("\n| 3. Tim kiem sinh vien theo Ma so sinh vien (MSSV) |");
        printf("\n| 4. Xuat danh sach sinh vien dat Hoc bong (>= 8.0)  |");
        printf("\n| 5. Thoat chuong trinh                             |");
        printf("\n+---------------------------------------------------+");
        printf("\n>> Xin moi chon chuc nang (1-5): ");
        scanf("%d", &luaChon);
        getchar(); // Đọc bỏ ký tự '\n' còn sót lại trong bộ đệm

        switch (luaChon) {
            case 1:
                nhapXuatSinhVien(mangSV, &n);
                break;
            case 2:
                if (n == 0) {
                    printf("\nDanh sach sinh vien dang trong! Vui long chon Chuc nang 1 truoc.\n");
                } else {
                    sapXepSinhVien(mangSV, n);
                }
                break;
            case 3:
                if (n == 0) {
                    printf("\nDanh sach sinh vien dang trong! Vui long chon Chuc nang 1 truoc.\n");
                } else {
                    timKiemSinhVien(mangSV, n);
                }
                break;
            case 4:
                if (n == 0) {
                    printf("\nDanh sach sinh vien dang trong! Vui long chon Chuc nang 1 truoc.\n");
                } else {
                    xuatHocBong(mangSV, n);
                }
                break;
            case 5:
                printf("\nDa thoat chuong trinh. Cam on ban da su dung!\n");
                break;
            default:
                printf("\nLua chon khong hop le! Vui long chon lai tu 1 den 5.\n");
        }
    } while (luaChon != 5);

    return 0;
}

// Hàm hỗ trợ loại bỏ ký tự '\n' khi dùng fgets
void xoaXuongDong(char s[]) {
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }
}

// Chức năng 1: Nhập và Xuất danh sách sinh viên
void nhapXuatSinhVien(struct SinhVien mangSV[], int *n) {
    printf("\n--- CHUC NANG 1: NHAP VA XUAT DANH SACH SINH VIEN ---\n");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", n);
    getchar();

    for (int i = 0; i < *n; i++) {
        printf("\n--- Nhap thong tin sinh vien thu %d ---\n", i + 1);
        printf("MSSV: ");
        fgets(mangSV[i].mssv, sizeof(mangSV[i].mssv), stdin);
        xoaXuongDong(mangSV[i].mssv);

        printf("Ho va ten: ");
        fgets(mangSV[i].tenSV, sizeof(mangSV[i].tenSV), stdin);
        xoaXuongDong(mangSV[i].tenSV);

        printf("Nganh hoc: ");
        fgets(mangSV[i].nganhHoc, sizeof(mangSV[i].nganhHoc), stdin);
        xoaXuongDong(mangSV[i].nganhHoc);

        printf("Diem trung binh: ");
        scanf("%f", &mangSV[i].diemTB);
        getchar();
    }

    printf("\n======================= DANH SACH SINH VIEN =======================\n");
    printf("%-5s | %-12s | %-25s | %-15s | %-8s\n", "STT", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < *n; i++) {
        printf("%-5d | %-12s | %-25s | %-15s | %-8.2f\n", 
               i + 1, mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
    }
    printf("===================================================================\n");
}

// Chức năng 2: Sắp xếp sinh viên theo điểm TB tăng dần
void sapXepSinhVien(struct SinhVien mangSV[], int n) {
    struct SinhVien temp;
    
    // Thuật toán Selection Sort / Bubble Sort hoán đổi toàn bộ struct
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mangSV[i].diemTB > mangSV[j].diemTB) {
                temp = mangSV[i];
                mangSV[i] = mangSV[j];
                mangSV[j] = temp;
            }
        }
    }

    printf("\n=== DANH SACH SINH VIEN SAU KHU SAP XEP (DIEM TB TANG DAN) ===\n");
    printf("%-5s | %-12s | %-25s | %-15s | %-8s\n", "STT", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-5d | %-12s | %-25s | %-15s | %-8.2f\n", 
               i + 1, mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
    }
    printf("===================================================================\n");
}

// Chức năng 3: Tìm kiếm sinh viên theo MSSV
void timKiemSinhVien(struct SinhVien mangSV[], int n) {
    char mssvTim[50];
    int found = 0;

    printf("\n--- CHUC NANG 3: TIM KIEM SINH VIEN THEO MSSV ---\n");
    printf("Nhap MSSV can tim: ");
    fgets(mssvTim, sizeof(mssvTim), stdin);
    xoaXuongDong(mssvTim);

    for (int i = 0; i < n; i++) {
        if (strcmp(mangSV[i].mssv, mssvTim) == 0) {
            if (!found) {
                printf("\n--- TIM THAY SINH VIEN ---\n");
                printf("%-12s | %-25s | %-15s | %-8s\n", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
                printf("-----------------------------------------------------------\n");
            }
            printf("%-12s | %-25s | %-15s | %-8.2f\n", 
                   mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nKhong tim thay sinh vien co MSSV: %s!\n", mssvTim);
    }
}

// Chức năng 4: Xuất danh sách sinh viên đạt Học bổng (>= 8.0)
void xuatHocBong(struct SinhVien mangSV[], int n) {
    int count = 0;

    printf("\n================ DANH SACH SINH VIEN DAT HOC BONG (>= 8.0) ================\n");
    printf("%-5s | %-12s | %-25s | %-15s | %-8s\n", "STT", "MSSV", "Ho va Ten", "Nganh Hoc", "Diem TB");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        if (mangSV[i].diemTB >= 8.0) {
            count++;
            printf("%-5d | %-12s | %-25s | %-15s | %-8.2f\n", 
                   count, mangSV[i].mssv, mangSV[i].tenSV, mangSV[i].nganhHoc, mangSV[i].diemTB);
        }
    }

    if (count == 0) {
        printf("Khong co sinh vien nao dat hoc bong (diem TB >= 8.0)!\n");
    }
    printf("===========================================================================\n");
}
