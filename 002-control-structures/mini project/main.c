#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define TRAIN 1
#define BATTLE 2
#define REST 3
#define EXIT 4

// function prototype
int Train(int Strength,int Stamina);
int Battle(int Strength,int Stamina,int Health);
int Rest(int Stamina);

int Rest(int Stamina) {
    // to generate a random number for how much stamina the user gains from resting
    int RestGained = rand() % 10+1;

    Stamina = Stamina + RestGained;
    printf("you decided to rest and your stamina incresed to %d",Stamina);
    return 0;
}

int Battle(int Strength,int Stamina,int Health) {

    // Initialize the randomizer using the current timestamp as a seed
    // (The time() function is provided by the <time.h> header file)
    srand(time(NULL));

    // generates a random number from the ranges of 1-50
    int EnemyStrength= rand()% 50 +1;
    int EnemyHealth = rand()% 50 +1;

    printf("You challenged an orc to a fight and he gives you a chance to land the first blow\n");

    // loops until your health is zero
    while(Health != 0) {
        printf("You attack the orc with all your might for %d\n",Strength);
        EnemyHealth=EnemyHealth-Strength;
        Stamina--;

        if (Stamina <= 0 && EnemyHealth <=0) {
            printf("You hit the orc with all your power and you fall to the ground from pure exhausion\n");
            printf("you watch the orc star tipping forward and realise hes gonna flatten you with his massive body\n");
            printf("you get squished and died from the impact");
            break;
        }

        if (Stamina <= 0) {
            printf("you was overly exhausted and passed out infront of the orc");
            return 0;
        }

        if(EnemyHealth <= 0) {
            printf("Somehow you knocked the orc out with your mighty punch");
            break;
        }

        printf("The orc hits you with it club for %d",EnemyStrength);
        Health = Health - EnemyStrength;

        if (Health <= 0) {
            printf("you got hit so hard you started to see stars and realised you was actually hit so hard you ended up in space");
            return 0;
        }

    }
}


int Train(int Strength,int Stamina) {
    int Hours;

    printf("Enter how many hours your character trains: ");
    scanf("%d", &Hours);

    for(int i = 0; i < Hours; i++) {
        Strength++;
        Stamina --;

        if (Stamina == 0) {
            printf("your character has been overworked and died!\n");
            exit(0);
        }
    }
    printf("your character new strength is %d and your stamina is at %d",Strength,Stamina);

    return 0;

}


int main(){

    int UserChoice,Strength =50 ,Stamina= 30, Health = 50;

    do {
        // display a menu
        printf("Select one of these options\n");
        printf("1.Train\n");
        printf("2.Battle\n");
        printf("3.Rest\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &UserChoice);

        // To redirect the user to the correct function
        switch (UserChoice) {
            case TRAIN:
                Train(Strength, Stamina);
                break;
            case BATTLE:
                Battle(Strength, Stamina, Health);
                break;
            case REST:
                Rest(Stamina);
                break;
            case EXIT:
                return 0;
            default:
                printf("Pick a valid option");
        }
    }while(UserChoice < TRAIN || UserChoice > EXIT);

    return 0;
}