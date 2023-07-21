/*

    CURSO KERNIGHAN Y RITCHIE
    
    uso de los arreglos para el conteo de diferentes caracteristicas
    
    
    
    capitulo2,arreglos, if-else if-else, condiciones
    herramientas:arreglos
    */


#include <stdio.h>
//cuenta digitos, espacios, espacios en blanco y otros



main(){
    int c,i,nwhite,nother;
    int ndigit[10];

    nwhite=nother=0;
    for (i = 0; i < 10; i++)
        ndigit[i]=0;


    while((c=getchar())!=EOF){
        if(c>='0'&&c<='9'){
            ++ndigit[c-'0'];
        }
        
        else if(c== ' '||c=='\n'||c=='t')
            ++nwhite;
        else
            ++nother;
    }
  
                   
//impresion por pantall 
    printf("digitos =");
    for (i = 0; i < 10; i++)
        printf("%d",ndigit[i]);
    printf(", espacios blancos = %d, otros =%d\n",nwhite,nother);

    
}