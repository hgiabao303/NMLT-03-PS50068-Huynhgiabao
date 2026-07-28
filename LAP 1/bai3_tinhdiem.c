#include <stdio.h>

int main() {
    // Khai báo điểm
    char mssv[20];
    char hoTen[100];
    float diemToan, diemLy, diemHoa;
    float diemTB;

    // nhập dữ liệu
    printf("Nhap ma so sinh vien (MSSV): ");
    scanf("%s", mssv);

    // Xóa bộ nhớ đệm trước khi nhập chuỗi tiếp theo để tránh bị trôi lệnh
    while (getchar() != '\n');

    printf("Nhap Ho va Ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    
    // Loại bỏ ký tự xuống dòng '\n' do fgets tự động thêm vào cuối chuỗi
    for (int i = 0; hoTen[i] != '\0'; i++) {
        if (hoTen[i] == '\n') {
            hoTen[i] = '\0';
            break;
        }
    }

    printf("Nhap diem Toan: ");
    scanf("%f", &diemToan);

    printf("Nhap diem Ly: ");
    scanf("%f", &diemLy);

    printf("Nhap diem Hoa: ");
    scanf("%f", &diemHoa);

    // tính toán
    // Công thức tính điểm trung bình nhân hệ số 2 cho môn Toán
    diemTB = (diemToan * 2 + diemLy + diemHoa) / 4.0;

    // xuất
    printf("\n--- KET QUA ---\n");
    printf("Ma so sinh vien: %s\n", mssv);
    printf("Ho Va Ten: %s\n", hoTen);
    // Xuất điểm trung bình làm tròn đến 2 chữ số thập phân
    printf("Diem Trung Binh: %.2f\n", diemTB);

    return 0;
}
