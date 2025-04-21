#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// created a struct to hold a user attributes
typedef struct{
    int Health;
    int Stamina;
    int Strength;
} Character;

// function prototype
int Train(Character *user);
int Battle(Character *user);
int Rest(Character *user);


int Rest(Character *user){
    // to generate a random number for how much stamina the user gains from resting
    int RestGained = rand() % 10+1;

    user->Stamina = user->Stamina + RestGained;
    printf("you decided to rest and your stamina increased to %d",user->Stamina);
    return 0;
}

int Battle(Character *user) {

    // generates a random number from the ranges of 1-50
    int EnemyStrength = rand()% 50 +1,EnemyHealth = rand()% 50 ;

    printf("You challenged an orc to a fight and he gives you a chance to land the first blow\n");

    // loops until your health is zero
    while(user->Health != 0) {

        printf("You attack the orc with all your might for %d\n",user->Strength);
        EnemyHealth=EnemyHealth-user->Strength;
        user->Stamina-=1;

        if (user->Stamina <= 0 && EnemyHealth <=0) {
            printf("You hit the orc with all your power and you fall to the ground from pure exhaustion\n");
            printf("you watch the orc star tipping forward and realise hes gonna flatten you with his massive body\n");
            printf("you get squished and died from the impact");
            return 0;
        }

        if (user->Stamina <= 0) {
            printf("you was overly exhausted and passed out info of the orc");
            return 0;
        }

        if(EnemyHealth <= 0) {
            printf("Somehow you knocked the orc out with your mighty punch");
            return 0;
        }

        printf("The orc hits you with it club for %d\n",EnemyStrength);
        user->Health -= EnemyStrength;

        if (user->Health <= 0) {
            printf("you got hit so hard you started to see stars and realised you was actually hit so hard you ended up in space");
            return 0;
        }

    }
}


int Train(Character *user) {
    int Hours;

    printf("Enter how many hours your character trains: ");
    scanf("%d", &Hours);

    // uses pointer to access the value in the struct Character's and edits them
    user->Strength += Hours;
    user->Stamina -= Hours;

    // if statement to handle the scenario of if the user runs out of stamina
    if (user->Stamina <= 0) {
        printf("You trained so hard you dropped a 500kg weight on your pinkie toe and passed out\n");
        printf("You then smack your head into a table and died");
        return 0;
    }

    printf("your character new strength is %d and your stamina is at %d",user->Strength,user->Stamina);

    return 0;

}


int main(){

    // Initialize the randomizer using the current timestamp as a seed
    // (The time() function is provided by the <time.h> header file)
    srand(time(NULL));

    // used enum to improve readability and use less storage as its local
    enum {TRAIN= 1,BATTLE=2,REST=3,EXIT=4};

    Character user = {50,50,30};
    int UserChoice;

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
                Train(&user);
                break;
            case BATTLE:
                Battle(&user);
                break;
            case REST:
                Rest(&user);
                break;
            case EXIT:
                return 0;
            default:
                printf("Pick a valid option");
        }
    }while(UserChoice < TRAIN || UserChoice > EXIT);

    return 0;
}