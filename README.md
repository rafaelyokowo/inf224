# INF224 - Paradigmes de programmation, théorie et pratique

## Les réponses aux questions posées
Pour ce faire créer dans main.cpp un tableau dont les éléments sont tantôt une photo tantôt une vidéo. Ecrire ensuite une boucle permettant d'afficher les attributs de tous les élements du tableau ou de les "jouer". Cette boucle doit traiter tous les objets dérivant de la classe de base de la même manière.

- Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?

    Le polymorphisme.

- Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?

    Au début, j'ai pensé que si on créait un array de Media, cela marcherait. Cependant, il fallait créer un array de pointeurs pour que les differents objets (Photo, Video etc.) puissent être référencés.

- Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.

    Le tableau doit contenir des pointeurs vers les objets car ce n'est pas possible de mélanger le polymorphisme et les arrays.