//
// Created by Robson Tavares Júnior on 31/10/18.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef EXERCICIO6A_39917_EXERCICIO6A_H
#define EXERCICIO6A_39917_EXERCICIO6A_H

int v1(){

    int i, age, biggestAge, numberOfPeople;
    float meanAge;

    age = -1;

    printf("How many people do you want to calculate the average age ? ");
    scanf("%d", &numberOfPeople);

    for(i=0; i<(numberOfPeople-1); i++){

        if(i == 0){
            do{
                printf("Enter the age of the first person: ");
                scanf("%d", &age);
                biggestAge = age;
                meanAge += age;

            }while(age<=0);
        }

        printf("Enter the age of the next person: ");
        scanf("%d", &age);

        if(age >= biggestAge){
            biggestAge = age;
        }

        meanAge += age;


    }

    printf("Average age is: %.2f\n", meanAge/numberOfPeople);
    printf("The biggest age is %.0f years.", biggestAge);


    return 0;
}

int v2(){

    int i, age, biggestAge;
    float meanAge, numberOfPeople=1;
    char stop[900];

    age = -1;
    strcpy(stop, "n");


    while(strcmp(stop, "n") == 0){

        if(numberOfPeople == 1){
            do{
                printf("Enter the age of the first person: ");
                scanf("%d", &age);
                biggestAge = age;
                meanAge += age;

                printf("Wanna stop the calculation ? y for yes, n for no ");
                scanf("%s", &stop);

                if(strcmp(stop, "y") == 0){
                    break;
                }
            }while(age<=0);
        }

        printf("Enter the age of the next person: ");
        scanf("%d", &age);

        if(age > biggestAge){
            biggestAge = age;
        }

        meanAge += age;
        numberOfPeople += 1;

        printf("Wanna stop the calculation ? y for yes, n for no ");
        scanf("%s", &stop);


    }

    printf("Average age is: %.2f\n", meanAge/numberOfPeople);
    printf("The biggest age is %d years.", biggestAge);

    return 0;
}

int v3(){

    float totalIA, biggestIA, lowestIA, IA, cc;
    int counter = 1;
    char name[900];

    printf("If you want to stop the program, please input as the owner's name the word end\n\n");

    printf("Name of the owner: ");
    scanf("%s", &name);

    while(strcmp(name, "end") != 0){
        if(counter == 1){
            printf("Please input the car's cylinder capacity: ");
            scanf("%f", &cc);
        }else{

            printf("Name of the owner: ");
            scanf("%s", &name);

            if(strcmp(name, "end") == 0){
                break;
            }else{
                printf("Please input the car's cylinder capacity: ");
                scanf("%f", &cc);
            }
        }

        if(cc <= 1250){

            IA = (3.74 * cc) - 2417.56;

        }else{

            IA = (8.86 * cc) - 8813.22;

        }

        //Assigning biggest and lowest IA
        if(counter == 1){

            biggestIA = IA;
            lowestIA = IA;

        }else{

            if(IA > biggestIA){
                biggestIA = IA;
            }else if(IA < lowestIA){
                lowestIA = IA;
            }

        }

        printf("%s owning a car with %.0f cylinder capacity pays %.2f of IA\n", name, cc, IA);

        // keeping count of the total IA
        totalIA += IA;
        counter += 1;

    }

    printf("Biggest IA is: %.2f\n", biggestIA);
    printf("Lowest IA is: %.2f\n", lowestIA);
    if(counter > 1){
        printf("Average IA is: %.2f\n", totalIA/(counter-1));
    }else{
        printf("Average IA is: %.2f\n", totalIA/(counter));
    }

    return 0;
}

int v4(){

    int weight,  biggestWeight = 0;
    float counterw1=0, counterw2=0, counterw3=0, counterw4=0, counterw5=0, counter=1;
    float height, imc, cumIMC, biggestIMC = 0, lowestIMC = 0;
    char name[900], biggestIMCName[900], lowestIMCName[900];

    // we need to initialize this char in order for the while-loop work properly
    printf("Enter the first person name ");
    scanf("%s", &name);

    weight = -1;

    while(strcmp(name, "fim") != 0) {

        //looping the first cycle
        if(weight<=0){

            do{

                printf("Enter the first person weight ");
                scanf("%d", &weight);

                printf("Enter the first person height ");
                scanf("%f", &height);

                //Assign biggest weight and name in case the first person inputted be the fattest.
                strcpy(biggestIMCName, name);

                //calculatin the "imc"
                imc = weight/pow(height,2);
                biggestIMC = imc;
                lowestIMC = imc;
                cumIMC = imc;

                //printing and counting accordingly IMC's table.
                if(imc < 19.1){

                    printf("%s has IMC %f which is below ideal weight\n", name, imc);
                    counterw1 += 1;

                } else if(imc >= 19.1 && imc < 25.8){
                    printf("%s has IMC %f which is ideal weight \n", name, imc);
                    counterw2 += 1;

                }else if(imc >= 25.8 && imc < 27.3){
                    printf("%s has IMC %f which is marginally above ideal weight \n", name, imc);
                    counterw3 += 1;

                }else if(imc >= 27.3 && imc < 32.3){
                    printf("%s has IMC %f which is above ideal weight \n", name, imc);
                    counterw4 += 1;
                }else{
                    printf("%s has IMC %f which is obese \n", name, imc);
                    counterw5 += 1;
                }

            }while(weight<=0);
        }


        //entering the second+ person
        printf("Enter the next person name ");
        scanf("%s", &name);

        //Checking if person to be inputted is wanted (i.e. input <> "fim")
        if(strcmp(name, "fim") !=0) {

            printf("Enter the next person weight ");
            scanf("%d", &weight);

            printf("Enter the next person height ");
            scanf("%f", &height);

            //calculatin the "imc
            imc = weight/pow(height, 2);

            //printing and counting accordingly IMC's table.
            if(imc < 19.1){

                printf("%s has IMC %f which is below ideal weight\n", name, imc);
                counterw1 += 1;

            } else if(imc >= 19.1 && imc < 25.8){
                printf("%s has IMC %f which is ideal weight \n", name, imc);
                counterw2 += 1;

            }else if(imc >= 25.8 && imc < 27.3){
                printf("%s has IMC %f which is marginally above ideal weight \n", name, imc);
                counterw3 += 1;

            }else if(imc >= 27.3 && imc < 32.3){
                printf("%s has IMC %f which is above ideal weight \n", name, imc);
                counterw4 += 1;
            }else{
                printf("%s has IMC %f which is obese \n", name, imc);
                counterw5 += 1;
            }

            //checking if the current imc inputted is the biggest
            if (imc > biggestIMC) {

                biggestIMC = imc;
                strcpy(biggestIMCName, name);
            }
                //checking if the current imc inputted is the lowest
            else if(imc < lowestIMC){

                lowestIMC = imc;
                strcpy(lowestIMCName, name);

            }

            //keeping count of the number of people inputted
            counter += 1;
            cumIMC += imc;
        } else{

            break;

        }

    }

    //printing the results after the user has ended the inputting cycle
    printf("\nThe person with the highest IMC is: %s with IMC = %f \n", biggestIMCName, biggestIMC);
    printf("The person with the lowest IMC is: %s with IMC = %f \n", lowestIMCName, lowestIMC);

    printf("The person with the average IMC is: %.2f \n", cumIMC/counter);


    printf("There are %.0f people with below ideal weight\n", counterw1);
    printf("There are %.0f people with ideal weight\n", counterw2);
    printf("There are %.0f people with marginally above ideal weight\n", counterw3);
    printf("There are %.0f people with above ideal weight\n", counterw4);
    printf("There are %.0f people with obesity\n", counterw5);


    return 0;
}

int v5(){

    float x, y, fXY, a, b, c, d;


    printf("Please choose a x lower bounder: ");
    scanf("%f", &a);

    printf("Please choose a x upper bounder: ");
    scanf("%f", &b);

    printf("Please choose a y lower bounder: ");
    scanf("%f", &c);

    printf("Please choose a y upper bounder: ");
    scanf("%f", &d);

    printf("f(x, y) for range x in [%f, %f] stepping 0.2 and y in [%f, %f] stepping 0.4 \n", a, b, c, d);

    for(x=a; x<=b; x += 0.2){

        for(y=c; y<=d; y+=0.4){

            if(x ==-3 || y == 2){

                fXY = pow(x,3) + pow(y, 2);


            }else{

                fXY = (4 * pow(x, 2) - 5*x +8)/((y+3)*(x-2));

            }
            printf("f(%.2f, %.2f) = %.2f\n", x, y, fXY);
        }



    }

    return 0;
}


#endif //EXERCICIO6A_39917_EXERCICIO6A_H
