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
