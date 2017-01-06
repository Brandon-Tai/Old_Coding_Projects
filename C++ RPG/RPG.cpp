// Declarations
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <windows.h>
using namespace std;
// Functions
#pragma region Functions
void SetName();
void CreatePlayer();
void DisplayStats();
void MainMenu();
void Enemy(string name, int hp, int attack, int armor, int goldReward, int expReward);
void Inventory();
void Shop();
void Check();
void Arena();
void Campaign();
void CheckLevel();
void Save();
void Load();
void Equipped();
#pragma endregion
// Player Strings
string name, type, playerClass, nameCorrect;
// Player Integers
int exp, level, armor, hp, mana, maxHP, maxMana, attack, attackSpeed, gold, expCap;
// Still Playing The Game (Not done)(For While Loop)
bool done = false;
// Player Integers
int str, agi, intl;
// Player Attack Integers
int meleeAttack, magicAttack;
// 0 Time Defined for Random
time_t ttime = time(NULL);
// 0 Time Integer
int itime = ttime;
// Potions
int hppots, manapots = 0;
// Integer for how much potions restore
int difference;
bool ironSword = false;
bool bronzeSword = false;
bool woodenStaff = false;
bool medusaHead = false;
bool leatherVest = false;

string str_ironSword;

// Function for Intro to Switch Statements
void Check()
{
	// Integer Choice
	int choice;
	cout << "Enter a choice: ";
	cin >> choice;
	// Switch Statement
	switch(choice)
	{
	// If choice is 1
	case 1:
		cout << "You have entered one." << endl;
		break;
	// If choice is 2
	case 2:
		cout << "You have entered two." << endl;
		break;
	// If choice is 3
	case 3:
		cout << "You have entered three." << endl;
		break;
	// If choice is 4
	case 4:
		cout << "You have entered four." << endl;
		break;
	// If choice is anything else
	default:
		cout << "Command Invalid." << endl;
		// Goes to Function Check
		Check();
	}
}
// Main Function
void main()
{
	// time 0 affects Random
	srand(itime);
	// Go to Function Set Character Name
	SetName();
	// Keep running main menu while done is false
	while(!done)
	{
		// go to Main Menu Function
		MainMenu();
	}
}
// Function for Player Name Creation
void SetName()
{
	system("cls");
	cout << " Enter your name: ";
	cin >> name;
	system("cls");
	cout << " is " << name << " correct?" << endl;
	cout << " Yes/no: ";
	cin >> nameCorrect;
	system("cls");
	if(nameCorrect == "yes" || nameCorrect == "Yes")
	{
	}
	else if(nameCorrect == "no" || nameCorrect == "No")
	{
		SetName();
	}
	else
	{
		cout << " Command Invalid." << endl;
		SetName();
	}
	CreatePlayer();
}
// Function for Player Character Creation
void CreatePlayer()
{
	// Clear Screen
	system("cls");
	// Start at level 1
	level = 1;
	// String Choice
	string choice;
	cout << " Enter your class:" << endl;
	cout << " (1) Warrior" << endl;
	cout << " (2) Ranger" << endl;
	cout << " (3) Mage" << endl;
	cin >> choice;
	// Clear Screen
	system("cls");
	// if they choose (1) Warrior...
	if(choice == "1")
	{
		// Class
		playerClass = "Warrior";
		// Attack
		attack = 30;
		// Attack Speed
		attackSpeed = 3;
		// Armor
		armor = 10;
		// Strength
		str = 40;
		// Agility
		agi = 7;
		// Intelligence
		intl = 3;
		// Max Health
		maxHP = 50;
		// Health
		hp = 50;
		// Mana
		mana = 10;
		// Max Mana
		maxMana = 10;
	}
	// if they choose (2) Ranger...
	else if(choice == "2")
	{
		// Class
		playerClass = "Ranger";
		// Attack
		attack = 24;
		// Attack Speed
		attackSpeed = 10;
		// Armor
		armor = 6;
		// Strength
		str = 5;
		// Agility
		agi = 30;
		// Intelligence
		intl = 15;
		// Max Health
		maxHP = 200;
		// Health
		hp = 200;
		// Mana
		mana = 20;
		// Max Mana
		maxMana = 20;
	}
	// if they choose (3) Mage...
	else if(choice == "3")
	{
		// Class
		playerClass = "Mage";
		// Attack
		attack = 1;
		// Attack Speed
		attackSpeed = 3;
		// Armor
		armor = 3;
		// Strength
		str = 1;
		// Agility
		agi = 1;
		// Intelligence
		intl = 44;
		// Max Health
		maxHP = 150;
		// Max Mana
		maxMana = 30;
		// Health
		hp = 150;
		// Mana
		mana = 30;
	}
	// If they choose something else...
	else
	{
		cout << " Class Invalid" << endl;
		// Go To Function CreatePlayer
		CreatePlayer();
	}
	// have 50 gold
	gold = 50;
	// have 0 experience
	exp = 0;
	// have 100 max experience
	expCap = 100;
	// Sure?
	cout << " is " << playerClass << " correct?" << endl;
	cout << " Yes/no: ";
	cin >> nameCorrect;
	// if nameCorrect is yes...
	if(nameCorrect == "yes" || nameCorrect == "Yes")
	{
		// Go to Main Menu Function
		MainMenu();
	}
	// if nameCorrect is no...
	else if(nameCorrect == "no" || nameCorrect == "No")
	{
		// Go To CreatePlayer Function
		CreatePlayer();
	}
	// if nameCorrect is anything else...
	else
	{
		cout << " Command Invalid." << endl;
		// Go To CreatePlayer Function
		CreatePlayer();
	}

}
// Show Player Stats
void DisplayStats()
{
	// Clear Screen
	system("cls");
	cout << "\n Name = " << name << endl;
	cout << " Class = " << playerClass << endl;
	cout << " Level = " << level << endl;
	cout << " Experience = " << exp << " / " << expCap << endl;
	cout << " Attack = " << attack << endl;
	cout << " Armor = " << armor << endl;
	cout << " Health = " << hp << " / " << maxHP << endl;
	cout << " Mana = " << mana << " / " << maxMana << endl;
	cout << " Strength = " << str << endl;
	cout << " Agility = " << agi << endl;
	cout << " Intelligence = " << intl << endl;
	cout << " You have " << gold << " gold." << endl;
	cout << endl;
	cout << endl;
	// Pause Game
	system("PAUSE");
}

// Function for Main Menu
void MainMenu()
{
	// Clear Screen
	system("cls");
	// String Choice
	string choice;
	cout << "\n\n   ------------------" << endl;
	cout << "    M A I N  M E N U" << endl;
	cout << "   ------------------" << endl;
	cout << "\n    (1) Play Game" << endl;
	cout << "\n    (2) Shop" << endl;
	cout << "\n    (3) Stats" << endl;
	cout << "\n    (4) Inventory" << endl;
	cout << "\n    (5) Save Game" << endl;
	cout << "\n    (6) Load Game" << endl;
	cout << "\n    (7) Leave Game" << endl;
	cin >> choice;
	// if choice is 1...
	if(choice == "1")
	{
		system("cls");
		int choice;
		cout << "(1) Campaign (Not yet made)" << endl;
		cout << "(2) Arena (Levels 1 - 100)" << endl;
		cout << "(3) MainMenu" << endl;
		cin >> choice;
		system("cls");
		switch(choice)
		{
		case 1:
			/*Campaign();*/
			break;
		case 2:
			Arena();
			break;
		case 3:
			MainMenu();
			break;
		default:
			cout << "Command Invalid." << endl;
			break;
		}
	}
	// if choice is 2...
	else if(choice == "2")
	{
		Shop();
	}
	// if choice is 3...
	else if(choice == "3")
	{
		DisplayStats();
	}
	// if choice is 4...
	else if(choice == "4")
	{
		Inventory();
	}
	// if choice is 5...
	else if(choice == "5")
	{
		Save();
	}
	// if choice is 6...
	else if(choice == "6")
	{
		Load();
	}
	// if choice is 7...
	else if(choice == "7")
	{
		done = true;
	}
	// if choice is anything else...
	else
	{
		cout << "Command Invalid." << endl;
		system("PAUSE");
		MainMenu();
	}
}
// Funtion for Fighting Enemies
void Enemy(string name, int hp, int attack, int armor, int goldReward, int expReward)
{
	// Clear Screen
	system("cls");
	// Integer Attack
	int attack1 = rand() % attack + attack - (::armor / 4);
	cout << " You were attacked by a " << name << "." << endl;
	// Enemy is alive
	bool alive = true;
	// Whil enemy is alive...
	while(alive)
	{
		// not defending
		bool defend = false;
		// not running away
		bool runaway = false;
		meleeAttack = rand() % str + agi + ::attack;
		magicAttack = rand() % 1 + (intl*3) - (armor / 4);
		cout << "\n Health = " << ::hp << " / " << maxHP << endl;
		cout << " Mana = " << mana << " / " << maxMana << endl;
		cout << "\n Enemy " << name << " Health = " << hp << endl;
		string choice;
		cout << "\n (1) Melee attack" << endl;
		cout << " (2) Magic attack" << endl;
		cout << " (3) Defend" << endl;
		cout << " (4) Inventory" << endl;
		cout << " (5) Run Away (-10 gold)" << endl;
		cin >> choice;
		system("cls");
		if(choice == "1")
		{
			int meleeOption;
			int doubleHit = meleeAttack * 2;
			int shockwave = meleeAttack * 4;
			cout << "(1) Bash (-0 mana)" << endl;
			cout << "(2) Double Hit (-2 mana)" << endl;
			cout << "(3) Shockwave (-10 mana)" << endl;
			cin >> meleeOption;

			system("cls");
			switch(meleeOption)
			{
			case 1:
				cout << " You bash the " << name << " for " << meleeAttack << " damage." << endl;
				hp -= meleeAttack;
				break;
			case 2:
				if(mana >= 2)
				{
					cout << " You Double Hit the " << name << " for " << meleeAttack << " damage." << endl;
					hp -= doubleHit;
					mana -= 2;
					break;
				}
				else
				{
					cout << "Not enough mana." << endl;
				}
			case 3:
				if(mana >= 10)
				{
					cout << " You send a Shockwave at the " << name << " for " << meleeAttack << " damage." << endl;
					hp -= shockwave;
					mana -= 2;
					break;
				}
				else
				{
					cout << "Not enough mana." << endl;
				}
			}
		}
		else if(choice == "2")
		{
			int magicOption;
			int iceSpike = magicAttack * 2;
			int energyBlast = magicAttack * 8;
			cout << "(1) Fireball (-5 mana)" << endl;
			cout << "(2) Ice Spike (-10 mana)" << endl;
			cout << "(3) Energy Blast (-50 mana)" << endl;
			cin >> magicOption;
			system("cls");
			switch(magicOption)
			{
			case 1:
				if(mana >= 5)
				{
					cout << " You shoot a Firball at the " << name << " for " << magicAttack << " damage." << endl;
					hp -= magicAttack;
					mana -= 5;
					break;
				}
				else
				{
					cout << "Not enough mana." << endl;
				}
			case 2:
				if(mana >= 10)
				{
					cout << " You hit the " << name << " with an Ice Spike for " << magicAttack << " damage." << endl;
					hp -= iceSpike;
					mana -= 10;
					break;
				}
				else
				{
					cout << "Not enough mana." << endl;
				}
			case 3:
				if(mana >= 50)
				{
					cout << " You blast the " << name << " with a wall of energy for " << magicAttack << " damage." << endl;
					hp -= energyBlast;
					mana -= 50;
					break;
				}
				else
				{
					cout << "Not enough mana." << endl;
				}
			}
		}
		else if(choice == "3")
		{
			int tempAttack = attack / 2;
			int randomAttack = rand() % 3;
			defend = true;
			if(randomAttack == 0)
			{
				cout << " The " << name << " missed the attack." << endl;
			}
			else if(randomAttack == 1)
			{
				cout << " The " << name << " attacks you for " << tempAttack << " damage." << endl;
				::hp -= tempAttack;
			}
			else if(randomAttack == 2)
			{
				cout << " You block the " << name << "'s attack back for " << attack1 << " damage." << endl;
				hp -= attack;
			}
		}
		else if(choice == "4")
		{
			Inventory();
		}
		else if(choice == "5")
		{
			cout << " You Run away from the " << name << " and lose 10 gold." << endl;
			runaway = true;
			if(gold <= 0)
			{
				gold = 0;
			}
			system("PAUSE");
			MainMenu();
		}
		else
		{
			cout << " Command Invalid." << endl;
		}
		if(hp <= 0)
		{
			alive = false;
		}
		if(runaway)
		{
			
			gold -= 10;
			if(gold <= 0)
			{
				gold = 0;
			}
			break;
		}
		if(!defend && alive)
		{
			cout << " The enemy " << name << " attacked you for " << attack1 << " damage." << endl;
			::hp -= attack1;
		}
		if(!alive)
		{
			cout << " You defeated the " << name << " in battle, and proven yourself against him." << endl;
			cout << " You have been rewarded " << goldReward << " gold." << endl;
			cout << " You have gained " << expReward << " experience." << endl;
			gold += goldReward;
			exp += expReward;
			CheckLevel();
			system("PAUSE");
		}
	}
}
// Function for Inventory with using items
void Inventory()
{
	system("cls");
	string choice;
	cout << " Health = " << hp << " / " << maxHP << endl;
	cout << " Mana = " << mana << " / " << maxMana << endl;
	cout << " Gold = " << gold << endl;
	cout << " Number of Health Potions = " << hppots << endl;
	cout << " Number of Mana Potions = " << manapots << endl;
	cout << "\n (1) Use Health Potion" << endl;
	cout << " (2) Use Mana Potion" << endl;
	cout << " (3) Equipped" << endl;
	cout << " (4) Close" << endl;
	cin >> choice;
	system("cls");
	if(choice == "1")
	{
		if(hppots > 0)
		{
			hp += 50;
			if(hp >= maxHP)
			{
				hp = maxHP;
			}
			else
			{
			}
			cout << " You have used a health potion. You now have " << hp << " / " << maxHP << " health." << endl;
			if(hp > maxHP)
			{
				hp = maxHP;
			}
		}
		else
		{
			cout << "You don't have any health potions!" << endl;
			system("PAUSE");
			Inventory();
		}
	}
	else if(choice == "2")
	{
		if(manapots > 0)
		{
			mana += 50;
			if(mana >= maxMana)
			{
				mana = maxMana;
			}
			else
			{
			}
			cout << " You have used a mana potion. You now have " << hp << " / " << maxHP << " mana." << endl;
		}
		else
		{
			cout << "You don't have any mana potions!" << endl;
			system("PAUSE");
			Inventory();
		}
	}
	else if(choice == "3")
	{
		Equipped();
		
	}
	else if(choice == "4")
	{
	}
	else
	{
		cout << "Command Invalid." << endl;
	}
}
// Function for Shop with buying and using items
void Shop()
{
	system("cls");
	string choice;
	cout << "\n\n   ---------------" << endl;
	cout << "   --- S H O P ---" << endl;
	cout << "   ---------------" << endl;
	cout << "\n\n  Potions:" << endl;
	cout << "\n  (1) Buy Health Potion (-10 gold, +50 health)" << endl;
	cout << "  (2) Buy Mana Potion (-10 gold, +50 mana)" << endl;
	cout << "\n\n  Main Weapons:" << endl;
	cout << "  (3) Buy Iron Sword (-50 gold, +10 strength)" << endl;
	cout << "  (4) Buy Bronze Sword (-25 gold, +5 strength)" << endl;
	cout << "  (5) Buy Wooden Staff (-50 gold, +5 Intelligence, +2 Attack)" << endl;
	cout << "\n\n  Secondary Weapons:" << endl;
	cout << "\n  (6) Buy Medusa's Head (-10000 gold, +100 Stregnth, Intelligence, and Agility)" << endl;
	cout << "\n\n  Armor:"  << endl;
	cout << "\n  Chest:" << endl;
	cout << "\n  (7) Leather Vest (-20 gold, +16 armor)" << endl;
	cout << "\n\n  (8) Leave Shop" << endl;
	cin >> choice;
	if(choice == "1")
	{
		if(gold >= 10)
		{
			string option;
			cout << " Would you like to use this potion now?" << endl;
			cout << " Yes/no: " << endl;
			cin >> option;
			system("cls");
			if(option == "Yes" || option == "yes")
			{
				hp += 50;
				if(hp >= maxHP)
				{
					hp = maxHP;
				}
				else
				{
				}
				cout << " You have used a health potion. You now have " << hp << " / " << maxHP << " health." << endl;
				system("PAUSE");
				
				if(hp > maxHP)
				{
					hp = maxHP;
				}
				Shop();
			}
			else if(option == "No" || option == "no")
			{
				gold -= 10;
				hppots++;
				cout << " You have purchased one health potion." << endl;
				system("PAUSE");
				Shop();
			}
		}
	}
	else if(choice == "2")
	{
		if(gold>=10)
		{
			string option;
			cout << " Would you like to use this potion now?" << endl;
			cout << " Yes/no: " << endl;
			cin >> option;
			system("cls");
			if(option == "Yes" || option == "yes")
			{
				mana += 50;
				if(mana >= maxMana)
				{
					mana = maxMana;
				}
				else
				{
				}
				cout << " You have used a mana potion. You now have " << hp << " / " << maxHP << " mana." << endl;
				system("PAUSE");
			}
			if(option == "No" || option == "no")
			{
				gold -= 10;
				manapots++;
				cout << " You have purchased one mana potion." << endl;
				system("PAUSE");
			}
		}
		
	}
	else if(choice == "3")
	{
		if(!ironSword && !woodenStaff && !bronzeSword )
		{
			if(gold >= 50)
			{
				cout << "You have purchased an Iron Sword." << endl;
				gold -= 50;
				str += 10;
				ironSword = true;
				str_ironSword = "Iron";
			}
			else
				cout << " Not enough money." << endl;
		}
		else if(woodenStaff)
		{
			string sell;
			cout << "You have an Wooden Staff." << endl;
			cout << "Would you like to replace it?  Yes/No: ";
			cin >> sell;
			system("cls");
			if(sell == "Yes" || sell == "yes")
			{
				cout << "You have purchased an Iron Sword." << endl;
				gold -= 25;
				str += 10;
				attack -= 2;
				intl -= 5;
			}
			else
			{
				cout << "Transaction Cancelled." << endl;
			}
		}
		else if(bronzeSword)
		{
			string sell;
			cout << "You have an Bronze Sword." << endl;
			cout << "Would you like to replace it?  Yes/No: ";
			cin >> sell;
			system("cls");
			if(sell == "Yes" || sell == "yes")
			{
				cout << "You have purchased an Iron Sword." << endl;
				gold -= 40;
				str += 5;
			}
			else
			{
				cout << "Transaction Cancelled." << endl;
			}
		}
		else 
			cout << " You already have that item." << endl;
	}
	else if(choice == "4")
	{
		if(!bronzeSword && !ironSword && !woodenStaff)
		{
			if(gold >= 25)
			{
				cout << "You have purchased a Bronze Sword." << endl;
				gold -= 25;
				str += 5;
				bronzeSword = true;
			}
			else
				cout << " Not enough money." << endl;
		}
		else if(ironSword)
		{
			string sell;
			cout << "You have an Iron Sword." << endl;
			cout << "Would you like to replace it?  Yes/No: ";
			cin >> sell;
			system("cls");
			if(sell == "Yes" || sell == "yes")
			{
				cout << "You have purchased a Bronze Sword." << endl;
				str -= 5;
			}
			else
			{
				cout << "Transaction Canceled." << endl;
				Shop();
			}
		}
		else if(woodenStaff)
		{
			string sell;
			cout << "You have an Wooden Staff." << endl;
			cout << "Would you like to replace it?  Yes/No: ";
			cin >> sell;
			system("cls");
			if(sell == "Yes" || sell == "yes")
			{
				cout << "You have purchased a Bronze Sword." << endl;
				str += 5;
				attack -= 2;
				intl -= 5;
			}
			else
			{
				cout << "Transaction Cancelled." << endl;
			}
		}
		else
		{
			cout << " You already have that item." << endl;
			system("PAUSE");
		}
	}
	else if(choice == "5")
	{
		if(!woodenStaff && !bronzeSword && !ironSword)
		{
			if(gold >= 50)
			{
				cout << "You have purchased a Wooden Staff." << endl;
				gold -= 50;
				attack += 2;
				intl += 5;
				woodenStaff = true;
			}
			else
				cout << " Not enough money." << endl;
		}
		else if(ironSword)
		{
			string sell;
			cout << "You have an Iron Sword." << endl;
			cout << "Would you like to replace it?  Yes/No: ";
			cin >> sell;
			system("cls");
			if(sell == "Yes" || sell == "yes")
			{
				cout << "You have purchased a Wooden Staff." << endl;
				gold -= 25;
				str -= 10;
				attack += 2;
				intl += 5;
			}
		}
		else
		{
			cout << "Transaction Canceled." << endl;
			Shop();
		}
	}
		else if(bronzeSword)
		{
			string sell;
			cout << "You have an Bronze Sword." << endl;
			cout << "Would you like to replace it?  Yes/No: ";
			cin >> sell;
			system("cls");
			if(sell == "Yes" || sell == "yes")
			{
				cout << "You have purchased a Wooden Staff." << endl;
				gold -= 40;
				str -= 5;
				attack += 2;
				intl += 5;
			}
			else
			{
				cout << "Transaction Canceled." << endl;
				Shop();
			}
		}
	else if(choice == "6")
	{
		if(!medusaHead)
		{
			if(gold >= 10000)
			{
				cout << "You have purchased a Head of Medusa." << endl;
				gold -= 10000;
				str += 100;
				intl += 100;
				agi += 100;
				medusaHead = true;
			}
			else
				cout << " Not enough money." << endl;
		}
		else
		{
			cout << "You already have one." << endl;
			Shop();
		}
	}
	else if(choice == "7")
	{
		if(!leatherVest)
		{
			if(gold >= 20)
			{
				cout << "You have purchased a Leather Vest." << endl;
				gold -= 20;
				armor += 16;
				leatherVest = true;
			}
			else
				cout << " Not enough money." << endl;
		}
		else
		{
			cout << "You already have one." << endl;
			Shop();
		}
	}
	else if(choice == "8")
	{
		MainMenu();
	}
	else
	{
		cout << "Command Invalid." << endl;
		system("PAUSE");
		Shop();
	}
}
// Function for Enemies fought in the Arena
void Arena()
{
	if(level <= 6)
	{
		int easyMonsters = rand() % 10;
		int easyHP = rand() % 150 + 150;
		int easyAttack = rand() % 5 + 10;
		int easyGold = rand() % 10 + 5;
		int easyExp = rand() % 20 + 100;
		switch(easyMonsters)
		{
		case 0:
			Enemy("Angry Giant Goat", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		case 1:
			Enemy("Iritated Poisonous Snake", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		case 2:
			Enemy("Rampaging Baby Pterodactyl", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		case 3:
			Enemy("Poisonous Treefrog", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		case 4:
			Enemy("Mutated Overgrown Bullfrog", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		case 5:
			Enemy("Giant Angry Hyena", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		case 6:
			Enemy("Angry Mutated Duck", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		case 7:
			Enemy("Rampaging Baby Raptor", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		case 8:
			Enemy("Baby Unicorn", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		case 9:
			Enemy("Sleeping Baby Dragon", easyHP, easyAttack, 5, easyGold, easyExp);
			break;
		}
	}
	else if(level >= 5 && level <= 11)
	{
		int fiveMonsters = rand() % 10;
		int fiveHP = rand() % 300 + 750;
		int fiveAttack = rand() % 15 + 45;
		int fiveGold = rand() % 30 + 20;
		int fiveExp = rand() % 50 + 500;
		switch(fiveMonsters)
		{
		case 0:
			Enemy("Malfunctioning Demolisher Robot", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		case 1:
			Enemy("Iritated Poisonous Viper", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		case 2:
			Enemy("Rampaging Pterodactyl", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		case 3:
			Enemy("Poisonous Mutated Toad", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		case 4:
			Enemy("Mutated Kimoto Dragon", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		case 5:
			Enemy("Giant Angry Hippo", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		case 6:
			Enemy("Angry Mutated Baby Sea Monster", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		case 7:
			Enemy("Frenzied Blind Raptor", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		case 8:
			Enemy("Unicorn", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		case 9:
			Enemy("Baby Dragon", fiveHP, fiveAttack, 5, fiveGold, fiveExp);
			break;
		}
	}
	else if(level >= 10 && level <= 21)
	{
		int tenMonsters = rand() % 10;
		int tenHP = rand() % 800 + 1750;
		int tenAttack = rand() % 50 + 100;
		int tenGold = rand() % 50 + 75;
		int tenExp = rand() % 750 + 1600;
		switch(tenMonsters)
		{
		case 0:
			Enemy("Missile Robot", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		case 1:
			Enemy("Angry Mutated Cobra", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		case 2:
			Enemy("Sleeping Baby Plesiosaur", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		case 3:
			Enemy("Angry Lioness", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		case 4:
			Enemy("Angry Lion", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		case 5:
			Enemy("Giant Rampaging Tusked Elephant", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		case 6:
			Enemy("Minor Sea Monster", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		case 7:
			Enemy("Frenzied Raptor", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		case 8:
			Enemy("Wolf", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		case 9:
			Enemy("Young Drake", tenHP, tenAttack, 5, tenGold, tenExp);
			break;
		}
	}
	else if(level >= 20 && level <= 41)
	{
		int twMonsters = rand() % 10;
		int twHP = rand() % 2500 + 5000;
		int twAttack = rand() % 200 + 750;
		int twGold = rand() % 200 + 750;
		int twExp = rand() % 2000 + 3000;
		switch(twMonsters)
		{
		case 0:
			Enemy("Angry Spirit", twHP, twAttack, 5, twGold, twExp);
			break;
		case 1:
			Enemy("Fire-Breathing Cobra", twHP, twAttack, 5, twGold, twExp);
			break;
		case 2:
			Enemy("Baby Plesiosaur", twHP, twAttack, 5, twGold, twExp);
			break;
		case 3:
			Enemy("Giant Angry Lioness", twHP, twAttack, 5, twGold, twExp);
			break;
		case 4:
			Enemy("Giant Angry Lion", twHP, twAttack, 5, twGold, twExp);
			break;
		case 5:
			Enemy("Giant Rampaging Tusken Warrior", twHP, twAttack, 5, twGold, twExp);
			break;
		case 6:
			Enemy("Angry Minor Sea Monster", twHP, twAttack, 5, twGold, twExp);
			break;
		case 7:
			Enemy("T-Rex", twHP, twAttack, 5, twGold, twExp);
			break;
		case 8:
			Enemy("Dire Wolf", twHP, twAttack, 5, twGold, twExp);
			break;
		case 9:
			Enemy("Dragon", twHP, twAttack, 5, twGold, twExp);
			break;
		}
	}
	else if(level >= 40 && level <= 100)
	{
		int ftMonsters = rand() % 10;
		int ftHP = rand() % 7500 + 15000;
		int ftAttack = rand() % 1000 + 2500;
		int ftGold = rand() % 1250 + 2500;
		int ftExp = rand() % 5000 + 10000;
		switch(ftMonsters)
		{
		case 0:
			Enemy("Angry Minor God", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		case 1:
			Enemy("Fire-Breathing Sea Dragon", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		case 2:
			Enemy("Plesiosaur", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		case 3:
			Enemy("Giant Angry Chimera", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		case 4:
			Enemy("Giant Angry Nemean Lion", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		case 5:
			Enemy("Giant Tusked Ogre Warrior", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		case 6:
			Enemy("Angry Sea Monster", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		case 7:
			Enemy("Pack of Angry Raptors", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		case 8:
			Enemy("Pack of Dire Wolves", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		case 9:
			Enemy("Giant Red Dragon", ftHP, ftAttack, 5, ftGold, ftExp);
			break;
		}
	}
}
// Function for leveling up
void CheckLevel()
{
	if(exp >= expCap)
	{
		level++;
		cout << "Congratulations!! You have leveled up to level " << level << "!" << endl;
		exp -= expCap;
		expCap *= 3;
		if(playerClass == "Warrior")
		{
			int strRand = rand() % 2 + 5;
			int agiRand = rand() % 1 + 3;
			int intlRand = rand() % 1 + 2;
			int hpRand = rand() % 50 + 100;
			int manaRand = rand() % 10 + 15;
			int attRand = rand() % 10 + 20;
			int aspdRand = rand() % 1 + 5;
			str += strRand;
			agi += agiRand;
			intl += intlRand;
			armor += intlRand;
			maxHP += hpRand;
			maxMana += manaRand;
			attack += attRand;
			attackSpeed += aspdRand;
		}
		else if(playerClass == "Ranger")
		{
			int strRand = rand() % 1 + 2;
			int agiRand = rand() % 2 + 5;
			int intlRand = rand() % 1 + 3;
			int hpRand = rand() % 50 + 100;
			int manaRand = rand() % 10 + 15;
			int attRand = rand() % 10 + 20;
			int aspdRand = rand() % 1 + 5;
			str += strRand;
			agi += agiRand;
			intl += intlRand;
			armor += intlRand;
			maxHP += hpRand;
			maxMana += manaRand;
			attack += attRand;
			attackSpeed += aspdRand;
		}
		else if(playerClass == "Mage")
		{
			int strRand = rand() % 1 + 1;
			int agiRand = rand() % 1 + 1;
			int intlRand = rand() % 2 + 5;
			int hpRand = rand() % 50 + 100;
			int manaRand = rand() % 10 + 15;
			int attRand = rand() % 1 + 2;
			int aspdRand = rand() % 1 + 5;
			str += strRand;
			agi += agiRand;
			intl += intlRand;
			armor += intlRand;
			maxHP += hpRand;
			maxMana += manaRand;
			attack += attRand;
			attackSpeed += aspdRand;
		}
		hp = maxHP;
		mana = maxMana;
	}
}
// Function for Saving your game
void Save()
{
	ofstream save("Character/Player.txt");
	ofstream save1("Character/Player1.txt");
	ofstream save2("Character/Player1.txt");
	ofstream save3("Character/Player1.txt");
	int choice;
	cout << " Which save file?" << endl;
	cout << " (1)  (2)  (3)  (4)  (5): ";
	cin >> choice;
	system("cls");
	switch(choice)
	{
	case 1:
		if(save.is_open())
		{
			save << endl;
			save << name << endl;
			save << playerClass << endl;
			save << armor << endl;
			save << str << endl;
			save << agi << endl;
			save << intl << endl;
			save << hp << endl;
			save << mana << endl;
			save << maxHP << endl;
			save << maxMana << endl;
			save << expCap << endl;
			save << exp << endl;
			save << level << endl;
			save << gold << endl;
			if(ironSword)
			{
				save << str_ironSword << endl;
			}
			save.close();
		}
		else
		{
			cout << "Error opening file Player.txt." << endl;
		}
		case 2:
		if(save.is_open())
		{
			save1 << endl;
			save1 << name << endl;
			save1 << playerClass << endl;
			save1 << armor << endl;
			save1<< str << endl;
			save1<< agi << endl;
			save1<< intl << endl;
			save1<< hp << endl;
			save1<< mana << endl;
			save1<< maxHP << endl;
			save1<< maxMana << endl;
			save1<< expCap << endl;
			save1 << exp << endl;
			save1 << level << endl;
			save1 << gold << endl;

			save1.close();
		}
		else
		{
			cout << "Error opening file Player1.txt." << endl;
		}
		case 3:
		if(save.is_open())
		{
			save2 << endl;
			save2 << name << endl;
			save2 << playerClass << endl;
			save2 << armor << endl;
			save2 << str << endl;
			save2 << agi << endl;
			save2 << intl << endl;
			save2 << hp << endl;
			save2 << mana << endl;
			save2 << maxHP << endl;
			save2 << maxMana << endl;
			save2 << expCap << endl;
			save2 << exp << endl;
			save2 << level << endl;
			save2 << gold << endl;
			save2.close();
		}
		else
		{
			cout << "Error opening file Player2.txt." << endl;
		}
		case 4:
		if(save.is_open())
		{
			save3 << endl;
			save3 << name << endl;
			save3 << playerClass << endl;
			save3 << armor << endl;
			save3 << str << endl;
			save3 << agi << endl;
			save3 << intl << endl;
			save3 << hp << endl;
			save3 << mana << endl;
			save3 << maxHP << endl;
			save3 << maxMana << endl;
			save3 << expCap << endl;
			save3 << exp << endl;
			save3 << level << endl;
			save3 << gold << endl;
			save3.close();
		}
		else
		{
			cout << "Error opening file Player3.txt." << endl;
		}
		case 5:
		if(save.is_open())
		{
			save2 << endl;
			save2 << name << endl;
			save2 << playerClass << endl;
			save2 << armor << endl;
			save2 << str << endl;
			save2 << agi << endl;
			save2 << intl << endl;
			save2 << hp << endl;
			save2 << mana << endl;
			save2 << maxHP << endl;
			save2 << maxMana << endl;
			save2 << expCap << endl;
			save2 << exp << endl;
			save2 << level << endl;
			save2 << gold << endl;
			save2.close();
		}
		else
		{
			cout << "Error opening file Player4.txt." << endl;
		}
	}
}
// Function for Loading your saved game
void Load()
{
	ifstream file("Character/Player.txt");
	ifstream file1("Character/Player1.txt");
	ifstream file2("Character/Player1.txt");
	ifstream file3("Character/Player1.txt");
	ifstream file4("Character/Player1.txt");
	string line;
	int choice;
	cout << " Pick a file slot to load." << endl;
	cout << " (1)  (2)  (3)  (4)  (5): ";
	cin >> choice;
	system("cls");
	switch(choice)
	{
	case 1:
		if(file.is_open())
		{
			while( ! file.eof() )
			{
				getline(file, line);
				file >> name;
				file >> playerClass;
				file >> armor;
				file >> str;
				file >> agi;
				file >> intl;
				file >> hp;
				file >> mana;
				file >> maxHP;
				file >> maxMana;
				file >> expCap;
				file >> exp;
				file >> level;	
				file >> gold;
				file >> str_ironSword;
				if(str_ironSword == "Iron")
					ironSword = true;
			}
			file1.close();
		}
		else
		{
			cout << "Error Opening File Player.txt" << endl;
		}
		break;
	case 2:
		if(file.is_open())
		{
			while( ! file.eof() )
			{
				getline(file, line);
				file1 >> name;
				file1 >> playerClass;
				file1 >> armor;
				file1 >> str;
				file1 >> agi;
				file1 >> intl;
				file1 >> hp;
				file1 >> mana;
				file1 >> maxHP;
				file1 >> maxMana;
				file1 >> expCap;
				file1 >> exp;
				file1 >> level;	
				file1 >> gold;
			}
			file1.close();
		}
		else
		{
			cout << "Error Opening File Player.txt" << endl;
		}
		break;
	case 3:
		if(file.is_open())
		{
			while( ! file.eof() )
			{
				getline(file, line);
				file2 >> name;
				file2 >> playerClass;
				file2 >> armor;
				file2 >> str;
				file2 >> agi;
				file2 >> intl;
				file2 >> hp;
				file2 >> mana;
				file2 >> maxHP;
				file2 >> maxMana;
				file2 >> expCap;
				file2 >> exp;
				file2 >> level;	
				file2 >> gold;
			}
			file2.close();
		}
		else
		{
			cout << "Error Opening File Player.txt" << endl;
		}
		break;
	case 4:
		if(file.is_open())
		{
			while( ! file.eof() )
			{
				getline(file, line);
				file3 >> name;
				file3 >> playerClass;
				file3 >> armor;
				file3 >> str;
				file3 >> agi;
				file3 >> intl;
				file3 >> hp;
				file3 >> mana;
				file3 >> maxHP;
				file3 >> maxMana;
				file3 >> expCap;
				file3 >> exp;
				file3 >> level;	
				file3 >> gold;
			}
			file3.close();
		}
		else
		{
			cout << "Error Opening File Player.txt" << endl;
		}
		break;
	case 5:
		if(file.is_open())
		{
			while( ! file.eof() )
			{
				getline(file, line);
				file4 >> name;
				file4 >> playerClass;
				file4 >> armor;
				file4 >> str;
				file4 >> agi;
				file4 >> intl;
				file4 >> hp;
				file4 >> mana;
				file4 >> maxHP;
				file4 >> maxMana;
				file4 >> expCap;
				file4 >> exp;
				file4 >> level;	
				file4 >> gold;
			}
			file4.close();
		}
		else
		{
			cout << "Error Opening File Player.txt" << endl;
		}
		break;
	}
}
// Function for Equipped Items
void Equipped()
{
	if(ironSword  || str_ironSword == "Iron Sword")
		cout << " Main Weapon: Iron Sword" << endl;
	else if(bronzeSword)
		cout << " Main Weapon: Bronze Sword" << endl;
	else if(woodenStaff)
		cout << " Main Weapon: Wooden Staff" << endl;
	else if(medusaHead)
		cout << " Secondary Weapon: Medusa's Head" << endl;
	else if(leatherVest)
		cout << " Chest Armor: Leather Vest" << endl;
	else
		cout << " No items equipped." << endl;

	system("Pause");

}