#include <iostream>
#include <fstream>

using element = std::string ;

struct occmot 
{
	element mot ; 
	int nboccurence ; 
} ;

struct maillon{
	occmot valeur ; 
	maillon * suiv ; 
} ; 

using listeMot = maillon * ; 

//question 1 : 

void initialiser (listeMot & L)
{
	L = nullptr; 
}

// question 2 : 

void ajoutDebut ( element mot , listeMot & L )
{
	maillon * aux = new maillon ; 
	aux -> valeur.mot = mot ; 
	aux -> valeur.nboccurence = 1 ; 
	aux -> suiv = L ; 
	L = aux ; 
}

// question 3 : ajout recursif  

void ajoute (element mot , listeMot & L)
{
	if ( ( L == nullptr ) or ( mot < L -> valeur.mot ) ) 
	{
		ajoutDebut (mot,L) ;
	}
	else if ( mot == L -> valeur.mot )
	{
		L -> valeur.nboccurence ++ ; 
	}
	else {
		ajoute ( mot , L -> suiv ) ; 
	}
}

// question 3 : version iteratif : 

void ajoutev2 ( element mot , listeMot & L)
{
	if ( ( L == nullptr ) or ( mot < L -> valeur.mot ) ) 
	{
		ajoutDebut (mot,L) ;
	}
	else
	{	maillon * aux = new maillon ; 
		aux -> valeur.mot = mot ; 
		aux -> valeur.nboccurence = 1 ; 
	
		maillon * tmp = L ; 
		while ( tmp -> suiv != nullptr )
		{
			if ( mot == tmp -> suiv -> valeur.mot)
			{
				tmp -> suiv ->  valeur.nboccurence ++ ; 
				return ; 
			}
			else if ( mot < tmp -> suiv -> valeur.mot)
			{
				
				aux -> suiv = tmp -> suiv  ; 
				tmp -> suiv = aux ; 
				return ; 
			}
			tmp = tmp -> suiv ; 
		}
		aux -> suiv = nullptr ; 
		tmp -> suiv = aux ; 	
	}
}


// question 4 : version recursive : 

void afficher ( listeMot L )
{
	if ( L != nullptr)
	{
		std::cout << L -> valeur.mot << " ( " << L -> valeur.nboccurence << " ) " << std::endl ; 
		afficher ( L -> suiv )  ; 
	}
} 

//question 4 : version iterative : 

void afficherv2 ( listeMot L)
{
	while ( L != nullptr )
	{
		std::cout << L -> valeur.mot << " ( " << L -> valeur.nboccurence << " ) " << std::endl ; 
		L = L -> suiv ; 
	}
}

// question 5 : la taille : version recursive :  
 
int taille ( listeMot L )
{
	if ( L == nullptr)
	{
		return 0 ; 
	} 
	else
	{
		return 1 + taille ( L -> suiv ) ; 
	}
}
 
// question 5 : la taille : version recursive :  

int taillev2 (listeMot L )
{
	int compt = 0 ; 
	while ( L != nullptr)
	{
		compt++ ; 
		L = L -> suiv  ; 
	}
	return compt ; 
} 

// question 6 :  nombre total de mot : recursif : 

int  nombreMot (listeMot L)
{
	if ( L == nullptr)
	{
		return 0 ; 
	} 
	else
	{
		return L -> valeur.nboccurence + nombreMot ( L -> suiv ) ; 
	}
}

// question 6 :  nombre total de mot : iteratif  : 

int nombreMotv2 (listeMot L )
{
	int compt = 0 ; 
	while ( L != nullptr)
	{
		compt = compt + L -> valeur.nboccurence ; 
		L = L -> suiv  ; 
	}
	return compt ; 
	
}

// question 7 : validité d'une liste de mot : recursif

bool estvalide ( listeMot L )
{
	if ( L == nullptr )
	{
		return true ; 
	}
	else if ( L -> suiv == nullptr )
	{
		return L -> valeur.nboccurence > 0  ; 
	}
	else if ( ( L -> valeur.mot >= L -> suiv -> valeur.mot) or ( L -> valeur.nboccurence < 1) )
	{
		return false ; 
	}
	else
	{
		return estvalide ( L -> suiv ) ; 
	}	
}

// question 7 : validité d'une liste de mot : iteratif

bool estvalidev2 ( listeMot L )
{
	if ( L == nullptr )
	{
		return true ; 
	}
	else if ( L -> suiv == nullptr )
	{
		return L -> valeur.nboccurence > 0  ; 
	}
	else
	{
		maillon* tmp = L ; 
		while ( tmp -> suiv != nullptr )
		{
		 	if ( ( tmp -> valeur.mot >= tmp -> suiv -> valeur.mot) or ( tmp -> valeur.nboccurence < 1) )	
		 		return false ; 
		 	tmp = tmp -> suiv ; 
		}
		return true ; 
	}
}

// question 8 : le mot le plus long de la liste : recursif : 

int max ( int a , int b)
{
	if ( a >= b)
		return a  ;
	else 
		return b ; 
}

unsigned  int plusLong (listeMot L )
{
	if ( L == nullptr  )
		return 0 ; 
	else
		return max ( L -> valeur.mot.length() , plusLong(L->suiv) ) ; 
}

// question 8 : le mot le plus long de la liste : iteratif : 

unsigned  int plusLongv2 (listeMot L )
{
	if ( L == nullptr  )
		return 0 ; 
	else
	{
		int max = L -> valeur.mot.length() ; 
		maillon* tmp = L ; 
		while ( tmp -> suiv != nullptr )
		{
			if ( max < tmp -> suiv -> valeur.mot.length() )
				max = tmp -> suiv -> valeur.mot.length() ; 
			tmp = tmp -> suiv ; 
		}	
		
		return max ; 
	}	
}

// question 9  : afficher les mots de la liste qui ont une longueur donnée : recursif

void afficherLongueur ( listeMot L  , int longueur )
{
	if ( L != nullptr )
	{
		if ( L -> valeur.mot.length() == longueur )
			std::cout << L -> valeur.mot  << std::endl ; 
		afficherLongueur ( L -> suiv , longueur ) ; 
	}
} 


// question 9  : afficher les mots de la liste qui ont une longueur donnée : iteratif : 

void afficherLongueurv2 ( listeMot L  , int longueur )
{
	while ( L != nullptr )
	{
		if ( L -> valeur.mot.length() == longueur )
			std::cout << L -> valeur.mot  << std::endl ;
		L = L -> suiv ; 
	}
}


// question 10 : afficher les mot du plus court au plus long : recursif




// question 10 : afficher les mot du plus court au plus long : iteratif 

void afficherTrieLongueurv2 ( listeMot L)
{
	for ( int i = 1 ; i <= plusLong (L) ; i++)
	{
		 afficherLongueur (  L  ,  i ) ; 
	}
}


// question 10 : inutile 


//question 11 : construit une liste à partir  d'un fichier texte : 

void construit ( listeMot & L , element fichier )
{
	std::ifstream fic(fichier) ;
	if ( fic )
	{
		while ( ! fic.eof() )
		{
			element mot ; 
			fic >> mot ; 
			ajoute ( mot , L ) ; 
		}	
	}
	else
	{
		std::cout << " erreur d'ouverture du fichier " << std::endl ;  
	}
}


// question 11 : rempplir un tableau de mot à partir d'une liste de mot : 

struct tabMot{
	element * t ; 
	int taillemax ; 
} ; 

void remplit ( tabMot & T , listeMot L)
{
	T.t = new element [taille(L)] ; 
	T.taillemax = taille(L) ; 
	int i = 0 ; 
	while( L!= nullptr)
	{
		T.t[i] = L -> valeur.mot ; 
		L = L -> suiv ; 
		i++ ; 
	}
}

// question 18 : 

void afficher (tabMot t )
{
	 for ( int i = 0 ; i < t .taillemax ; i++)
	  {
	  	std::cout << t.t[i] << std::endl ; 
	   }
}


bool recherche (element v, element * t, int d, int f)
// renvoie vrai ssi v apparait dans t entre les indices d et f
// on suppose les valeurs de t triées par ordre croissant
{
	if (d > f)
	return false;
	else {
	int m = (d + f) / 2;
	if (t[m] == v)
	return true;
	else if (t[m] > v)
	return recherche(v,t,d,m-1);
	else return recherche(v,t,m+1,f);
	}
}


bool appartient ( element mot , tabMot t )
{
	return recherche(mot,t.t,0,t.taillemax) ; 
}

// question 17  : edclaration des types ;: 


struct occLettre{
	char lettre ; 
	int nboccurence ; 
} ; 

struct tabLettre{
	occLettre * t  ;
	// int taillemax : cette declaration n'est pas importante , puisque de toute facon,je sais que je vais utiliser 26 cases 
} ; 

/// question 18 : 

void initialiser ( tabLettre &t )
{
	t.t = new occLettre [ 26 ] ; 
	char s = 'a' ; 
	for ( int i = 0 ; i < 26 ; i++)
	{
		t.t[i].lettre = s ; 
		t.t[i].nboccurence = 0 ;  
		s ++ ; 
	}
}


// question 19 : ajouter un lettre dans un tableau de lettre : 

void ajoute ( char c , tabLettre & t)
{
	int i = 0 ; 
	while ( t.t[i].lettre != c)
	{
		i++ ; 
	}
	t.t[i].nboccurence ++ ; 
}

// question 20 : rempli un table de lettre en fonction des elements qui sont dans la liste de mot : 

void  comptabiliser ( tabLettre & t , listeMot  L)
{
	while ( L != nullptr )
	{
		for ( int j = 0 ; j < L -> valeur.mot.length() ; j++ )
		{
			for ( int i = 0 ; i < L -> valeur.mot.length() ; i++ )
			{
				ajoute (L -> valeur.mot[i] , t ) ; 
			}
		}
		
		L = L -> suiv ; 
	}
}

//  question 21 : trie le tableau par ordre décroissant du nombre d'occurence des lettres : 






void trie (tabLettre & t ) // trie par selection : 
{
	int taille = 26 ; 
	int max = t.t[0].nboccurence ; 
	int indice = 0 ; 
	char aux1 ; 
	int aux2 ; 
	
	while ( taille > 0)
	{
		for ( int i = 1 ; i < taille ; i ++)
		{
			if ( t.t[i].nboccurence > max  )
			{
				max =  t.t[i].nboccurence ; 
				indice = i ; 
			}
		}
		
		aux1  = t.t[indice].lettre ; 
		aux2 = t.t[indice].nboccurence ; 
		
		t.t[indice].lettre = t.t[taille-1].lettre ;
		t.t[indice].nboccurence = t.t[taille-1].nboccurence ; 
		
		t.t[taille-1].lettre = aux1 ; 
		t.t[taille-1].nboccurence = aux2  ; 
		
		max = t.t[0].nboccurence ;
		indice = 0 ; 
		taille -- ; 
	}
}







//question 22 : 

void afficher (tabLettre & t)
{
	for ( int i = 0 ; i <  26 ; i ++)
	{
		std::cout << t.t[i].lettre << " ( " << t.t[i].nboccurence << " ) " << std::endl ; 
	}
}


int main ()
{
	listeMot L ; 
	initialiser (L) ; 
	
	 construit (L,"bouledesuif.txt") ; 
	 std::cout << std::endl ; 
	 //afficher (L) ; 
	 construit (L,"bouledesuif.txt") ; 
	 tabMot tm ; 
	 remplit (tm , L) ;
	  
	tabLettre tl ; 
	initialiser (tl) ; 
	
	comptabiliser ( tl , L) ;
	afficher(tl) ; 
	std::cout << std::endl ; 
	trie ( tl ) ; 
	afficher(tl) ; 
	 
	 
	 
	  return 0 ; 
}
