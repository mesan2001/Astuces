#include <iostream>

/*

	git remote set-url origin git@github.com:mesan2001/Premier-test.git
	
	
	queslques commande utile : 
	
	
	// initialisatin de git //
	
	git config --global user.name  "mon nom"
	git config --global user.email "adresse mail"
	git config --list                          : afficher mon nom et mon adresse mail
	
	
	// versionner en local //
	git init                                   : initialise le depot
	git add .                                  : ajouter toutes les modifications 
	git commit -m "un message"                 : creer un nouveau commit git add pousse les fichiers en zone d'index ,git commit les sauvegarde réellement dans un nouveau commit

	// Gerer les commits //
	
	git log                                    : liste des commits
	git log -n2                                : affihcer les 2 derniers commits
	git show "sha"			   	   : pour lire exactement le contenu du fichier dans une etape precise
	git checkout "sha"                         : remettre la version de sha
	git checkout master                        : remettre la version la plus recente 
	
	// versionner sur un depot distant
	
	git clone lien-github.com                  : recuperer le travail depuis le depot distant
	git push -u origin master		   : pousse les modifications vers serveur
	git push -f origin master                  : pousse de force des modifications 
	
	// commit son projet sur github //
	
	
*/


int main ()
{
	
	return 0 ; 
}
