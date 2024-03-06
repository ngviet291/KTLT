#include<stdio.h>
struct nhanvien
{
	int code;
	char name[20];
	double salary;
	double allowance;
};
void Nhapthongtin(struct nhanvien *nv)
{
	printf("Nhap ma nhan vien: ");
    scanf("%d", nv->code);
    printf("Nhap ten nhan vien: ");
    scanf("%s", nv->name);
    printf("Nhap luong: ");
    scanf("%lf", &nv->salary);
    printf("Nhap phu cap: ");
    scanf("%lf", &nv->allowance);
}
void timthongtin(struct nhanvien *ds,int n)
{
	char ten[20];
	printf("Nhap ten nhan vien can tim:");
	scanf("%c",&ten);
	int timthay=0;
	for(int i=0;i<n;i++)
	{
		if(ds[i].name == ten)
		{
			printf("Thong tin nhan vien:\n");
            printf("Ma nhan vien: %d\n", ds[i].code);
            printf("Ten nhan vien: %c\n", ds[i].name);
            printf("Luong: %.2lf\n", ds[i].salary);
            printf("Phu cap: %.2lf\n", ds[i].allowance);
            timthay = 1;
            break;
		}
		if (!timthay) {
        printf("Khong tim thay nhan vien co ten %c\n", ten);
    	}
	}
}
void xoanhanvien(struct nhanvien *ds,int *n)
{
	int ma;
	printf("Nhap ma nhan vien can xoa: ");
	scanf("%d",&ma);
	int vt = -1;
    for (int i = 0; i < *n; i++) {
        if (ds[i].code==ma) {
            vt = i;
            break;
        }
	}
	if (vt != -1) {
        for (int i = vt; i < *n - 1; i++) {
            ds[i] = ds[i + 1];
        }
        (*n)--;
        printf("Da xoa nhan vien co ma %s\n", ma);
    } else {
        printf("Khong tim thay nhan vien co ma %s\n", ma);
    }
}

void SapXepTheoLuong(struct nhanvien *ds, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ds[i].salary + ds[i].allowance > ds[j].salary + ds[j].allowance) {
                struct nhanvien temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }
    printf("Danh sach nhan vien sau khi sap xep theo luong:\n");
    for (int i = 0; i < n; i++) {
        printf("Ma nhan vien: %s, Ten nhan vien: %s, Luong: %.2lf, Phu cap: %.2lf\n", ds[i].code, ds[i].name, ds[i].salary, ds[i].allowance);
    }
}

int main()
{
	int n;
	printf("Nhap so luong nhan vien:");
	scanf("%d",&n);
	struct nhanvien ds[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin cho nhan vien thu %d:\n", i + 1);
        Nhapthongtin(&ds[i]);
    }
    timthongtin(ds, n);
    xoanhanvien(ds, &n);
    SapXepTheoLuong(ds, n);
    return 0;
	
}