#include<stdio.h>
void matriceadjacentdynamique(int**A,int**B,int**I,int**U,int**V,int**C,int**P) {
    int i,j,n,c,k,l,f;
    printf("entrez le nombre de sommet :");
    scanf("%d",&n);
    A=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++) {
        *(A+i)=(int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            do {
                printf("arc:[%d]->[%d]=",i,j);
                scanf("%d",(*(A+i)+j));
            } while(*(*(A+i)+j)!=0 && *(*(A+i)+j)!=1);
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(*(*(A+i)+j)==1) {
                printf("ajout d'arc [%d]->[%d]=",i,j);
                scanf("%d",(*(A+i)+j));
            }
        }
    }
    printf("\n le graphe A est:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t",*(*(A+i)+j));
        }
        printf("\n");
    }
    printf("entrez le nombre de sommet :");
    scanf("%d",&n);
    B=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++) {
        *(B+i)=(int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            do {
                printf("arc:[%d]->[%d]=",i,j);
                scanf("%d",(*(B+i)+j));
            } while(*(*(B+i)+j)!=0 && *(*(B+i)+j)!=1);
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(*(*(B+i)+j)==1) {
                printf("ajout d'arc [%d]->[%d]=",i,j);
                scanf("%d",(*(B+i)+j));
            }
        }
    }
    printf("\n le graphe B est:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t",*(*(B+i)+j));
        }
        printf("\n");
    }
    I=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++) {
        *(I+i)=(int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(*(*(A+i)+j)==1 && *(*(B+i)+j)==1) {
                *(*(I+i)+j)=1;
            }
            else {
                *(*(I+i)+j)=0;
            }
        }
    }
    printf("\n l'intersection est:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t",*(*(I+i)+j));
        }
        printf("\n");
    }
    U=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++) {
        *(U+i)=(int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(*(*(A+i)+j)==1 || *(*(B+i)+j)==1) {
                *(*(U+i)+j)=1;
            }
            else {
                *(*(U+i)+j)=0;
            }
        }
    }
    printf("\n l'union est:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t",*(*(U+i)+j));
        }
        printf("\n");
    }
    V=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++) {
        *(V+i)=(int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            *(*(V+i)+j)=*(*(B+j)+i);
        }
    }
    printf("\n l'inverse est:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t",*(*(V+i)+j));
        }
        printf("\n");
    }
    C=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++) {
        *(C+i)=(int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(*(*(B+i)+j)==1) {
                *(*(C+i)+j)=0;
            }
            else {
                *(*(C+i)+j)=1;
            }
        }
    }
    printf("\n le complément  est:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t",*(*(C+i)+j));
        }
        printf("\n");
    }
    P=(int**)malloc(n*sizeof(int*));
    for(i=0; i<n; i++) {
        *(P+i)=(int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            for(k=0; k<n; k++) {
                *(*(P+i)+j)=*(*(P+i)+j)+*(*(A+i)+k)**(*(B+k)+j);
            }
        }
    }
    printf("\n le produit  est:\n");
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%d\t",*(*(P+i)+j));
        }
        printf("\n");
    }
    // Totalité
    for(i=0; i<n; i++) {
        l=0;
        for(j=0; j<n; j++) {
            l=l+*(*(B+i)+j);
        }
        if(l<1) {
            break;
        }
    }
    if(l<1) {
        printf("Totalité :Non\n");
    }
    else {
        printf("Totalité :Oui\n");
    }
    //determinisme
    for(i=0; i<n; i++) {
        l=0;
        for(j=0; j<n; j++) {
            l=l+*(*(B+i)+j);
        }
        if(l>1) {
            break;
        }
    }
    if(l>1) {
        printf("determinisme :Non\n");
    }
    else {
        printf("determinisme:Oui\n");
    }
    // application
    for(i=0; i<n; i++) {
        l=0;
        for(j=0; j<n; j++) {
            l=l+*(*(B+i)+j);
        }
        if(l!=1) {
            break;
        }
    }
    if(l==1) {
        printf("application :Oui\n");
    }
    else {
        printf("application :Non\n");
    }
    //surjection
    for(i=0; i<n; i++) {
        f=0;
        for(j=0; j<n; j++) {
            f=f+*(*(B+j)+i);
        }
        if(f<1) {
            break;
        }
    }
    if(f<1) {
        printf("surjection:Non\n");
    }
    else {
        printf("surjection:Oui\n");
    }
    // injectivité
    for(i=0; i<n; i++) {
        f=0;
        for(j=0; j<n; j++) {
            f=f+*(*(B+j)+i);
        }
        if(f>1) {
            break;
        }
    }
    if(f>1) {
        printf("injectivité :Non\n");
    }
    else {
        printf("injectivité :Oui\n");
    }
    // application bijection
    for(i=0; i<n; i++) {
        l=0;
        for(j=0; j<n; j++) {
            l=l+*(*(B+i)+j);
        }
        if(l!=1) {
            break;
        }
    }
    for(i=0; i<n; i++) {
        f=0;
        for(j=0; j<n; j++) {
            f=f+*(*(B+j)+i);
        }
        if(f!=1) {
            break;
        }
    }
    if(l!=1 && f!=1) {
        printf("application bijection  :Non\n");
    }
    else {
        printf("application bijection  :Oui\n");
    }
    // liberatd'espace
    for(i=0; i<n; i++) {
        if(n>0) {
            free(*(B+i));
        }
    }
    if(n>0) {
        free(*(B+i));
    }
}
int main()
{
    int**A,**B,**I,**U,**V,**C,**P;
    matriceadjacentdynamique(A,B,I,U,V,C,P);
    return 0;
}