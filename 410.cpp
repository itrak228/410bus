#include <iostream>
#include <windows.h>
#include <string>
#include <limits>
/*
	���� ��������
	������� �������
	������
	�������/�������
	����������� �����
	������������ �����
	���
	������� ����
	����������



*/
//������� ������
int userCount = 2;
std::string* loginarr = new std::string[userCount]{ "admin","user" };
std::string* passwordarr = new std::string[userCount]{ "admin","user" };
//------------------------------------------------------------------------

//���������� ����������
int martini = 450, aleksandr = 700, old_fesion = 500, daykiry = 300, blue_laguna = 600, sex_on_beach = 400, b52 = 300, cosmopolyten = 550, manhetten = 600, kuznechik = 400;
int check;
std::string choose{};
//------------------------------------------------------------------------

//�����-------------------------------------------------------------------

//��� ����������� ��������� � ����
int size = 10;
int* idArr = new int[10];
double* countArr = new double[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];
//��� ����������� ������� ������ ��� ������������� ���������
int boutleSize = 13;
int* boutleArr = new int[boutleSize];
double* boutleCapacity = new double[boutleSize]; 
std::string* boutleNameArr = new std::string[boutleSize];
//------------------------------------------------------------------------
 
//========================================================================
//�������
/*
��� ���������� �����?
��� ������ ���� � �������� �����?
*/
//��� ����� �������
/*
������� ����������� �����������
�������� �� ������� �� � �������
������� ������� � �� ������������ (�� ��������� ������) PS. ������� ������� � ��� ���� ����
*/
//������ ������� �������� � �� �������
/*
//������ ��������
���� Barrister Dry Gin 0.5 �
������ Martini Bianco 1 �
Baileys Original 0.7 �(���������)
������ A. de Fussigny Selection 0.7
����� Gallant 0.5 �
����� Jim Beam White 0.7 �
��� Old Nick Carribean white 0.7 � (����� ���)
����� Fruko Schulz Peach Liqueur 0.7 �(����������)
����� Cointreau 0.7 � (������������)
����� Mozart, Dark Chocolate 0.5 � (����������\����� ����)
����� Kahlua 0.7 � (��������)
������ Martini Fiero 1 � (�������)
����� Branca Menta 0.7 � (������)
*/
//������� ���������
/*
�������
�������:
70�� Barrister Dry Gin
20�� Martini Bianco

���������:
20�� Mozart, Dark Chocolate
50�� A. de Fussigny Selection

��� ����:
25�� Jim Beam White

�������:
Old Nick Carribean white

������� ������:
50�� Gallant

���� �� �����:
40�� Gallant
40�� Fruko Schulz Peach Liqueur 

b52:
20�� Cointreau
20�� Kahlua
20�� Baileys Original

������������:
45�� Cointreau
45�� Gallant

���������:
30�� Martini Fiero
60�� Jim Beam White

��������:
30 �� Mozart, Dark Chocolate
5�� A. de Fussigny Selection
30�� Branca Menta
*/
//========================================================================

bool isAdmin = false;

//�������-----------------------------------------------------------------
void start();
bool Login();
void ShopAdminMenu();
void ShopUserMenu();
int sell();
int pricechange();
int profit();
void CreateStaticStorege();
template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size);
template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size);
void ShowStorage();

//------------------------------------------------------------------------


#if defined(max)
#undef max
#endif{


int main()
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	start();
	delete[]loginarr;
	delete[]passwordarr;
	delete[]idArr;
	delete[]countArr;
	delete[]priceArr;
	delete[]nameArr;
	delete[]boutleArr;
	delete[]boutleCapacity;
	delete[]boutleNameArr;

	return 0;
}
void start()
{
	
	std::cout << "\t\t\t\t410 �������\n\n\n";
	if (Login () == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		
		{
			std::string choose{};
			do
			{

				std::cout << "������������ ������� ����� ��� ������� �����?\n1 - ������� �����\n2 - ����� �����\n\n����: ";
				std::getline(std::cin, choose, '\n');
			} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 49); // ���������� ASCII ������� �� 0 �� 8 ���

			if (choose == "1")
			{
				CreateStaticStorege();
			}
			else
			{

			}
			ShopAdminMenu();
		}
		else
		{
			ShopUserMenu();
		}
	}
}
bool Login()
{
	while (true)
	{
		std::string login, pass;
		std::cout << "������� �����: ";
		std::getline(std::cin, login, '\n');
		std::cout << "������� ������: ";
		std::getline(std::cin, pass, '\n');
		
		for (int i = 1; i < userCount; i++)
		{
			if (login == loginarr[0] && pass == passwordarr[0])
			{
				std::cout << "����� ����������" << loginarr[0] << '\n';
				isAdmin = true;
				return true;
			}
			else if (login == loginarr[i] && pass == passwordarr[i])
			{
				std::cout << "����� ���������� " << loginarr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "������� ����� ����� ��� ������!\n\n";

	}

}
void ShopAdminMenu()
{
	std::cout <<"\t\t\tadmin menu\n";

	std::string choose{};
			// �������� �����
	while (true)
	{
		do
		{
			
			std::cout << "1. ������ �������\n";//done
			std::cout << "2. �������� �����\n";
			std::cout << "3. ��������� �����\n";
			std::cout << "4. ������� �� ������\n";
			std::cout << "5. �������� ����\n";//done
			std::cout << "6. �������� �����\n";
			std::cout << "7. �������� ��������\n";
			std::cout << "8. ����� � �������\n\n";
			std::cout << "0. ������� �����\n\n\n";

			std::cout << "����: \n";
			std::getline(std::cin, choose, '\n');




		} 
		while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // ���������� ASCII ������� �� 0 �� 8 ���

		if (choose == "1")
		{
			sell();
		}
		else if (choose == "2")
		{
			std::cout << "2\n";
			ShowStorage();
		}
		else if (choose == "3")
		{
			std::cout << "3\n";
		}
		else if (choose == "4")
		{
			std::cout << "4\n";
		}
		else if (choose == "8")
		{
			std::cout << "5\n";
		}
		else if (choose == "6")
		{
			std::cout << "6\n";
		}
		else if (choose == "7")
		{
			std::cout << "7\n";
		}
		else if (choose == "5")
		{
			pricechange();

		}
		else if (choose == "0")
		{
			std::cout << "0\n";
		}
		else
		{
			std::cerr << "AdminMenuError";
		}
		break;
	}

} 
void ShopUserMenu()

{
	
	std::cout << "user menu";


	std::string choose{};
	// �������� �����
	while (true)
	{
		
		do
		{
			
			std::cout << "1. ������ �������\n";
			std::cout << "2. �������� �����\n";
			std::cout << "3. ��������� �����\n";
			std::cout << "4. ������� �� ������\n";
			std::cout << "5. �������� ����\n";//-
			std::cout << "6. �������� �����\n";//-
			std::cout << "7. �������� ��������\n";//-
			std::cout << "8. ����� � �������\n\n";
			std::cout << "0. ������� �����\n\n\n";

			std::cout << "����: ";
			std::getline(std::cin, choose, '\n');




		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // ���������� ASCII ������� �� 0 �� 8 ���

		if (choose == "1")
		{
			std::cout << "me";
		}
		else if (choose == "2")
		{

		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			std::cerr << "AdminMenuError";
		}
		// �� ������ �������� �������� ���� �������
		break;
	}
}

int sell ()
{
	int choise;
	std::string choose{};
	std::cout << "\t\t������ �������\n\n";
	std::cout << "0. �������\t\t450\n";
	std::cout << "1. ��������\t\t700\n";
	std::cout << "2. ��� ����\t\t500\n";
	std::cout << "3. �������\t\t300\n";
	std::cout << "4. ������� ������\t600\n";
	std::cout << "5. ���� �� �����\t400\n";
	std::cout << "6. b52\t\t\t300\n";
	std::cout << "7. ������������\t\t550\n";
	std::cout << "8. ���������\t\t600\n";
	std::cout << "9. ��������\t\t400\n";

	std::cout << "�� ������ ������� �����?\n���� �� �� ������� 1, ����� ������� 2\n";
	std::cin >> choise;

	if (choise > 2 || choise < 1)
	{
		std::cout << "�� ���������";
		choise = 0;
		sell();
	}
	else if (choise == 1)
	{

		while (choise != 2)
		{
			std::cout << "�������� �������: ";
			std::getline(std::cin, choose, '\n');
			if (choose == "0")
			{
				std::cout << "����� ����� 0\n";
				check += martini;
				std::cout << "��� = " << check<<"\n";
				sell();

			}
			else if (choose == "1")
			{
				std::cout << "����� ����� 1\n";
				check += aleksandr;
				std::cout << "��� = " << check << "\n";
				sell();
			}
			else if (choose == "2")
			{
				std::cout << "����� ����� 2";
				check += old_fesion;
				std::cout << "��� = " << check << "\n";
				sell();
			}
			else if (choose == "3")
			{
				std::cout << "����� ����� 3";
				check += daykiry;
				std::cout << "��� = " << check << "\n";
				sell();
			}
			else if (choose == "4")
			{
				std::cout << "����� ����� 4";
				check += blue_laguna;
				std::cout << "��� = " << check << "\n";
				sell();
			}
			else if (choose == "5")
			{
				std::cout << "����� ����� 5";
				check += sex_on_beach;
				std::cout << "��� = " << check << "\n";
				sell();
			}
			else if (choose == "6")
			{
				std::cout << "����� ����� 6";
				check += b52;
				std::cout << "��� = " << check << "\n";
				sell();
			}
			else if (choose == "7")
			{
				std::cout << "����� ����� 7";
				check += cosmopolyten;
				std::cout << "��� = " << check << "\n";
				sell();
			}
			else if (choose == "8")
			{
				std::cout << "����� ����� 8";
				check += manhetten;
				std::cout << "��� = " << check << "\n";
				sell();
			}
			else if (choose == "9")
			{
				std::cout << "����� ����� 9";
				check += kuznechik;
				std::cout << "��� = " << check << "\n";
				sell();
			}
			else
			{
				std::cerr << "AdminMenuError\n";
			}
		}
	}
	else if (choise == 2)
	{
		ShopAdminMenu();
	}
	return 0;
}
int pricechange()
{
	int choise, choise2;
			
				std::cout << "�� ������ �������� ����?\n���� �� �� ������� 1, ����� 2\n";
				std::cin >> choise;
				if (choise == 2)
				{
					ShopAdminMenu();
				}
				else if (choise == 1)
				{
					std::cout << "\t\t����� ����\n\n";
					std::cout << "0. �������\t\t450\n";
					std::cout << "1. ��������\t\t700\n";
					std::cout << "2. ��� ����\t\t500\n";
					std::cout << "3. �������\t\t300\n";
					std::cout << "4. ������� ������\t600\n";
					std::cout << "5. ���� �� �����\t400\n";
					std::cout << "6. b52\t\t\t300\n";
					std::cout << "7. ������������\t\t550\n";
					std::cout << "8. ���������\t\t600\n";
					std::cout << "9. ��������\t\t400\n";
					std::cout << "����� ���� ������� �� ������ ��������?\n";
					std::cin>> choise2;
					if (choise2 < 0 || choise2 > 9)
					{
						std::cout << "�� �� ����� ���������";

					}
					else
					{
						if (choise2 == 0)
						{
							std::cout << "������ ���� ������� ����� " << martini << " ������� ����� �� ������� ������ �������� ���� \n";
							std::cin >> martini;

							std::cout << "������ ���� ������� ����� " << martini << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 1)
						{
							std::cout << "������ ���� ���������� ����� " << aleksandr << " ������� ����� �� ������� ������ �������� ���� \n";
							std::cin >> aleksandr;

							std::cout << "������ ���� ���������� ����� " << aleksandr << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 2)
						{
							std::cout << "������ ���� ��� ������ ����� " << old_fesion << " ������ ����� �� ������� ������ �������� ���� \n";
							std::cin >> old_fesion;

							std::cout << "������ ���� ��� ������ ����� " << old_fesion << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 3)
						{
							std::cout << "������ ���� ������� ����� " << daykiry << " ������� ����� �� ������� ������ �������� ���� \n";
							std::cin >> daykiry;

							std::cout << "������ ���� ������� ����� " << daykiry << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 4)
						{
							std::cout << "������ ���� ������� ������ �����"<< blue_laguna << " ������� ����� �� ������� ������ �������� ���� \n";
							std::cin >> blue_laguna;

							std::cout << "������ ���� ������� ������ �����" << blue_laguna << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 5)
						{
							std::cout<< "������ ���� ����� �� ����� ����� "<< sex_on_beach << " ������� ����� �� ������� ������ �������� ���� \n";
							std::cin >> sex_on_beach;

							std::cout << "������ ���� ����� �� ����� ����� " << sex_on_beach << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 6)
						{
							std::cout << "������ ���� b 52 ����� " << b52 << " ������� ����� �� ������� ������ �������� ���� \n";
							std::cin >> b52;

							std::cout << "������ ���� b52 ����� " << b52 << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 7)
						{
							std::cout << "������ ���� ������������� ����� " << cosmopolyten << " ������� ����� �� ������� ������ �������� ���� \n";
							std::cin >> cosmopolyten;

							std::cout << "������ ���� ������������� ����� " << cosmopolyten << "\n";
							ShopAdminMenu(); 
						}
						else if (choise2 == 8)
						{
							std::cout << "������ ���� ���������� ����� " << manhetten << " ������� ����� �� ������� ������ �������� ���� \n";
							std::cin >> manhetten;

							std::cout << "������ ���� ���������� ����� " << manhetten << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 9)
						{
							std::cout << "������ ���� ��������� ����� " << kuznechik << " ������� ����� �� ������� ������ �������� ���� \n";
							std::cin >> kuznechik;

							std:: cout << "������ ���� ��������� ����� " << kuznechik << "\n";
							ShopAdminMenu();
						}
					}


				}
				return 0;
}
int profit()
{
	std::cout << "d";
	return 0;
}
void CreateStaticStorege()
{
	const int staticSizeBoutle = 13;
	const int staticSize = 10;
	int idStaticArr[staticSize]
	{ 1,2,3,4,5,6,7,8,9,0 };
	double priceStaticArr[staticSize]
	{ 450.0,700.0,500.0,300.0,600.0,400.0,300.0,550.0,600.0,400.0 };
	std::string nameStaticArr[staticSize]
	{ 
		"�������\t","���������",
		"��� ����","�������\t",
		"������� ������","���� �� �����",
		"b52\t","������������",
		"���������","��������"
	};
	std::string nameStaticArrBoutle[staticSizeBoutle]
	{
		"���� Barrister Dry Gin", "������ Martini Bianco", "���� Baileys Original", "������ A. de Fussigny Selection", "����� Gallant",
		"����� Jim Beam White", "��� Old Nick Carribean white", "����� Fruko Schulz Peach Liqueur", "����� Cointreau",
		"����� Mozart, Dark Chocolate", "����� Kahlua", "������ Martini Fiero", "����� Branca Menta"
	};
	
	SetArr (idStaticArr, idArr, staticSize);
	SetArr(priceStaticArr, priceArr, staticSize);
	SetArr(nameStaticArr, nameArr, staticSize);
	SetArr(nameStaticArrBoutle, boutleNameArr, staticSizeBoutle);
	/*PrintArr(idArr, staticSize);
	PrintArr(priceArr, staticSize);
	PrintArr(nameArr, staticSize);
	PrintArr(boutleNameArr, staticSizeBoutle);*/
	



}

template<typename ArrType>
void SetArr(ArrType staticArr, ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}
template<typename ArrType>
void PrintArr(ArrType dynamicArr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << dynamicArr[i] << " ";

	}
	std::cout << "\n";
}
void ShowStorage()
{
	std::cout << "ID\t��������\t\t\t����\t��������\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << nameArr[i] << "\t\t"
			<< priceArr[i] << "\t\t" << boutleNameArr[i] << "\t\n";
	}

}