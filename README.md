<img src="utils/1.png" width= 100%>

---

## Exercice 00 - "Mommy, when I grow up, I want to be a bureaucrat!"

#### Objectif :
L'objectif de cet exercice est de concevoir une classe `Bureaucrat` qui incarne le concept de bureaucratie avec des règles strictes concernant le grade des bureaucrates. Les bureaucrates ont un grade numérique qui détermine leur rang dans la hiérarchie bureaucratique, avec 1 étant le grade le plus élevé et 150 le plus bas.

#### Contraintes :
- **Nom Constant** : Chaque bureaucrate possède un nom qui ne change pas.
- **Grade** : Le grade est compris entre 1 et 150. Toute tentative de création d'un bureaucrate avec un grade en dehors de cette plage doit lever une exception.
- **Gestion des Exceptions** : Deux types d'exceptions doivent être gérés - `GradeTooHighException` et `GradeTooLowException`, pour les cas où le grade est respectivement trop haut ou trop bas.
- **Manipulation des Grades** : Il doit être possible d'incrémenter ou de décrémenter le grade d'un bureaucrate, avec gestion des exceptions si les modifications proposées font sortir le grade de la plage valide.
- **Affichage** : Implémenter une surcharge de l'opérateur d'insertion (<<) pour afficher les détails d'un bureaucrate sous la forme : `<nom>, bureaucrate grade <grade>`.

### Mon Implémentation :

[Lien ici](https://github.com/aceyzz/CPP05/tree/main/ex00)

#### Classe Bureaucrat :
- **Attributs** : 
  - `const std::string _name` : Le nom du bureaucrate, constant et initialisé lors de la création.
  - `int _grade` : Le grade du bureaucrate, doit être entre 1 et 150.

- **Constructeurs et Destructeur** : 
  - Un constructeur par défaut, un constructeur paramétrique pour initialiser le bureaucrate avec un nom et un grade spécifiques, et un destructeur.
  - Le constructeur paramétrique vérifie la validité du grade et lance des exceptions si nécessaire.

- **Exceptions** : 
  - `GradeTooHighException` et `GradeTooLowException` sont définies comme des classes internes, héritant de `std::exception`, et implémentant la méthode `what()` pour fournir un message d'erreur.

- **Fonctionnalités** :
  - `incrementGrade()` et `decrementGrade()` pour modifier le grade du bureaucrate, avec gestion des exceptions si le grade résultant est invalide.
  - `getName()` et `getGrade()` comme accesseurs pour obtenir le nom et le grade du bureaucrate.

- **Surcharge de l'Opérateur <<** :
  - Permet d'afficher les informations du bureaucrate en utilisant `std::cout`.

#### Gestion des Exceptions :
Des blocs `try` et `catch` sont utilisés pour capturer et gérer les exceptions lors de la manipulation des grades des bureaucrates. Cela inclut les tentatives d'augmentation ou de diminution du grade au-delà des limites autorisées.

#### Test :
Des instances de `Bureaucrat` sont créées avec différents grades pour démontrer la gestion des exceptions et l'affichage des informations du bureaucrate. Les tests mettent en évidence la robustesse de la classe face aux opérations invalides.

<br>

---

<br>

## Exercice 01 - "Form up, maggots!"

#### Objectif :
Après l'introduction des bureaucrates, cet exercice propose de leur attribuer des tâches à travers la gestion de formulaires à remplir. La classe `Form` représente ces formulaires et contient les éléments suivants :
- **Nom Constant** : Un nom immuable pour le formulaire.
- **Statut de Signature** : Un booléen indiquant si le formulaire est signé ou non (non signé par défaut).
- **Grade Requis pour Signature** : Un grade spécifique requis pour pouvoir signer le formulaire.
- **Grade Requis pour Exécution** : Un grade spécifique requis pour pouvoir exécuter le formulaire.

#### Contraintes :
- Les grades des formulaires suivent les mêmes règles que ceux des bureaucrates, avec gestion des exceptions `Form::GradeTooHighException` et `Form::GradeTooLowException` si un grade est hors limites.
- La classe `Form` doit fournir des accesseurs pour tous ses attributs et une surcharge de l'opérateur d'insertion (<<) pour afficher les informations du formulaire.
- La fonction membre `beSigned(Bureaucrat)` permet de changer le statut du formulaire en "signé" si le grade du bureaucrate est suffisant.

#### Classe Bureaucrat :
- Modification pour inclure la fonction membre `signForm(Form&)` qui tente de signer un formulaire. Si le formulaire est signé avec succès, un message de confirmation est affiché ; sinon, une raison est donnée pour l'échec.

### Mon Implémentation :

[Lien ici](https://github.com/aceyzz/CPP05/tree/main/ex01)

#### Classe Form :
- **Constructeurs et Destructeur** : 
  - Un constructeur par défaut, un constructeur paramétrique pour initialiser le formulaire avec des grades spécifiques pour la signature et l'exécution, et un destructeur.
- **Exceptions** : 
  - Des exceptions personnalisées `GradeTooHighException` et `GradeTooLowException` pour gérer les grades invalides lors de la création des formulaires.
- **Fonctionnalités** :
  - `beSigned(const Bureaucrat&)` pour tenter de signer le formulaire avec un bureaucrate donné, avec gestion des exceptions si le grade du bureaucrate est insuffisant.

#### Modifications de la Classe Bureaucrat :
- Ajout de la fonction `signForm(Form&)` qui permet au bureaucrate de signer un formulaire, affichant un message selon que la signature est réussie ou non.

#### Test :
Des scénarios de test sont implémentés pour démontrer la création de formulaires, la gestion des exceptions liées aux grades, et l'interaction entre bureaucrates et formulaires pour la signature. Ces tests mettent en lumière le fonctionnement intégré des classes `Bureaucrat` et `Form` dans le contexte de la gestion des documents administratifs.

<br>

---

<br>

## Exercice 02 - "No, you need form 28B, not 28C..."

#### Objectif :
L'objectif est d'introduire des formulaires concrets qui effectuent des actions spécifiques, en transformant la classe de base `Form` en une classe abstraite renommée `AForm`. Cette transformation implique que tous les attributs restent privés dans la classe de base.

#### Formulaires Concrets :
- **ShrubberyCreationForm** : Crée un fichier `<target>_shrubbery` et y écrit des arbres en ASCII. Grades requis : signature 145, exécution 137.
- **RobotomyRequestForm** : Produit des bruits de perçage et annonce la robotomisation réussie de `<target>` 50% du temps. Sinon, informe de l'échec. Grades requis : signature 72, exécution 45.
- **PresidentialPardonForm** : Annonce que `<target>` a été gracié par Zaphod Beeblebrox. Grades requis : signature 25, exécution 5.

Chaque formulaire prend en paramètre de son constructeur la cible du formulaire (par exemple, "home" pour planter un arbuste à domicile).

#### Exécution des Formulaires :
- Une fonction membre `execute(Bureaucrat const &executor) const` est ajoutée à la classe de base pour exécuter l'action spécifique du formulaire. Cette fonction vérifie si le formulaire est signé et si le grade du bureaucrate tentant d'exécuter le formulaire est suffisamment élevé, sinon elle lance une exception appropriée.

#### Classe Bureaucrat :
- Ajout de la fonction membre `executeForm(AForm const &form)` qui tente d'exécuter le formulaire. Si l'exécution est réussie, elle affiche un message de confirmation; sinon, elle affiche un message d'erreur explicite.

### Mon Implémentation :

[Lien ici](https://github.com/aceyzz/CPP05/tree/main/ex02)

#### Modifications et Ajouts :
- **Classe AForm** : Renommage de `Form` en `AForm` pour indiquer son caractère abstrait, avec l'ajout de la fonction virtuelle pure `execute` pour exécuter l'action du formulaire.
- **Classes de Formulaires Spécifiques** : Implémentation des classes `ShrubberyCreationForm`, `RobotomyRequestForm`, et `PresidentialPardonForm` avec leurs comportements d'exécution uniques.
- **Gestion des Exceptions** : Ajout de gestion des exceptions pour garantir que les formulaires ne soient exécutés que si les conditions requises sont remplies (formulaire signé, grade suffisant).

#### Tests :
Des scénarios de test démontrent la création et l'exécution de chaque type de formulaire, illustrant la flexibilité et l'extensibilité du système de formulaires grâce à l'héritage et au polymorphisme. Ces tests mettent en évidence les interactions entre les bureaucrates et les divers formulaires, soulignant la complexité et la robustesse de la gestion des formulaires dans le cadre bureaucratique.
