# Documentation of my programming language
**EN** :  
This project consists of creating my own programming language in French which is my native language.  
This language will be based on the syntax of C, it will therefore be an imperative and procedural language like C.  
The language will use C at compile time, you can then use existing functions in C such as malloc or printf provided you include the appropriate headers.  
This also means that my language is low level and also handles pointers and all the advantages of C.
________________________________________________________________________________________________________________________________________________________________________________________________

**FR** :  
    Ce projet consiste à créer mon propre langage de programmation en français qui est ma langue native.  
    Ce langage sera basé sur la syntaxe du C, ce sera donc un langage impératif et procédural comme le C.  
    Le langage utilisera le C au moment de la compilation, vous pourrez ensuite utiliser les fonctions existantes en C telles que malloc ou printf à condition d'inclure les en-têtes appropriés.  
    Cela signifie également que mon langage est de bas niveau et gère également les pointeurs et tous les avantages du C.

## Types of variables | types de variables
-`nombre` : Integer. | `nombre age = 19;`  
-`car` : char. | `car letter = 'a';`  
-`flottant` : float | `flottant nb = 2.10;`
____________________________________________

-`statique` : static | `statique nombre;`
## Loop | boucle
- **While loop | boucle while** :
    ```mylang
    tant que (i != 12) {
        // instructions;
    }
- **For loop | boucle for** :
    ```mylang
    pour (i = 0, i <= 20, i++) {
        // instructions;
    }
## Terms | conditions
- **If** :
    ```mylang
    si (i < 10) {
        // instructions;
    }
- **Else if** :
    ```mylang
    sinon si (i == 10) {
        // instructions;
    }
- **Else** :
    ```mylang
    sinon {
        // instructions;
    }
## Define
- **#define** :
    ```mylang
    #definir //name //value
## Return
- **return** :
    ```mylang
    retourner(0);
## function | fonction
**EN** :  
    printf will be the only function translated into this language.  
**FR** :  
    printf sera la seul fonction traduite dans ce langage.  
- **Printf** :
    ```mylang
    afficher("Hello World !");
## Exemple
- **for my language | pour mon langage** :
    ```mylang
    nombre main(nombre argc, char **argv)
    {
        nombre i;
        car hw[13] = "Hello World !";

        i = 0;
        tant que (i <= 20)
        {
            afficher("%s for the %d's time !", hw, i):
            i++;
        }
        retourner (0);
    }
- **In C | En C** :
    ```c
    int main(int argc, char **argv)
    {
        int i;
        char hw[13] = "Hello World !";

        i = 0;
        while (i <= 20)
        {
            printf("%s for the %d's time !", hw, i):
            i++;
        }
        return (0);
    }