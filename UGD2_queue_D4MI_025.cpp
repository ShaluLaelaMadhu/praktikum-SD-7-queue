#include <iostream>
using namespace std;

typedef struct
{
	int data[100], head, tail;
}queue;

int batas;
queue antrian;

void MembuatAntrian()
{
	antrian.head = antrian.tail = -1;
}

int Kosong()
{
	if (antrian.tail == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Penuh()
{
	if (antrian.tail == batas - 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void Tambah(int data)
{
	int count = 0;
	system("cls");
	if (Kosong() == 1)
	{
		if (antrian.tail == -1)
		{
			antrian.head = antrian.tail = 0;
			antrian.data[antrian.tail] = data;
			cout << "Plat Nomor: " << data << " Telah Masuk Ke Antrian\n\n";
			system("pause"); system("cls");
		}
		else
		{
			cout << "Data Kosong\n\n";
			system("pause"); system("cls");
		}
	}
	else if (Kosong() == 0)
	{
		if (antrian.tail != batas - 1)
		{
			for (int x = antrian.head; x <= antrian.tail; x++)
			{
				if (data == antrian.data[x])
				{
					count++;
				}
			}

			if (count > 0)
			{
				cout << "Plat Nomor Sudah Terdaftar\n\n";
				system("pause"); system("cls");
			}
			else
			{
				for (int x = antrian.tail; x >= 0; x--)
				{
					antrian.data[x + 1] = antrian.data[x];
				}
				antrian.tail++;
				antrian.data[antrian.head] = data;
				cout << "Plat Nomor: " << data << " Telah Masuk Ke Antrian\n\n";
				system("pause"); system("cls");
			}
		}
		else
		{
			cout << "Antrian Sudah Penuh\n\n";
			system("pause"); system("cls");
		}
		
	}
	else
	{
		cout << "Antrian Sudah Penuh\n\n";
		system("pause"); system("cls");
	}
}

void Keluar(int data)
{
	int count = -1;
	do
	{
		count++;
	} while (data != antrian.data[count]);

	if (count == antrian.tail)
	{
		cout << "Plat Nomor: " << antrian.data[antrian.tail] << " Telah Keluar\n\n";
		antrian.tail--;
		system("pause"); system("cls");
	}
	else
	{
		system("cls");
		for (int x = antrian.tail; x >= count; x--)
		{
			cout << "Plat Nomor: " << antrian.data[x] << " Telah Keluar\n";
		}
		
		do
		{
			antrian.tail--;
		}while (antrian.tail != count - 1);
		cout << endl << endl;
		system("pause");
		system("cls");
	}
}

void HapusAntrian()
{
	antrian.head = antrian.tail = -1;
	cout << "Semua Antrian Telah Terhapus\n\n";
	system("pause"); system("cls");
}

void TampilkanAntrian()
{
	for (int x = antrian.head; x <= antrian.tail; x++)
	{
		cout << "Antrian Ke-" << x + 1 << ": " << antrian.data[x] << endl;
	}
}

void SalahMemasukkan()
{
	system("cls");
	cout << "Anda Salah Memasukkan Input\n\n";
	system("pause");
}

void KeluarProgram()
{
	system("cls");
	cout << "Anda Keluar Program \n\n";
	system("pause");
}

int main()
{
	MembuatAntrian();
	do
	{
		unsigned short int pil;
		int plat;
		system("cls");
		cout << "Sistem Antrian Parkiran Kendaraan\n\n";
		system("pause"); system("cls");
		cout << "Apakah anda ingin melanjutkan ?\n1. Iya\n2. Tidak\n\nPilihan: ";
		cin >> pil;
		switch (pil)
		{
		case 1: cout << "Masukkan Batas Kendaraan: "; cin >> batas;
			do
			{
				cout << "1. Antrian Parkir Kendaraan\n2. Keluarkan Kendaraan\n3. Hapus Semua Antrian\n4. Tampilkan Antrian Kendaraan\n5. Exit\n\nPilihan: ";
				cin >> pil; switch (pil)
				{
				case 1:
					cout << "Masukkan Plat Nomor: "; cin >> plat;
					Tambah(plat); break;
				case 2:
					TampilkanAntrian();
					cout << "Masukkan Plat Nomor: "; cin >> plat;
					Keluar(plat); break;
				case 3:
					HapusAntrian(); break;
				case 4:
					TampilkanAntrian();break;
				case 5:
					KeluarProgram();
					return 0; break;
				default:
					SalahMemasukkan();
					return 0; break;
				}
			} while (true);
		case 2:
			KeluarProgram();
			return 0; break;
		default:
			SalahMemasukkan();
			return 0; break;
		}
	} while (true);
}
