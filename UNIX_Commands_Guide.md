#Procédure de Suppression d'une Application Installée sur la Machine

##Obtenir la Liste des Applications Installées

dpkg --list  # ou
dpkg -l

##Chercher une Application en Particulier

dpkg -l | grep nom_application

##Supprimer l'Application Une Fois Trouvée

sudo apt-get remove nom_app

##Supprimer les Fichiers de Configuration

sudo apt purge nom_app

##Supprimer les Dépendances Inutiles Après Avoir Supprimé l'Application

sudo apt autoremove

##Note : Parfois, les noms des applications peuvent être difficiles à trouver. Dans ce cas, utilisez la commande find pour rechercher et ensuite supprimer les fichiers de l'application.




# Réinitialisation du Mot de Passe Utilisateur sur Ubuntu

Si vous avez oublié le mot de passe de votre compte utilisateur sur Ubuntu, vous pouvez le réinitialiser en suivant ces étapes :

**Remarque importante** : Assurez-vous de comprendre ces instructions avant de les suivre. Si vous n'êtes pas sûr, demandez de l'aide à quelqu'un qui s'y connaît.

## Étapes de Réinitialisation

1. **Redémarrez votre ordinateur** :
    - Lorsque l'ordinateur démarre, maintenez la touche `Shift` enfoncée pour accéder au menu de démarrage GRUB. Si vous ne voyez pas GRUB, essayez de maintenir la touche `Esc` au lieu de `Shift`.

2. **Accédez au mode de récupération** :
    - Dans le menu GRUB, sélectionnez l'option **"Advanced options for Ubuntu"** (Options avancées pour Ubuntu) et choisissez le noyau avec le mode de récupération. Cela peut être quelque chose comme "recovery mode" ou "rescue mode". Sélectionnez-le et appuyez sur `Enter`.

3. **Accédez à la console en tant que root** :
    - Une fois dans le mode de récupération, sélectionnez l'option **"Drop to root shell prompt"** (Passer à l'invite de commande root). Cela vous donnera un accès en tant que superutilisateur (root) avec les privilèges les plus élevés.

4. **Montez le système de fichiers en mode lecture/écriture** :
    - Montez le système de fichiers en mode lecture/écriture pour pouvoir modifier les fichiers. Utilisez la commande :
        ```bash
        mount -o remount,rw /
        ```

5. **Réinitialisez le mot de passe** :
    - Utilisez la commande suivante pour réinitialiser le mot de passe de l'utilisateur (remplacez `nom_utilisateur` par votre nom d'utilisateur) :
        ```bash
        passwd nom_utilisateur
        ```
    - Suivez les instructions pour entrer le nouveau mot de passe.

6. **Redémarrez votre ordinateur** :
    - Après avoir réinitialisé le mot de passe, redémarrez votre ordinateur avec la commande :
        ```bash
        reboot
        ```

## Remarque Finale

Assurez-vous de remplacer `nom_utilisateur` par votre nom d'utilisateur réel. Ces étapes devraient vous permettre de réinitialiser votre mot de passe utilisateur sur Ubuntu.

**Attention** : Après le changement, même après le redémarrage, le système peut demander l'ancien mot de passe une dernière fois. Cliquez simplement sur **annuler**, et le tour est joué !

**BON COURAGE !**
