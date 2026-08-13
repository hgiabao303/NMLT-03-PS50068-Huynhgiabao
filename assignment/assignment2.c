#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Định nghĩa cấu trúc SinhVien cho Chức năng 9
struct SinhVien {
    char ten[50];
    float diem;
    char hocLuc[20];
};

// Khai báo các hàm chức năng
void chucNang1();
void chucNang2();
void chucNang3();
void chucNang4();
void chucNang5();
void chucNang6();
void chucNang7();
void chucNang8();
void chucNang9();
void chucNang10();

int main() {
    int chon;
    do {
        printf("\n================= ASSIGNMENT NMLT =================");
        printf("\n1. Kiem tra so nguyen");
        printf("\n2. Tim UCLN va BCNN cua 2 so");
        printf("\n3. Tinh tien karaoke");
        printf("\n4. Tinh tien dien");
        printf("\n5. Chuc nang doi tien");
        printf("\n6. Tinh lai suat vay ngan hang tra gop");
        printf("\n7. Vay tien mua xe");
        printf("\n8. Sắp xep thong tin sinh vien");
        printf("\n9. Game FPOLY-LOTT (2/15)");
        printf("\n10. Tinh toan phan so");
        printf("\n0. Thoat chuong trinh");
        printf("\n==================================================");
        printf("\nChon chuc nang (0-10): ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 0: printf("\nDa thoat chuong trinh. Tam biệt!\n"); break;
            default: printf("\nChon sai! Vui long chon tu 0 den 10.\n");
        }
    } while (chon != 0);

    return 0;
}

// -------------------------------------------------------------
// CHỨC NĂNG 1: KIỂM TRA SỐ NGUYÊN / SỐ CHÍNH PHƯƠNG / SỐ NGUYÊN TỐ
void chucNang1() {
    float x;
    printf("\n--- CHUC NANG 1: KIEM TRA SO ---");
    printf("\nNhap vao x: ");
    scanf("%f", &x);

    // Kiem tra so nguyen
    if (x == (int)x) {
        int n = (int)x;
        printf("\n%.0f la so nguyen.", x);

        // Kiem tra so nguyen to
        int isNguyenTo = 1;
        if (n < 2) isNguyenTo = 0;
        else {
            for (int i = 2; i <= sqrt(n); i++) {
                if (n % i == 0) { isNguyenTo = 0; break; }
            }
        }
        if (isNguyenTo) printf("\n%.0f la so nguyen to.", x);
        else printf("\n%.0f KHONG phai so nguyen to.", x);

        // Kiem tra so chinh phuong
        int sq = sqrt(n);
        if (sq * sq == n) printf("\n%.0f la so chinh phuong.\n", x);
        else printf("\n%.0f KHONG phai so chinh phuong.\n", x);

    } else {
        printf("\n%.2f KHONG phai la so nguyen.\n", x);
    }
}

// -------------------------------------------------------------
// CHỨC NĂNG 2: TÌM UCLN VÀ BCNN CỦA 2 SỐ
int timUCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void chucNang2() {
    int a, b;
    printf("\n--- CHUC NANG 2: UCLN & BCNN ---");
    printf("\nNhap a: "); scanf("%d", &a);
    printf("Nhap b: "); scanf("%d", &b);

    int ucln = timUCLN(a, b);
    int bcnn = (a * b) / ucln;

    printf("UCLN(%d, %d) = %d\n", a, b, ucln);
    printf("BCNN(%d, %d) = %d\n", a, b, bcnn);
}

// -------------------------------------------------------------
// CHỨC NĂNG 3: TÍNH TIỀN KARAOKE
void chucNang3() {
    int gioBatDau, gioKetThuc;
    printf("\n--- CHUC NANG 3: TINH TIEN KARAOKE ---");
    printf("\nNhap gio bat dau (12-23): "); scanf("%d", &gioBatDau);
    printf("Nhap gio ket thuc (12-23): "); scanf("%d", &gioKetThuc);

    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("Gio khong hop le! Quan chi mo cua tu 12h-23h.\n");
        return;
    }

    int tongGio = gioKetThuc - gioBatDau;
    double tongTien = 0;

    if (tongGio <= 3) {
        tongTien = tongGio * 150000;
    } else {
        tongTien = 3 * 150000 + (tongGio - 3) * 150000 * 0.7; // Giam 30% cho gio thu 4 tro di
    }

    // Giam 10% neu vao ca tu 14h-17h
    if (gioBatDau >= 14 && gioBatDau <= 17) {
        tongTien = tongTien * 0.9;
    }

    printf("Tong tien thanh toan: %.0f VN\n", tongTien);
}

// -------------------------------------------------------------
// CHỨC NĂNG 4: TÍNH TIỀN ĐIỆN
void chucNang4() {
    float kwh, tien;
    printf("\n--- CHUC NANG 4: TINH TIEN DIEN ---");
    printf("\nNhap so kWh tieu thu: "); scanf("%f", &kwh);

    if (kwh <= 50) tien = kwh * 1678;
    else if (kwh <= 100) tien = 50 * 1678 + (kwh - 50) * 1734;
    else if (kwh <= 200) tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    else if (kwh <= 300) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    else if (kwh <= 400) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    else tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;

    printf("Tien dien phai tra: %.0f VND\n", tien);
}

// -------------------------------------------------------------
// CHỨC NĂNG 5: ĐỔI TIỀN
void chucNang5() {
    int meGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soTien;
    printf("\n--- CHUC NANG 5: DOI TIEN ---");
    printf("\nNhap so tien can doi: "); scanf("%d", &soTien);

    printf("Ket qua doi tien:\n");
    for (int i = 0; i < 9; i++) {
        int soTo = soTien / meGia[i];
        if (soTo > 0) {
            printf("- %d to me gia %d\n", soTo, meGia[i]);
            soTien %= meGia[i];
        }
    }
}

// -------------------------------------------------------------
// CHỨC NĂNG 6: TÍNH LÃI SUẤT VAY NGÂN HÀNG TRẢ GÓP
void chucNang6() {
    double tienVay = 500000000; // 500 trieu
    double laiSuatThang = 0.05;  // 5%/thang
    int kyHan = 12;               // 12 thang

    double gocPhaiTra = tienVay / kyHan;
    double tongPhaiTra = 0;

    printf("\n--- CHUC NANG 6: TINH LAI VAY TRẢ GÓP ---");
    printf("\nKỳ\tTiền gốc\tTiền lãi\tTổng trả\tCòn lại\n");

    for (int i = 1; i <= kyHan; i++) {
        double laiPhaiTra = tienVay * laiSuatThang;
        double tienThang = gocPhaiTra + laiPhaiTra;
        tienVay -= gocPhaiTra;
        tongPhaiTra += tienThang;

        printf("%d\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n", i, gocPhaiTra, laiPhaiTra, tienThang, tienVay);
    }
    printf("--> Tong tien tra sau 12 thang: %.0f VND\n", tongPhaiTra);
}

// -------------------------------------------------------------
// CHỨC NĂNG 7: VAY TIỀN MUA XE
void chucNang7() {
    double phanTramVay;
    printf("\n--- CHUC NANG 7: VAY MUA XE ---");
    printf("\nNhap %% muon vay (VD: 80): "); scanf("%lf", &phanTramVay);

    double giaXe = 500000000;
    double tienTraDau = giaXe * (100 - phanTramVay) / 100;
    double tienVay = giaXe - tienTraDau;

    printf("So tien tra truoc: %.0f VND\n", tienTraDau);
    printf("So tien vay: %.0f VND\n", tienVay);
}

// -------------------------------------------------------------
// CHỨC NĂNG 8: SẮP XẾP THÔNG TIN SINH VIÊN
void chucNang8() {
    int n;
    printf("\n--- CHUC NANG 8: SAP XEP SINH VIEN ---");
    printf("\nNhap so luong sinh vien: "); scanf("%d", &n);

    struct SinhVien ds[n];
    for (int i = 0; i < n; i++) {
        getchar(); // Xoa bo nho dem
        printf("Nhap ten SV %d: ", i + 1);
        gets(ds[i].ten);
        printf("Nhap diem SV %d: ", i + 1);
        scanf("%f", &ds[i].diem);

        if (ds[i].diem >= 9) strcpy(ds[i].hocLuc, "Xuat sac");
        else if (ds[i].diem >= 8) strcpy(ds[i].hocLuc, "Gioi");
        else if (ds[i].diem >= 6.5) strcpy(ds[i].hocLuc, "Kha");
        else if (ds[i].diem >= 5) strcpy(ds[i].hocLuc, "Trung binh");
        else strcpy(ds[i].hocLuc, "Yeu");
    }

    // Sap xep giam dan theo diem
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].diem < ds[j].diem) {
                struct SinhVien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    printf("\nDANH SACH SINH VIEN DA SAP XEP GIAM DAN:\n");
    for (int i = 0; i < n; i++) {
        printf("Ten: %-20s | Diem: %.1f | Hoc luc: %s\n", ds[i].ten, ds[i].diem, ds[i].hocLuc);
    }
}

// -------------------------------------------------------------
// CHỨC NĂNG 9: GAME LOTT (XỔ SỐ)
void chucNang9() {
    int so1, so2;
    printf("\n--- CHUC NANG 9: GAME FPOLY LOTT ---");
    printf("\nNhap 2 so may man (tu 01-15): ");
    scanf("%d%d", &so1, &so2);

    int r1 = rand() % 15 + 1;
    int r2 = rand() % 15 + 1;

    printf("Ket qua so xố: %d va %d\n", r1, r2);

    int trung = 0;
    if (so1 == r1 || so1 == r2) trung++;
    if (so2 == r1 || so2 == r2) trung++;

    if (trung == 2) printf("CHUC MUNG! Ban da trung GIẢI NHẤT!\n");
    else if (trung == 1) printf("CHUC MUNG! Ban da trung GIẢI NHÌ!\n");
    else printf("Rất tiếc! Chúc bạn may mắn lần sau.\n");
}

// -------------------------------------------------------------
// CHỨC NĂNG 10: TÍNH TOÁN PHÂN SỐ
typedef struct {
    int tu;
    int mau;
} PhanSo;

void chucNang10() {
    PhanSo p1, p2, tong, hieu, tich, thuong;
    printf("\n--- CHUC NANG 10: TINH TOAN PHAN SO ---");
    printf("\nNhap Tu/Mau phan so 1: "); scanf("%d%d", &p1.tu, &p1.mau);
    printf("Nhap Tu/Mau phan so 2: "); scanf("%d%d", &p2.tu, &p2.mau);

    // Tống
    tong.tu = p1.tu * p2.mau + p2.tu * p1.mau;
    tong.mau = p1.mau * p2.mau;

    // Hiệu
    hieu.tu = p1.tu * p2.mau - p2.tu * p1.mau;
    hieu.mau = p1.mau * p2.mau;

    // Tích
    tich.tu = p1.tu * p2.tu;
    tich.mau = p1.mau * p2.mau;

    // Thương
    thuong.tu = p1.tu * p2.mau;
    thuong.mau = p1.mau * p1.tu;

    printf("Tong = %d/%d\n", tong.tu, tong.mau);
    printf("Hieu = %d/%d\n", hieu.tu, hieu.mau);
    printf("Tich = %d/%d\n", tich.tu, tich.mau);
    printf("Thuong = %d/%d\n", thuong.tu, thuong.mau);
}
