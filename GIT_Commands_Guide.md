# Guide des Commandes Git
## Commandes Git Utiles

### Initialisation de Git

```bash
git config --global user.name "mon nom"
git config --global user.email "adresse mail"
git config --list  # Afficher le nom et l'adresse mail configurés

Versionnement Local

git init  # Initialiser le dépôt
git add .  # Ajouter toutes les modifications
git commit -m "un message"  # Créer un nouveau commit. 'git add' pousse les fichiers en zone d'index, 'git commit' les sauvegarde réellement dans un nouveau commit.

Gestion des Commits		

git log  # Liste des commits
git log -n2  # Afficher les 2 derniers commits
git show "sha"  # Lire exactement le contenu du fichier dans une étape précise
git checkout "sha"  # Remettre la version de 'sha'
git checkout master  # Remettre la version la plus récente

Versionnement sur un Dépôt Distant

git clone lien-github.com  # Récupérer le travail depuis le dépôt distant
git push -u origin master  # Pousser les modifications vers le serveur
git push -f origin master  # Pousser de force des modifications

Commiter son Projet sur GitHub

git remote set-url origin git@github.com:mesan2001/Premier-test.git  # Pointer le push local sur le bon dossier sur GitHub

