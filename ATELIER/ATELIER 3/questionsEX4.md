1. Différence entre copie superficielle et copie profonde :

Copie superficielle : Le pointeur est simplement copié. Les deux objets partagent donc la même ressource (par exemple, un objet Client). Cela peut provoquer des problèmes comme la double suppression ou des pointeurs invalides.

Copie profonde : Une nouvelle ressource est allouée et copiée. Chaque objet possède sa propre copie, garantissant une indépendance totale entre eux.

2. Pourquoi le compteur du nombre de comptes doit-il être statique ?
Le compteur doit être statique car il reflète une propriété globale de la classe, c’est-à-dire le nombre total d’instances créées, et non une information propre à chaque objet.

3. Différence entre méthode statique et méthode normale :

Méthode normale (d’instance) :

Nécessite un objet pour être appelée.

Reçoit automatiquement le pointeur this.

Peut accéder aux membres de l’instance.

Méthode statique (de classe) :

Appartient à la classe, pas à un objet spécifique.

Ne reçoit pas this.

Peut être appelée sans créer d’objet et n’accède qu’aux membres statiques.

4. Quand rendre une fonction inline ?

Utile pour les fonctions petites et simples qui sont appelées fréquemment.

Le compilateur peut remplacer l’appel par le corps de la fonction, réduisant la surcharge d’exécution et améliorant les performances.

5. Que se passe-t-il si on oublie de libérer la mémoire dans le destructeur ?

Si la mémoire allouée dynamiquement (par exemple Client* dans la classe Account) n’est pas libérée, cela provoque une fuite mémoire (memory leak).

La mémoire reste occupée mais inaccessible, ce qui peut entraîner l’épuisement des ressources du programme.
