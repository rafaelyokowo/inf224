# INF224 - Paradigmes de programmation, théorie et pratique

## Introduction

Le but de ces travaux pratiques est de créer l'ébauche du logiciel d'une set-top box multimédia permettant de jouer de la musique, des vidéos, des films, d'afficher des photos, etc. Ce logiciel sera realisé par étapes, en se limitant à la déclaration et l'implémentation de quelques classes et fonctionnalités typiques que l'on complétera progressivement. Noter qu'il est utile de lire le texte de chaque étape en entier avant de la traiter (en particulier les notes ou remarques qui donnent des indications).


## Les réponses aux questions posées

### 5eme étape
Pour ce faire créer dans main.cpp un tableau dont les éléments sont tantôt une photo tantôt une vidéo. Ecrire ensuite une boucle permettant d'afficher les attributs de tous les élements du tableau ou de les "jouer". Cette boucle doit traiter tous les objets dérivant de la classe de base de la même manière.

- Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ?

    Le polymorphisme.

- Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ?

    Au début, j'ai pensé que si on créait un array de Media, cela marcherait. Cependant, il fallait créer un array de pointeurs pour que les differents objets (Photo, Video etc.) puissent être référencés.

- Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.

    Le tableau doit contenir des pointeurs vers les objets car ce n'est pas possible de mélanger le polymorphisme et les arrays.

### 8eme étape

- Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java.

### 10eme étape

- Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ?