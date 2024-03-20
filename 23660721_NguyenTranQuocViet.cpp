#include <stdio.h>
#include <string.h>

struct MonHoc {
    char MSMH[20];
    char tenMH[50];
    float TK1, TK2, GK, CK, TH1, TH2, TH3;
    float diemTrungBinh;
};

struct SinhVien {
    char MSSV[20];
    char hoTen[50];
    struct MonHoc monHoc[10];
    int soMonHoc;
};

void xoaKhoangTrangThua(char *s) {
    int i, j;
    for (i = 0; s[i] != '\0';) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            for (j = i; s[j] != '\0'; ++j) {
                s[j] = s[j + 1];
            }
        } else {
            ++i;
        }
    }
}

float tinhDiemTrungBinh(float TK1, float TK2, float GK, float CK, float TH1, float TH2, float TH3) {
    float TBTK = (TK1 + TK2) / 2;
    float TBTH = (TH1 + TH2 + TH3) / 3;
    return (((TBTK * 0.2 + GK * 0.3 + CK * 0.5) * 2) + TBTH) / 3;
}

void sapXepTheoDiemTrungBinh(struct SinhVien *sv, int n) {
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (sv[i].monHoc[0].diemTrungBinh > sv[j].monHoc[0].diemTrungBinh) {
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

void sapXepTheoMSSV(struct SinhVien *sv, int n) {
    int i, j;
    for (i = 0; i < n - 1; ++i) {
        for (j = i + 1; j < n; ++j) {
            if (strcmp(sv[i].MSSV, sv[j].MSSV) > 0) {
                struct SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}

void nhapMonHoc(struct MonHoc *mh) {
    printf("Nhap MSMH: ");
    scanf("%s", mh->MSMH);
    printf("Nhap ten MH: ");
    scanf("%s", mh->tenMH);
    do {
        printf("Nhap diem TK1: ");
        scanf("%f", &mh->TK1);
        printf("Nhap diem TK2: ");
        scanf("%f", &mh->TK2);
        printf("Nhap diem GK: ");
        scanf("%f", &mh->GK);
        printf("Nhap diem CK: ");
        scanf("%f", &mh->CK);
        printf("Nhap diem TH1: ");
        scanf("%f", &mh->TH1);
        printf("Nhap diem TH2: ");
        scanf("%f", &mh->TH2);
        printf("Nhap diem TH3: ");
        scanf("%f", &mh->TH3);
        if (mh->TK1 < 0 || mh->TK1 > 10 || mh->TK2 < 0 || mh->TK2 > 10 || mh->GK < 0 || mh->GK > 10 ||
            mh->CK < 0 || mh->CK > 10 || mh->TH1 < 0 || mh->TH1 > 10 || mh->TH2 < 0 || mh->TH2 > 10 ||
            mh->TH3 < 0 || mh->TH3 > 10) {
            printf("Diem khong hop le. Vui long nhap lai!\n");
        }
    } while (mh->TK1 < 0 || mh->TK1 > 10 || mh->TK2 < 0 || mh->TK2 > 10 || mh->GK < 0 || mh->GK > 10 ||
             mh->CK < 0 || mh->CK > 10 || mh->TH1 < 0 || mh->TH1 > 10 || mh->TH2 < 0 || mh->TH2 > 10 ||
             mh->TH3 < 0 || mh->TH3 > 10);
}

void nhapSinhVien(struct SinhVien *sv) {
    printf("Nhap MSSV: ");
    scanf("%s", sv->MSSV);
    printf("Nhap ho va ten: ");
    scanf(" %[^\n]s", sv->hoTen);
    xoaKhoangTrangThua(sv->hoTen); 
    printf("Nhap so mon hoc: ");
    scanf("%d", &sv->soMonHoc);
    printf("Nhap thong tin cho tung mon hoc:\n");
    for (int i = 0; i < sv->soMonHoc; ++i) {
        printf("Mon hoc %d:\n", i + 1);
        nhapMonHoc(&sv->monHoc[i]);
        sv->monHoc[i].diemTrungBinh = tinhDiemTrungBinh(sv->monHoc[i].TK1, sv->monHoc[i].TK2, sv->monHoc[i].GK, sv->monHoc[i].CK, sv->monHoc[i].TH1, sv->monHoc[i].TH2, sv->monHoc[i].TH3);
    }
}

void hienThiKetQua(struct SinhVien *sv, int n) {
    printf("KET QUA HOC TAP\n");
    for (int i = 0; i < n; ++i) {
        printf("Ma so Sinh vien: %s\n", sv[i].MSSV);
        printf("Ho va ten: %s\n", sv[i].hoTen);
        printf("MSMH  Ten Mon hoc  Diem Trung binh  Ghi chu\n");
        for (int j = 0; j < sv[i].soMonHoc; ++j) {
            printf("%s\t%s\t\t%.2f\n", sv[i].monHoc[j].MSMH, sv[i].monHoc[j].tenMH, sv[i].monHoc[j].diemTrungBinh);
        }
    }
}
int main() {
    struct SinhVien dsSinhVien[100];
    int n;

    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        nhapSinhVien(&dsSinhVien[i]);
    }

    sapXepTheoDiemTrungBinh(dsSinhVien, n);
    printf("\nDanh sach sinh vien sap xep theo diem trung binh:\n");
    hienThiKetQua(dsSinhVien, n);

    sapXepTheoMSSV(dsSinhVien, n);
    printf("\nDanh sach sinh vien sap xep theo MSSV:\n");
    hienThiKetQua(dsSinhVien, n);

    return 0;
}

