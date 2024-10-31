#include <iostream>
#include <windows.h>
#include <string>
#include <limits>
/*
	меню магазина
	система продажи
	скидки
	нейминг/запреты
	управляемый склад
	динамический склад
	чек
	чистота кода
	коментарии



*/
//учётные записи
int userCount = 2;
std::string* loginarr = new std::string[userCount]{ "admin","user" };
std::string* passwordarr = new std::string[userCount]{ "admin","user" };
//------------------------------------------------------------------------

//глобальные переменные
int martini = 450, aleksandr = 700, old_fesion = 500, daykiry = 300, blue_laguna = 600, sex_on_beach = 400, b52 = 300, cosmopolyten = 550, manhetten = 600, kuznechik = 400;
int check;
std::string choose{};
//------------------------------------------------------------------------

//склад-------------------------------------------------------------------

//тут колличество коктейлей в меню
int size = 10;
int* idArr = new int[10];
double* countArr = new double[size];
double* priceArr = new double[size];
std::string* nameArr = new std::string[size];
//тут колличество бутылок нужных для приготовления коктейлей
int boutleSize = 13;
int* boutleArr = new int[boutleSize];
double* boutleCapacity = new double[boutleSize]; 
std::string* boutleNameArr = new std::string[boutleSize];
//------------------------------------------------------------------------
 
//========================================================================
//вопросы
/*
как показывать склад?
что должно быть в закрытии смены?
*/
//что нужно сделать
/*
сделать колличество потребления
проверку на хватает ли в бутылке
создать бутылки и их наполненость (по умолчанию полные) PS. записал сколько и для чего надо
*/
//нужные бутылки алкоголя и их ёмкость
/*
//нужный алкоголь
Джин Barrister Dry Gin 0.5 л
Вермут Martini Bianco 1 л
Baileys Original 0.7 л(сливочный)
Коньяк A. de Fussigny Selection 0.7
Водка Gallant 0.5 л
Виски Jim Beam White 0.7 л
Ром Old Nick Carribean white 0.7 л (белый ром)
Ликер Fruko Schulz Peach Liqueur 0.7 л(персиковый)
Ликер Cointreau 0.7 л (апельсиновый)
Ликер Mozart, Dark Chocolate 0.5 л (шоколадный\какао ликёр)
Ликер Kahlua 0.7 л (кофейный)
Вермут Martini Fiero 1 л (красный)
Ликер Branca Menta 0.7 л (мятный)
*/
//составы коктейлей
/*
составы
мартини:
70мл Barrister Dry Gin
20мл Martini Bianco

александр:
20мл Mozart, Dark Chocolate
50мл A. de Fussigny Selection

олд фешн:
25мл Jim Beam White

дайкири:
Old Nick Carribean white

голубая логуна:
50мл Gallant

секс на пляже:
40мл Gallant
40мл Fruko Schulz Peach Liqueur 

b52:
20мл Cointreau
20мл Kahlua
20мл Baileys Original

космополитен:
45мл Cointreau
45мл Gallant

манхэттен:
30мл Martini Fiero
60мл Jim Beam White

кузнечик:
30 мл Mozart, Dark Chocolate
5мл A. de Fussigny Selection
30мл Branca Menta
*/
//========================================================================

bool isAdmin = false;

//функции-----------------------------------------------------------------
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
	
	std::cout << "\t\t\t\t410 автобус\n\n\n";
	if (Login () == true)
	{
		//std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		if (isAdmin == true)
		
		{
			std::string choose{};
			do
			{

				std::cout << "использовать готорый склад или создаьт новый?\n1 - готовый склад\n2 - новый склад\n\nВвод: ";
				std::getline(std::cin, choose, '\n');
			} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 49); // промежуток ASCII таблици от 0 до 8 вкл

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
		std::cout << "введите логин: ";
		std::getline(std::cin, login, '\n');
		std::cout << "введите пароль: ";
		std::getline(std::cin, pass, '\n');
		
		for (int i = 1; i < userCount; i++)
		{
			if (login == loginarr[0] && pass == passwordarr[0])
			{
				std::cout << "добро пожаловать" << loginarr[0] << '\n';
				isAdmin = true;
				return true;
			}
			else if (login == loginarr[i] && pass == passwordarr[i])
			{
				std::cout << "добро пожаловать " << loginarr[i] << '\n';
				isAdmin = false;
				return true;
			}
		}
		system("cls");
		std::cout << "неверно введён логин или пароль!\n\n";

	}

}
void ShopAdminMenu()
{
	std::cout <<"\t\t\tadmin menu\n";

	std::string choose{};
			// добавить акции
	while (true)
	{
		do
		{
			
			std::cout << "1. Начать продажу\n";//done
			std::cout << "2. показать склад\n";
			std::cout << "3. пополнить склад\n";
			std::cout << "4. списать со склада\n";
			std::cout << "5. изменить цену\n";//done
			std::cout << "6. изменить склад\n";
			std::cout << "7. изменить персонал\n";
			std::cout << "8. отчёт о прибыли\n\n";
			std::cout << "0. закрыть смену\n\n\n";

			std::cout << "ввод: \n";
			std::getline(std::cin, choose, '\n');




		} 
		while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // промежуток ASCII таблици от 0 до 8 вкл

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
	// добавить акции
	while (true)
	{
		
		do
		{
			
			std::cout << "1. Начать продажу\n";
			std::cout << "2. показать склад\n";
			std::cout << "3. пополнить склад\n";
			std::cout << "4. списать со склада\n";
			std::cout << "5. изменить цену\n";//-
			std::cout << "6. изменить склад\n";//-
			std::cout << "7. изменить персонал\n";//-
			std::cout << "8. отчёт о прибыли\n\n";
			std::cout << "0. закрыть смену\n\n\n";

			std::cout << "ввод: ";
			std::getline(std::cin, choose, '\n');




		} while (choose.size() > 1 || choose[0] < 48 || choose[0] > 56); // промежуток ASCII таблици от 0 до 8 вкл

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
		// не забыть поменять значение аски таблици
		break;
	}
}

int sell ()
{
	int choise;
	std::string choose{};
	std::cout << "\t\tначало продажи\n\n";
	std::cout << "0. мартини\t\t450\n";
	std::cout << "1. александ\t\t700\n";
	std::cout << "2. олд фешн\t\t500\n";
	std::cout << "3. дайкири\t\t300\n";
	std::cout << "4. голубая логуна\t600\n";
	std::cout << "5. секс на пляже\t400\n";
	std::cout << "6. b52\t\t\t300\n";
	std::cout << "7. космополитен\t\t550\n";
	std::cout << "8. манхэттен\t\t600\n";
	std::cout << "9. кузнечик\t\t400\n";

	std::cout << "вы хотите создать заказ?\nесли да от введите 1, иначе введите 2\n";
	std::cin >> choise;

	if (choise > 2 || choise < 1)
	{
		std::cout << "ты перепутал";
		choise = 0;
		sell();
	}
	else if (choise == 1)
	{

		while (choise != 2)
		{
			std::cout << "выберите коктейл: ";
			std::getline(std::cin, choose, '\n');
			if (choose == "0")
			{
				std::cout << "Вроде робит 0\n";
				check += martini;
				std::cout << "чек = " << check<<"\n";
				sell();

			}
			else if (choose == "1")
			{
				std::cout << "Вроде робит 1\n";
				check += aleksandr;
				std::cout << "чек = " << check << "\n";
				sell();
			}
			else if (choose == "2")
			{
				std::cout << "Вроде робит 2";
				check += old_fesion;
				std::cout << "чек = " << check << "\n";
				sell();
			}
			else if (choose == "3")
			{
				std::cout << "Вроде робит 3";
				check += daykiry;
				std::cout << "чек = " << check << "\n";
				sell();
			}
			else if (choose == "4")
			{
				std::cout << "Вроде робит 4";
				check += blue_laguna;
				std::cout << "чек = " << check << "\n";
				sell();
			}
			else if (choose == "5")
			{
				std::cout << "Вроде робит 5";
				check += sex_on_beach;
				std::cout << "чек = " << check << "\n";
				sell();
			}
			else if (choose == "6")
			{
				std::cout << "Вроде робит 6";
				check += b52;
				std::cout << "чек = " << check << "\n";
				sell();
			}
			else if (choose == "7")
			{
				std::cout << "Вроде робит 7";
				check += cosmopolyten;
				std::cout << "чек = " << check << "\n";
				sell();
			}
			else if (choose == "8")
			{
				std::cout << "Вроде робит 8";
				check += manhetten;
				std::cout << "чек = " << check << "\n";
				sell();
			}
			else if (choose == "9")
			{
				std::cout << "Вроде робит 9";
				check += kuznechik;
				std::cout << "чек = " << check << "\n";
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
			
				std::cout << "вы хотите поменять цену?\nесли да то введите 1, иначе 2\n";
				std::cin >> choise;
				if (choise == 2)
				{
					ShopAdminMenu();
				}
				else if (choise == 1)
				{
					std::cout << "\t\tсмена цены\n\n";
					std::cout << "0. мартини\t\t450\n";
					std::cout << "1. александ\t\t700\n";
					std::cout << "2. олд фешн\t\t500\n";
					std::cout << "3. дайкири\t\t300\n";
					std::cout << "4. голубая логуна\t600\n";
					std::cout << "5. секс на пляже\t400\n";
					std::cout << "6. b52\t\t\t300\n";
					std::cout << "7. космополитен\t\t550\n";
					std::cout << "8. манхэттен\t\t600\n";
					std::cout << "9. кузнечик\t\t400\n";
					std::cout << "какую цену напитка вы хотите изменить?\n";
					std::cin>> choise2;
					if (choise2 < 0 || choise2 > 9)
					{
						std::cout << "ты по моему перепутал";

					}
					else
					{
						if (choise2 == 0)
						{
							std::cout << "сейчас цена мартини равна " << martini << " введите сумму на которую хотите поменять цену \n";
							std::cin >> martini;

							std::cout << "теперь цена мартини равна " << martini << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 1)
						{
							std::cout << "сейчас цена александра равна " << aleksandr << " введите сумму на которую хотите поменять цену \n";
							std::cin >> aleksandr;

							std::cout << "теперь цена александра равнв " << aleksandr << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 2)
						{
							std::cout << "сейчас цена олд фешена равна " << old_fesion << " ведите сумму на которую хотите поменять цену \n";
							std::cin >> old_fesion;

							std::cout << "теперь цена олд фешена равна " << old_fesion << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 3)
						{
							std::cout << "сейчас цена дайкири равна " << daykiry << " введите сумму на которую хотите поменять цену \n";
							std::cin >> daykiry;

							std::cout << "теперь цена дайкири равна " << daykiry << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 4)
						{
							std::cout << "сейчас цена голубой лагуны равна"<< blue_laguna << " введите сумму на которую хотите поменять цену \n";
							std::cin >> blue_laguna;

							std::cout << "теперь цена голубой лагуны равна" << blue_laguna << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 5)
						{
							std::cout<< "сейчас цена секса на пляже равна "<< sex_on_beach << " введите сумму на которую хотите поменять цену \n";
							std::cin >> sex_on_beach;

							std::cout << "теперь цена секса на пляже равна " << sex_on_beach << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 6)
						{
							std::cout << "сейчас цена b 52 равна " << b52 << " введите сумму на которую хотите поменять цену \n";
							std::cin >> b52;

							std::cout << "теперь цена b52 равна " << b52 << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 7)
						{
							std::cout << "сейчас цена космополитена равна " << cosmopolyten << " введите сумму на которую хотите поменять цену \n";
							std::cin >> cosmopolyten;

							std::cout << "теперь цена космополитена равна " << cosmopolyten << "\n";
							ShopAdminMenu(); 
						}
						else if (choise2 == 8)
						{
							std::cout << "сейчас цена манхэттена равна " << manhetten << " введите сумму на которую хотите поменять цену \n";
							std::cin >> manhetten;

							std::cout << "теперь цена манхэттена равна " << manhetten << "\n";
							ShopAdminMenu();
						}
						else if (choise2 == 9)
						{
							std::cout << "сейчас цена кузнечика равна " << kuznechik << " введите сумму на которую хотите поменять цену \n";
							std::cin >> kuznechik;

							std:: cout << "теперь цена кузнечика равна " << kuznechik << "\n";
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
		"мартини\t","александр",
		"олд фешн","дайкири\t",
		"голубая логуна","секс на пляже",
		"b52\t","космополитен",
		"манхэттен","кузнечик"
	};
	std::string nameStaticArrBoutle[staticSizeBoutle]
	{
		"Джин Barrister Dry Gin", "Вермут Martini Bianco", "Ликёр Baileys Original", "Коньяк A. de Fussigny Selection", "Водка Gallant",
		"Виски Jim Beam White", "Ром Old Nick Carribean white", "Ликер Fruko Schulz Peach Liqueur", "Ликер Cointreau",
		"Ликер Mozart, Dark Chocolate", "Ликер Kahlua", "Вермут Martini Fiero", "Ликер Branca Menta"
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
	std::cout << "ID\tназвание\t\t\tцена\tбутылуки\n\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << idArr[i] << "\t" << nameArr[i] << "\t\t"
			<< priceArr[i] << "\t\t" << boutleNameArr[i] << "\t\n";
	}

}