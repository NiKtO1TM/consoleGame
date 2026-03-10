#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(time(0));

    int play = 1;

    while (play == 1) {

        int playerHealth = 30;
        int maxHealth = 30;
        int playerAttack = 7;

        int monsterHealth = 35;
        int monsterAttack = 6;

        cout << "=== Mystery of the Dark Cave ===\n\n";

        cout << "You are a warrior standing at the entrance of a dark cave.\n";
        cout << "Villagers say a dangerous creature lives inside.\n";
        cout << "What will you do?\n\n";

        cout << "1 - Enter the cave\n";
        cout << "2 - Go back home\n";

        int startChoice;
        cin >> startChoice;

        if (startChoice == 2) {

            cout << "\nYou decided to go back home.\n";
            cout << "But the monster is still somewhere out there...\n";

        }
        else {

            cout << "\nYou step into the cave...\n";
            cout << "A wild Goblin jumps out of the shadows!\n";

            while (playerHealth > 0 && monsterHealth > 0) {

                cout << "\nYour health: " << playerHealth << endl;
                cout << "Goblin health: " << monsterHealth << endl;

                cout << "\nChoose your action:\n";
                cout << "1 - Attack\n";
                cout << "2 - Drink potion\n";

                int choice;
                cin >> choice;

                if (choice == 1) {

                    int damage = playerAttack + rand() % 4;
                    monsterHealth -= damage;

                    cout << "You hit the goblin and deal "
                        << damage << " damage!\n";

                }
                else if (choice == 2) {

                    int heal = 2 + rand() % 4;
                    playerHealth += heal;

                    if (playerHealth > maxHealth)
                        playerHealth = maxHealth;

                    cout << "You drink a potion and restore "
                        << heal << " health!\n";

                }
                else {

                    cout << "Invalid choice!\n";

                }

                if (monsterHealth > 0) {

                    int monsterDamage = monsterAttack + rand() % 4;

                    if (rand() % 5 == 0) {
                        monsterDamage *= 2;
                        cout << "The goblin makes a CRITICAL attack!\n";
                    }

                    playerHealth -= monsterDamage;

                    cout << "The goblin attacks and deals "
                        << monsterDamage << " damage!\n";

                }

            }

            if (playerHealth <= 0) {

                cout << "\nYou have fallen in battle...\n";
                cout << "Game Over.\n";

            }
            else {

                cout << "\nYou defeated the goblin!\n";
                cout << "The village is safe thanks to you!\n";

            }

        }

        cout << "\n====================\n";
        cout << "1 - Play again\n";
        cout << "2 - Exit\n";

        cin >> play;

    }

    cout << "\nThanks for playing!\n";

    return 0;
}