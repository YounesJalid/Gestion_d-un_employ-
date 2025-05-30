#include <stdio.h>
typedef enum {
    TEMPS_PLEIN,
    TEMPS_PARTIEL,
    STAGIAIRE
}TypeEmploye;
typedef struct {
    float salaire_mensuel ;
} TempsPlein;
typedef struct {
int heures_par_semaine;
float taux_horaire;
}TempsPartiel;
typedef struct {
char etablissement[50];
int duree;
}Stagiaire;
typedef union {
    TempsPlein plein;
    TempsPartiel partiel;
    Stagiaire stagiaire;
}InfosEmploye;
typedef struct {
    char nom[30] ;
    TypeEmploye type ;
    InfosEmploye infos ;
}Employe;
void SaisirEmploye( Employe *e){
    int choix ;
    printf(" choisir le type d'emloye :\n");
    printf("1. Temps plien\n");
    printf("2. Temps partiel\n");
    printf("3. Stagiaire\n");
    printf("votre choix :");
    scanf("%d",&choix);
    e->type = choix - 1 ;
    printf("Nom :")
     scanf(" %[^\n]",e->nom);
     switch(e->type) {
         case TEMPS_PLEIN :
            printf("Salaire mensuel : ");
            scanf("%f",&e->infos.plein.salaire_mensuel);
             break ;
        case TEMPS_PARTIEL :
            printf("Heures / Semaine :");
            scanf("%d",&e->infos.partiel.heures_par_semaine);
            printf("Taux horaire :");
            scanf("%f",&e->infos.partiel.taux_horaire);
        break;
        case STAGIAIRE :
            printf("Etablissement : ");
            scanf(" %[^\n]",e->infos.stagiaire.etablissement);
            printf("Duree du stage : ");
            scanf("%d",&e->infos.stagiaire.duree);
            break;

     }
}
void AfficherEmploye(Employe e){
    printf("\n---Informations---\n");
    printf("Nom : %s\n",e.nom);
switch(e.type){
   case TEMPS_PLEIN:
            printf("Type : Temps plein\nSalaire : %.2f\n", e.infos.plein.salaire_mensuel);
            break;
        case TEMPS_PARTIEL:
            printf("Type : Temps partiel\nHeures : %d\nTaux : %.2f\n", e.infos.partiel.heures_par_semaine, e.infos.partiel.taux_horaire);
            break;
        case STAGIAIRE:
            printf("Type : Stagiaire\nÉtablissement : %s\nDurée : %d mois\n", e.infos.stagiaire.etablissement, e.infos.stagiaire.duree);
            break;
}
}
int main() {
    Employe e ;
    SaisirEmploye(&e);
    AfficherEmploye(e);
    return 0;
}
