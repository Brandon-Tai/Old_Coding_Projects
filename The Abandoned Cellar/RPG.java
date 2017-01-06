
import java.util.Scanner;
import java.util.Random;
public class RPG {

	public static void main(String[] args) {

		// Menu Variables
		int menuChoice;
		Scanner scanMenuChoice = new Scanner(System.in);
		
		// Character Variables
		int level = 1;
		int health = 100;
		int maxHP = 100;
		int gold = 0;
		int weapon = 1;
		int armor = 0;
		int critical;
		Random crit = new Random();
		
		// Menu
		System.out.println("|| MENU ||\n\n(1) Start New Game\n(2) Load Saved Game\n(3) Quit");
		menuChoice = scanMenuChoice.nextInt();
		
		if(menuChoice == 1){
			
			// Chapter 1
			
			// Chapter 1 Variables
			int choice1;
			Scanner scanCh1Choice = new Scanner(System.in);
			
			System.out.println("You awake, lying on the floor of an old cellar.\nYou are wearing light cloth clothes.\nYou get up and look around to see wine barrels.\n");
			System.out.println("What would you like to do?");
			System.out.println("(1) Check Barrels\n(2) Leave Room\n");
			
			choice1 = scanCh1Choice.nextInt();
			
			if(choice1 == 1){
				System.out.println("You find a stick. You will now use it as a weapon.\n");
				weapon = 2;
				System.out.println("You leave the room and see a giant cellar rat glaring at you.\n");
			}
			else if(choice1 == 2){
				System.out.println("You leave the room and see a giant cellar rat glaring at you.\n");
			}
			
			// Rat Encounter
			
			// Rat Variables
			int ratChoice;
			Scanner scanRat = new Scanner(System.in);
			int ratLvl = 1;
			int ratHP = 20;
			int ratDMG = 2;
			int ratGold = 5;
			int ratCrit;
			
			System.out.println("Would you like to:\n(1) Fight\n(2) Run");
			
			ratChoice = scanRat.nextInt();
			
			if(ratChoice == 2){
				System.out.println("You have nowhere to run!");
			}
			
			// Fight
			
			System.out.println("You engage the giant cellar rat!");
			
			while(ratHP > 0 && health > 0){
				System.out.println("You have " + health + "/" + maxHP + " health.");
				
				// Rat Bloodied
				if(ratHP <= 20 && ratHP > 15){
					System.out.println("The giant cellar rat does not look injured at all.\n");
				}
				if(ratHP <= 15 && ratHP > 10){
					System.out.println("The giant cellar rat looks slightly injured.\n");
				}
				if(ratHP <= 10 && ratHP > 5){
					System.out.println("The giant cellar rat is not looking good. It looks badly injured.\n");
				}
				if(ratHP <= 5){
					System.out.println("The giant cellar rat looks as if it is barely clinging on to life. It is shaking and about to fall over.\n");
				}
				
				System.out.println("\n(1) Attack\n");
				ratChoice = scanRat.nextInt();
				
				// For random criticals
				critical = crit.nextInt(10);
				
				Random ratCritGen = new Random();
				ratCrit = ratCritGen.nextInt(10);
				
				// Your Attack
				if(weapon == 1){
					if(critical == 0){
						System.out.println("\nYou feel a great ninja power rush through your hands. You punch the giant cellar rat and it takes 4 damage.");
						ratHP = ratHP - (weapon + level) * 2;
						
					}
					else if(critical == 9){
						System.out.println("\nYou are suddenly distracted by a centipede scurrying along the floor. His name is Steve. :D");
					}
					else {
						System.out.println("\nYou poke the giant cellar rat and it takes 2 damage.");
						ratHP = ratHP - (weapon + level);
					}
				}
				else if(weapon == 2){
					if(critical == 0){
						System.out.println("\nYou feel a great power rush through your veins. You bash the giant cellar rat with your stick and it takes 6 damage.");
						ratHP = ratHP - (weapon + level) * 2;
					}
					else if(critical == 9){
						System.out.println("\nYou are suddenly distracted by a centipede scurrying along the floor. His name is Steve. :D");
					}
					else {
						System.out.println("\nYou hit the giant cellar rat with your stick and it takes 3 damage.");
						ratHP = ratHP - (weapon + level);
					}
				}
				
				// Rat's Attack
				if(ratHP > 0){
					if(ratCrit == 0){
						System.out.println("\nThe giant cellar rat goes into a ferocious frenzy. It jumps at you and bites at your neck. You take 6 damage!");
						health = health - (ratDMG + ratLvl) * 2;
					}
					else if(ratCrit == 9){
						System.out.println("\nThe giant cellar rat seems distracted. It does not even acknowledge your presence.");
					}
					else {
						System.out.println("\nThe giant cellar rat scratches at your leg. You take 3 damage.");
						health = health - (ratDMG + ratLvl);
					}
				}
				
			}
			if(health <= 0){
				System.out.println("Game Over");
				return;
			}
			
			System.out.println("You have defeated the giant cellar rat!\nIt dropped 5 gold!\n\nYou levelled up!");
			
			gold = gold + ratGold;
			
			level++;
			
			health = health + 50;
			maxHP = maxHP + 50;
			
			System.out.println("You are level " + level);
			System.out.println("You have " + health +  "/" + maxHP + " health");
			System.out.println("You have " + gold + " gold");
			
			if(weapon == 2){
				System.out.println("You have a stick");
			}
				
			// Rat Encounter 2
			
			// Rat 1 Variables
			int ratLvl1 = 1;
			int ratHP1 = 20;
			int ratDMG1 = 2;
			int ratGold1 = 5;
			int ratCrit1;
			
			// Rat 2 Variables
			int ratLvl2 = 1;
			int ratHP2 = 20;
			int ratDMG2 = 2;
			int ratGold2 = 5;
			int ratCrit2;
			
			System.out.println("Fighting with that rat has startled 2 others. 2 giant cellar rats scurry towards you!");
			
			System.out.println("Would you like to:\n(1) Fight\n(2) Run");
						
			ratChoice = scanRat.nextInt();
						
			if(ratChoice == 2){
				System.out.println("You cannot get away!");
			}
						
			// Fight
					
			System.out.println("You engage the 2 giant cellar rats!");
						
			while(ratHP1 > 0 || ratHP2 > 0 && health > 0){
				System.out.println("\nYou have " + health +  "/" + maxHP + " health.\n");
							
				// Rat 1 Bloodied
				if(ratHP1 <= 20 && ratHP1 > 15){
					System.out.println("The first giant cellar rat does not look injured at all.\n");
				}
				if(ratHP1 <= 15 && ratHP1 > 10){
					System.out.println("The first giant cellar rat looks slightly injured.\n");
				}
				if(ratHP1 <= 10 && ratHP1 > 5){
					System.out.println("The first giant cellar rat is not looking good. It looks badly injured.\n");
				}
				if(ratHP1 <= 5 && ratHP1 > 0){
					System.out.println("The first giant cellar rat looks as if it is barely clinging on to life. It is shaking and about to fall over.\n");
				}
				if(ratHP1 <= 0){
					System.out.println("The first giant cellar rat is dead.\n");
				}
				
				// Rat 2 Bloodied
				if(ratHP2 <= 20 && ratHP2 > 15){
					System.out.println("The second giant cellar rat does not look injured at all.\n");
				}
				if(ratHP2 <= 15 && ratHP2 > 10){
					System.out.println("The second giant cellar rat looks slightly injured.\n");
				}
				if(ratHP2 <= 10 && ratHP2 > 5){
					System.out.println("The second giant cellar rat is not looking good. It looks badly injured.\n");
				}
				if(ratHP2 <= 5 && ratHP2 > 0){
					System.out.println("The second giant cellar rat looks as if it is barely clinging on to life. It is shaking and about to fall over.\n");
				}
				if(ratHP2 <= 0){
					System.out.println("The second giant cellar rat is dead.\n");
				}
				
				if(ratHP1 > 0 && ratHP2 > 0){
					System.out.println("\n(1) Attack the first giant cellar rat\n(2) Attack the second cellar rat\n");	
				}
				if(ratHP1 > 0 && ratHP2 <= 0){
					System.out.println("\n(1) Attack the first giant cellar rat\n");	
				}
				if(ratHP1 <= 0 && ratHP2 > 0){
					System.out.println("\n(2) Attack the second cellar rat\n");	
				}
							
				
				ratChoice = scanRat.nextInt();
							
				// For random criticals
				critical = crit.nextInt(10);
							
				Random ratCritGen1 = new Random();
				ratCrit1 = ratCritGen1.nextInt(10);
				
				Random ratCritGen2 = new Random();
				ratCrit2 = ratCritGen2.nextInt(10);
							
				// Your Attack
				
				if(ratChoice == 1 && ratHP1 > 0){
					if(weapon == 1){
						if(critical == 0){
							System.out.println("\nYou feel a great ninja power rush through your hands. You punch the giant cellar rat and it takes 4 damage.");
							ratHP1 = ratHP1 - (weapon + level) * 2;
										
						}
						else if(critical == 9){
							System.out.println("\nYou are suddenly distracted by a centipede scurrying along the floor. His name is Steve. :D");
						}
						else {
							System.out.println("\nYou poke the giant cellar rat and it takes 2 damage.");
							ratHP1 = ratHP1 - (weapon + level);
						}
					}
					else if(weapon == 2){
						if(critical == 0){
							System.out.println("\nYou feel a great power rush through your veins. You bash the giant cellar rat with your stick and it takes 6 damage.");
							ratHP1 = ratHP1 - (weapon + level) * 2;
						}
						else if(critical == 9){
							System.out.println("\nYou are suddenly distracted by a centipede scurrying along the floor. His name is Steve. :D");
						}
						else {
							System.out.println("\nYou hit the giant cellar rat with your stick and it takes 3 damage.");
							ratHP1 = ratHP1 - (weapon + level);
						}
					}

					// Rat 1's Attack
					if(ratHP1 > 0){
						if(ratCrit1 == 0){
							System.out.println("\nThe giant cellar rat goes into a ferocious frenzy. It jumps at you and bites at your neck. You take 6 damage!");
							health = health - (ratDMG1 + ratLvl1) * 2;
						}
						else if(ratCrit1 == 9){
							System.out.println("\nThe giant cellar rat seems distracted. It does not even acknowledge your presence.");
						}
						else {
							System.out.println("\nThe giant cellar rat scratches at your leg. You take 3 damage.");
							health = health - (ratDMG1 + ratLvl1);
						}
					}
					
					// Rat 2's Attack
					if(ratHP2 > 0){
						if(ratCrit2 == 0){
							System.out.println("\nThe giant cellar rat goes into a ferocious frenzy. It jumps at you and bites at your neck. You take 6 damage!");
							health = health - (ratDMG2 + ratLvl2) * 2;
						}
						else if(ratCrit2 == 9){
							System.out.println("\nThe giant cellar rat seems distracted. It does not even acknowledge your presence.");
						}
						else {
							System.out.println("\nThe giant cellar rat scratches at your leg. You take 3 damage.");
							health = health - (ratDMG2 + ratLvl2);
						}
					}
				}
				else if(ratChoice == 2 && ratHP2 > 0){
					if(weapon == 1){
						if(critical == 0){
							System.out.println("\nYou feel a great ninja power rush through your hands. You punch the giant cellar rat and it takes 4 damage.");
							ratHP2 = ratHP2 - (weapon + level) * 2;
										
						}
						else if(critical == 9){
							System.out.println("\nYou are suddenly distracted by a centipede scurrying along the floor. His name is Steve. :D");
						}
						else {
							System.out.println("\nYou poke the giant cellar rat and it takes 2 damage.");
							ratHP2 = ratHP2 - (weapon + level);
						}
					}
					else if(weapon == 2){
						if(critical == 0){
							System.out.println("\nYou feel a great power rush through your veins. You bash the giant cellar rat with your stick and it takes 6 damage.");
							ratHP2 = ratHP2 - (weapon + level) * 2;
						}
						else if(critical == 9){
							System.out.println("\nYou are suddenly distracted by a centipede scurrying along the floor. His name is Steve. :D");
						}
						else {
							System.out.println("\nYou hit the giant cellar rat with your stick and it takes 3 damage.");
							ratHP2 = ratHP2 - (weapon + level);
						}
					}

					// Rat 1's Attack
					if(ratHP1 > 0){
						if(ratCrit1 == 0){
							System.out.println("\nThe giant cellar rat goes into a ferocious frenzy. It jumps at you and bites at your neck. You take 6 damage!");
							health = health - (ratDMG1 + ratLvl1) * 2;
						}
						else if(ratCrit1 == 9){
							System.out.println("\nThe giant cellar rat seems distracted. It does not even acknowledge your presence.");
						}
						else {
							System.out.println("\nThe giant cellar rat scratches at your leg. You take 3 damage.");
							health = health - (ratDMG1 + ratLvl1);
						}
					}
					
					// Rat 2's Attack
					if(ratHP2 > 0){
						if(ratCrit2 == 0){
							System.out.println("\nThe giant cellar rat goes into a ferocious frenzy. It jumps at you and bites at your neck. You take 6 damage!");
							health = health - (ratDMG2 + ratLvl2) * 2;
						}
						else if(ratCrit2 == 9){
							System.out.println("\nThe giant cellar rat seems distracted. It does not even acknowledge your presence.");
						}
						else {
							System.out.println("\nThe giant cellar rat scratches at your leg. You take 3 damage.");
							health = health - (ratDMG2 + ratLvl2);
						}
					}
				}
							
			}
			if(health <= 0){
				System.out.println("Game Over");
				return;
			}
			
			System.out.println("You have defeated the 2 giant cellar rats!\nThey dropped 10 gold!\n\nYou levelled up!");
			
			gold = gold + ratGold1 + ratGold2;
			
			level++;
			
			health = health + 75;
			maxHP = maxHP + 75;
			
			System.out.println("You are level " + level);
			System.out.println("You have " + health +  "/" + maxHP + " health");
			System.out.println("You have " + gold + " gold");
			
			if(weapon == 2){
				System.out.println("You have a stick");
			}
			
			// Chapter 2
			
			// Chapter 2 Variables
			int choice2;
			Scanner scanCh2Choice = new Scanner(System.in);
			boolean torch = false;
			
			System.out.println("You see an old, wet stone hallway leading to a staircase.\n");
			
			System.out.println("What would you like to do?");
			
			System.out.println("(1) Walk to the stairs\n(2) Look around\n");
			
			choice2 = scanCh2Choice.nextInt();
			
			if(choice2 == 2){
				System.out.println("The hallway is barely lit by a dim torch.\n");
				
				System.out.println("What would you like to do?");
				
				System.out.println("(1) Walk to the stairs\n(2) Look around\n");
				
				choice2 = scanCh2Choice.nextInt();
				
				if(choice2 == 2){
					System.out.println("The dim torch in a holster in the wall.\n");
					
					System.out.println("What would you like to do?");
					
					System.out.println("(1) Walk to the stairs\n(2) Look around\n");
					
					choice2 = scanCh2Choice.nextInt();
					
					if(choice2 == 2){
						System.out.println("The dim torch is loose. It looks as if it can be easily removed.\n");
						
						System.out.println("What would you like to do?");
						
						System.out.println("(1) Walk to the stairs\n(2) Take the torch\n");
						
						choice2 = scanCh2Choice.nextInt();
						
						if(choice2 == 2){
							weapon = 3;
							torch = true;
						}
					}
				}
			}
			
			// Torch Encounter
			
			// Variable
			boolean gotChest = false;
			
			if(torch == true){
				System.out.println("You remove the torch from its holster.\nSuddenly, you hear a loud rumbling and a section of the wall lowers down, revealing a secret room.\n");
				System.out.println("In the room you find a chest.\n");
				
				System.out.println("What would you like to do?");
				
				System.out.println("(1) Open the chest\n(2) Leave\n");
				
				choice2 = scanCh2Choice.nextInt();
				
				if(choice2 == 1){
					System.out.println("You walk up to the chest.\nHowever, the loud rumbling of the wall startled a wolf who was hiding in the shadows.");
					
					System.out.println("Would you like to:\n(1) Fight\n(2) Run");
					
					choice2 = scanCh2Choice.nextInt();
					
					if(choice2 == 2){
						System.out.println("You back away from the wolf and trip over the chest.\n");
						
						System.out.println("What would you like to do?");
						
						System.out.println("(1) Fight\n(2) Open the chest\n");
						
						choice2 = scanCh2Choice.nextInt();
						
						if(choice2 == 2){
							gotChest = true;
							armor = 1;
							gold = gold + 20;
							
							System.out.println("You find some leather armor in the chest and 20 gold.\n");
						}
					}
					System.out.println("You engage the wolf!");
				}
			}
			
			// If not torch
			if(torch == false){
				System.out.println("You walk to the stairs. Suddenly, you are ambushed by a wolf who was hiding in the shadows!\n");
			}
			
			// Wolf Encounter
			
			// Wolf Variables
			int wolfChoice;
			Scanner wolfScan = new Scanner(System.in);
			int wolfLvl = 2;
			int wolfHP = 60;
			int wolfDMG = 3;
			int wolfGold = 15;
			int wolfCrit;
			
			// Fight
			
			while(wolfHP > 0 && health > 0){
				System.out.println("You have " + health +  "/" + maxHP + " health.");
				
				// Wolf Bloodied
				if(wolfHP <= 60 && wolfHP > 50){
					System.out.println("The wolf does not look injured at all.\n");
				}
				if(wolfHP <= 50 && wolfHP > 40){
					System.out.println("The wolf looks slightly injured.\n");
				}
				if(wolfHP <= 40 && wolfHP > 30){
					System.out.println("The wolf is hurting.\n");
				}
				if(wolfHP <= 30 && wolfHP > 20){
					System.out.println("The wolf is not looking good. It looks badly injured.\n");
				}
				if(wolfHP <= 20 && wolfHP > 10){
					System.out.println("The wolf looks terrible. It looks heavily wounded.\n");
				}
				if(wolfHP <= 10){
					System.out.println("The wolf looks as if it is barely clinging on to life. It is shaking and about to fall over.\n");
				}
				
				System.out.println("\n(1) Attack\n");
				wolfChoice = wolfScan.nextInt();
				
				// For random criticals
				critical = crit.nextInt(10);
				
				Random wolfCritGen = new Random();
				wolfCrit = wolfCritGen.nextInt(10);
				
				// Your Attack
				if(weapon == 1){
					if(critical == 0){
						System.out.println("\nYou feel a great ninja power rush through your hands. You punch the wolf and it takes " + (weapon + level) * 2 + " damage.");
						wolfHP = wolfHP - (weapon + level) * 2;
						
					}
					else if(critical == 9){
						System.out.println("\nYou are suddenly distracted by a centipede scurrying along the floor. His name is Steve. :D");
					}
					else {
						System.out.println("\nYou poke the wolf and it takes " + (weapon + level) + " damage.");
						wolfHP = wolfHP - (weapon + level);
					}
				}
				else if(weapon == 2){
					if(critical == 0){
						System.out.println("\nYou feel a great power rush through your veins. You bash the wolf with your stick and it takes " + (weapon + level) * 2 + " damage.");
						wolfHP = wolfHP - (weapon + level) * 2;
					}
					else if(critical == 9){
						System.out.println("\nYou are suddenly distracted by a centipede scurrying along the floor. His name is Steve. :D");
					}
					else {
						System.out.println("\nYou hit the wolf with your stick and it takes " + (weapon + level) + " damage.");
						wolfHP = wolfHP - (weapon + level);
					}
				}
				else if(weapon == 3){
					if(critical == 0){
						System.out.println("\nYou see an opportunity. You burn the wolf with your torch and it takes " + (weapon + level) * 2 + " damage.");
						wolfHP = wolfHP - (weapon + level) * 2;
					}
					else if(critical == 9){
						System.out.println("\nYou are suddenly distracted by a centipede scurrying along the floor. His name is Steve. :D");
					}
					else {
						System.out.println("\nYou poke the wolf with your torch and it takes " + (weapon + level) + " damage.");
						wolfHP = wolfHP - (weapon + level);
					}
				}
				
				// Wolf's Attack
				if(wolfHP > 0){
					if(wolfCrit == 0){
						System.out.println("\nThe wolf looks mad. It pounces on you and gashes at your chest. You take " + (((wolfDMG + wolfLvl) * 2) - armor) + " damage!");
						health = health - (((wolfDMG + wolfLvl) * 2) - armor);
					}
					else if(wolfCrit == 9){
						System.out.println("\nThe wolf seems distracted. It does not even acknowledge your presence.");
					}
					else {
						System.out.println("\nThe wolf bites at your leg. You take " + ((wolfDMG + wolfLvl) - armor) + " damage.");
						health = health - ((wolfDMG + wolfLvl) - armor);
					}
				}
				
			}
			if(health <= 0){
				System.out.println("Game Over");
				return;
			}
			
			System.out.println("You have defeated the wolf!\nIt dropped 15 gold!\n\nYou levelled up!");
			
			gold = gold + wolfGold;
			
			level++;
			
			health = health + 100;
			maxHP = maxHP + 100;
			
			System.out.println("You are level " + level);
			System.out.println("You have " + health +  "/" + maxHP + " health");
			System.out.println("You have " + gold + " gold");
		
			if(weapon == 2){
				System.out.println("You have a stick");
			}
			
			if(weapon == 3){
				System.out.println("You have a torch");
			}
			
			if(armor == 1){
				System.out.println("You have leather armor");
			}
			
			// After Wolf Encounter
			
			if(gotChest == false && torch == false){

				// Variables
				int choice3;
				Scanner scanChoice3 = new Scanner(System.in);	
				
				System.out.println("(1) Walk up the stairs\n(2) Look around\n");
				
				choice3 = scanChoice3.nextInt();
				
				if(choice3 == 2){
					System.out.println("The hallway is barely lit by a dim torch.\n");
					
					System.out.println("What would you like to do?");
					
					System.out.println("(1) Walk to the stairs\n(2) Look around\n");
					
					choice3 = scanChoice3.nextInt();
					
					if(choice3 == 2){
						System.out.println("The dim torch is in a holster in the wall.\n");
					
						System.out.println("What would you like to do?");
						
						System.out.println("(1) Walk to the stairs\n(2) Look around\n");
						
						choice2 = scanChoice3.nextInt();
						
						if(choice3 == 2){
							System.out.println("The dim torch is loose. It looks as if it can be easily removed.\n");
							
							System.out.println("What would you like to do?");
							
							System.out.println("(1) Walk to the stairs\n(2) Take the torch\n");
							
							choice3 = scanChoice3.nextInt();
							
							if(choice3 == 2){
								weapon = 3;
								torch = true;
								
								System.out.println("You remove the torch from its holster.\nSuddenly, you hear a loud rumbling and a section of the wall lowers down, revealing a secret room.\n");
								System.out.println("In the room you find a chest.\n");
							
								System.out.println("What would you like to do?");
								
								System.out.println("(1) Open the chest\n(2) Leave\n");
								
								choice3 = scanChoice3.nextInt();
								
								if(choice3 == 1){
									System.out.println("You walk up to the chest and open it.\n");
									gotChest = true;
									
									armor = 1;
									gold = gold + 20;
									
									System.out.println("You find some leather armor in the chest and 20 gold.\n");
									
									System.out.println("You are level " + level);
									System.out.println("You have " + health +  "/" + maxHP + " health");
									System.out.println("You have " + gold + " gold");
									
									if(weapon == 2){
										System.out.println("You have a stick");
									}
									
									if(weapon == 3){
										System.out.println("You have a torch");
									}
									
									if(armor == 1){
										System.out.println("You have leather armor");
									}
								}
							}
						}
					}
				}
				
			}
			if(gotChest == false && torch == true){

				// Variables
				int choice3;
				Scanner scanChoice3 = new Scanner(System.in);	
				
				System.out.println("What would you like to do?");
				
				System.out.println("(1) Open the chest\n(2) Leave\n");
				
				choice3 = scanChoice3.nextInt();
				
				if(choice3 == 1){
					System.out.println("You walk up to the chest and open it.\n");
					gotChest = true;
					
					armor = 1;
					gold = gold + 20;
					
					System.out.println("You find some leather armor in the chest and 20 gold.\n");
					
					System.out.println("You are level " + level);
					System.out.println("You have " + health +  "/" + maxHP + " health");
					System.out.println("You have " + gold + " gold");
					
					if(weapon == 2){
						System.out.println("You have a stick");
					}
					
					if(weapon == 3){
						System.out.println("You have a torch");
					}
					
					if(armor == 1){
						System.out.println("You have leather armor");
					}
				}
				
			}
			
			// Chapter 3
			
			// Variables
			int Ch3choice;
			Scanner scanCh3Choice = new Scanner(System.in);	
			
			System.out.println("You walk up the stairs into an old room with a couple of barrels of wine.\n");
			
			System.out.println("What would you like to do?");
			
			System.out.println("(1) Leave\n(2) Look around\n");
			
			Ch3choice = scanCh3Choice.nextInt();
			
			if(Ch3choice == 2){
				System.out.println("There is also a counter, tables, and chairs.\n");
				
				System.out.println("What would you like to do?");
				
				System.out.println("(1) Leave\n(2) Look around\n");
				
				Ch3choice = scanCh3Choice.nextInt();
				
				if(Ch3choice == 2){
					System.out.println("It looks as though it used to be a bar.\n");
					
					System.out.println("What would you like to do?");
					
					System.out.println("(1) Leave\n");
					
					Ch3choice = scanCh3Choice.nextInt();
				}
			}
			
			// Leave abandoned bar
			System.out.println("You exit out the door.\n When you open the door, it collapses.");
			System.out.println("You walk outside into a clearing on a hill overlooking a small town.\n");
			
			System.out.println("What would you like to do?");
			
			System.out.println("(1) Walk to town\n(2) Look around\n");
			
			Ch3choice = scanCh3Choice.nextInt();
			
			if(Ch3choice == 2){
				System.out.println("You look around. It is late and starting to get too dark to see.\n");
				
				System.out.println("What would you like to do?");
				
				System.out.println("(1) Walk to town\n(2) Look around\n");
				
				Ch3choice = scanCh3Choice.nextInt();
				
				if(Ch3choice == 2){
					System.out.println("It is getting dark.\n");
					
					System.out.println("What would you like to do?");
					
					System.out.println("(1) Walk to town\n(2) Look around\n");
					
					Ch3choice = scanCh3Choice.nextInt();
				
					if(Ch3choice == 2){
						System.out.println("It is getting very dark.\n");
					
						System.out.println("What would you like to do?");
					
						System.out.println("(1) Walk to town\n(2) Look around\n");
					
						Ch3choice = scanCh3Choice.nextInt();
					
						if(Ch3choice == 2){
							System.out.println("You should get to town soon, it is getting hard to see the town.\n");
							
							System.out.println("What would you like to do?");
							
							System.out.println("(1) Walk to town\n(2) Look around\n");
						
							Ch3choice = scanCh3Choice.nextInt();
						
							if(Ch3choice == 2){
								System.out.println("It is too dark to see the town anymore.\n");
							
								System.out.println("What would you like to do?");
							
								System.out.println("(1) Try to walk to where you think the town is\n(2) Look around\n");
								
								Ch3choice = scanCh3Choice.nextInt();
								
								if(Ch3choice == 2){
									System.out.println("You cannot see anything.\n");
								
									System.out.println("What would you like to do?");
								
									System.out.println("(1) Try to walk to where you think the town is\n");
								
									Ch3choice = scanCh3Choice.nextInt();
								}
							}
						}
						
					}
				}
			}
			
			// Going to town
			System.out.println("You walk into town. There is no one outside, but some light emanates from windows.\n");
			System.out.println("You see an inn.\n");
		
			System.out.println("What would you like to do?");
			
			System.out.println("(1) Go in\n");
			
			Ch3choice = scanCh3Choice.nextInt();
			
			System.out.println("You enter the inn.\nIt is a quiet inn with a few customers and a friendly looking innkeeper.\nThe innkeeper greets you.\n");
			
			// Innkeeper Conversation
			System.out.println("Would you like a room for the night? You look exhausted.");
		
			System.out.println("(1) Yes\n(2) Thanks, but I am good\n");
		
			Ch3choice = scanCh3Choice.nextInt();
		
			if(Ch3choice == 2){
				System.out.println("You don't look good. You should spend the night.");
			
				System.out.println("(1) Ok, thanks\n(2) I DON'T WANT TO SPEND THE NIGHT!!!\n");
			
				Ch3choice = scanCh3Choice.nextInt();
			
				if(Ch3choice == 2){
					System.out.println("Yes you do.");
				
					System.out.println("(1) I do? Oh, ok sure.\n");
				
					Ch3choice = scanCh3Choice.nextInt();
				}
			}
			
			System.out.println("That will be 10 gold, please.\n\n(hand over gold)\n\nThank you!\n");
			
			gold = gold - 10;
			
			System.out.println("You have " + gold + " gold.\n");
			
			System.out.println("It is rough times, and everybody should be ready for anything.\nThe leader of the town has issued armor and weapons to everyone in the town.\n");
			System.out.println("So, since you have a room here, here you go!\n(hands you a dull sword and some used chainmail armor)\n");
			System.out.println("You go up to your room and sleep for the night.");
			
			System.out.println("You have reached a CHECKPOINT! To get back here, \"Load Saved Game\" and type in the code \"CHAINMAIL\" to skip to this checkpoint.");
			
			health = maxHP;
			
			System.out.println("You are level " + level);
			System.out.println("You have " + health +  "/" + maxHP + " health");
			System.out.println("You have " + gold + " gold");
			
			System.out.println("You have a dull sword");
			System.out.println("You have used chainmail armor");
			
			weapon = 4;
			
			armor = 2;
		}
		else if (menuChoice == 2){
			
		}
		
	}

}
