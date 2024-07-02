#!/bin/bash

# Fonction pour ajouter un nouvel utilisateur
add_user() {
    local username=$1
    sudo useradd -m $username
    if [ $? -eq 0 ]; then
        echo "Utilisateur $username ajouté avec succès."
    else
        echo "Erreur lors de l'ajout de l'utilisateur $username."
    fi
}

# Fonction pour supprimer un utilisateur
delete_user() {
    local username=$1
    sudo userdel -r $username
    if [ $? -eq 0 ]; then
        echo "Utilisateur $username supprimé avec succès."
    else
        echo "Erreur lors de la suppression de l'utilisateur $username."
    fi
}

# Fonction pour lister tous les utilisateurs
list_users() {
    echo "Liste des utilisateurs :"
    cut -d: -f1 /etc/passwd
}

# Fonction pour surveiller l'utilisation du disque
check_disk_usage() {
    echo "Utilisation du disque :"
    df -h
}

# Fonction pour surveiller l'utilisation de la mémoire
check_memory_usage() {
    echo "Utilisation de la mémoire :"
    free -h
}

# Fonction pour surveiller l'utilisation du processeur
check_cpu_usage() {
    echo "Utilisation du processeur :"
    top -b -n1 | grep "Cpu(s)"
}

# Fonction pour mettre à jour le système
update_system() {
    echo "Mise à jour du système..."
    sudo apt update && sudo apt upgrade -y
    if [ $? -eq 0 ]; then
        echo "Système mis à jour avec succès."
    else
        echo "Erreur lors de la mise à jour du système."
    fi
}

# Menu pour l'utilisateur
show_menu() {
    echo "Choisissez une option :"
    echo "1) Ajouter un utilisateur"
    echo "2) Supprimer un utilisateur"
    echo "3) Lister les utilisateurs"
    echo "4) Surveiller l'utilisation du disque"
    echo "5) Surveiller l'utilisation de la mémoire"
    echo "6) Surveiller l'utilisation du processeur"
    echo "7) Mettre à jour le système"
    echo "8) Quitter"
    read -p "Option : " option
    case $option in
        1)
            read -p "Entrez le nom d'utilisateur à ajouter : " username
            add_user $username
            ;;
        2)
            read -p "Entrez le nom d'utilisateur à supprimer : " username
            delete_user $username
            ;;
        3)
            list_users
            ;;
        4)
            check_disk_usage
            ;;
        5)
            check_memory_usage
            ;;
        6)
            check_cpu_usage
            ;;
        7)
            update_system
            ;;
        8)
            exit 0
            ;;
        *)
            echo "Option invalide."
            ;;
    esac
}

# Boucle pour afficher le menu jusqu'à ce que l'utilisateur choisisse de quitter
while true; do
    show_menu
done
