# Repository de Conseils et Astuces

Bienvenue dans ce repository dédié aux conseils et astuces pour optimiser l'utilisation de divers outils informatiques, principalement Git et Ubuntu. Ce repository a été conçu pour servir de référence et de guide pratique pour les développeurs, administrateurs système, et toute personne souhaitant améliorer son efficacité et résoudre des problèmes techniques courants.

## Contenu du Repository

Ce repository est organisé en plusieurs sections, chacune contenant des guides et des notes spécifiques. Voici un aperçu de ce que vous trouverez :

### 1. Commandes Git

Dans cette section, vous trouverez des commandes Git essentielles pour la gestion des versions, le déploiement de projets, et la gestion des commits. Les fichiers incluent des explications détaillées et des exemples pratiques pour vous aider à utiliser Git de manière efficace.

#### Commandes Utiles

- **Initialisation de Git**
  - `git config --global user.name "mon nom"`
  - `git config --global user.email "adresse mail"`
  - `git config --list`

- **Versionner en Local**
  - `git init`
  - `git add .`
  - `git commit -m "un message"`

- **Gérer les Commits**
  - `git log`
  - `git log -n2`
  - `git show "sha"`
  - `git checkout "sha"`
  - `git checkout master`

- **Versionner sur un Dépôt Distant**
  - `git clone lien-github.com`
  - `git push -u origin master`
  - `git push -f origin master`

- **Configurer un Remote**
  - `git remote set-url origin git@github.com:mesan2001/Premier-test.git`

### 2. Gestion des Applications sur Ubuntu

Cette section contient des instructions détaillées pour installer, supprimer, et gérer les applications sur Ubuntu. Vous y trouverez des commandes utiles pour la gestion des paquets et des applications installées sur votre système.

#### Suppression d'Applications

- **Lister les Applications Installées**
  - `dpkg --list`
  - `dpkg -l`

- **Rechercher une Application**
  - `dpkg -l | grep nom_application`

- **Supprimer une Application**
  - `sudo apt-get remove nom_app`
  - `sudo apt purge nom_app`
  - `sudo apt autoremove`

### 3. Réinitialisation du Mot de Passe sur Ubuntu

Si vous avez oublié le mot de passe de votre compte utilisateur sur Ubuntu, cette section vous guide à travers le processus de réinitialisation du mot de passe.

#### Étapes pour Réinitialiser le Mot de Passe

1. **Redémarrez votre ordinateur et accédez au menu GRUB**
   - Maintenez la touche Shift enfoncée pendant le démarrage pour accéder au menu GRUB.

2. **Accédez au Mode de Récupération**
   - Sélectionnez "Advanced options for Ubuntu" et choisissez le mode de récupération.

3. **Accédez à la Console en tant que Root**
   - Sélectionnez "Drop to root shell prompt" pour obtenir un accès root.

4. **Montez le Système de Fichiers en Mode Lecture/Écriture**
   - Utilisez la commande `mount -o remount,rw /`.

5. **Réinitialisez le Mot de Passe**
   - Utilisez `passwd nom_utilisateur` pour réinitialiser le mot de passe.

6. **Redémarrez votre Ordinateur**
   - Utilisez `reboot` pour redémarrer.

Attention : Après le redémarrage, le système peut demander l'ancien mot de passe une dernière fois. Cliquez sur "Annuler" pour passer cette étape.

## Comment Contribuer

Si vous souhaitez contribuer à ce repository, n'hésitez pas à ouvrir des issues ou à soumettre des pull requests. Toute contribution est la bienvenue, qu'il s'agisse de corrections, de nouvelles astuces, ou d'améliorations des guides existants.

## Licence

Ce repository est sous licence [MIT](LICENSE). Vous êtes libre de l'utiliser, le modifier et le distribuer, tant que vous respectez les termes de la licence.

## Contact

Pour toute question ou suggestion, vous pouvez me contacter via [mon adresse email](mailto:jsphanani@gmail.com).

Merci d'utiliser ce repository et bon courage dans vos projets !
